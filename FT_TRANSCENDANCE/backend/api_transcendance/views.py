from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt
from django.utils.decorators import method_decorator
from .serializers import Register, Login, Verification, User_Detail, Update_Profile, Update_Password
from .models import User, Friendship, Invitation, Game, Tournaments_Invitations, Name_Tournaments_Game
from rest_framework import status
from rest_framework.response import Response
from datetime import timedelta
from django.utils import timezone
from django.contrib.auth import authenticate, login as django_login, logout as django_logout
from django.core.mail import send_mail
from rest_framework import status
from rest_framework.decorators import api_view, permission_classes
from rest_framework.response import Response
from rest_framework.views import APIView
from .utils import generate_random_digits, make_invitation_obsolete, get_winner_player_one, get_winner_player_two, make_invitation_tournaments_obsolete
from .permissions import NoTokenPermission, IsInvitee
from rest_framework.permissions import IsAuthenticated
from decouple import config
from rest_framework_simplejwt.tokens import RefreshToken
from django.contrib.auth import get_user_model
import uuid
from threading import Timer


from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync



from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from rest_framework_simplejwt.tokens import UntypedToken
from rest_framework_simplejwt.exceptions import InvalidToken, TokenError
from faker import Faker
from django.db import transaction

fake = Faker()

@method_decorator(csrf_exempt, name='dispatch')
class RegisterAPIView(APIView):
    permission_classes = [NoTokenPermission]
    queryset = User.objects.all()
    serializer_class = Register

    def post(self, request, *args, **kwargs):
        serializer = self.serializer_class(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response({'detail': 'Registration successful.'}, status=status.HTTP_200_OK)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


@method_decorator(csrf_exempt, name='dispatch')
class LoginAPIView(APIView):
    permission_classes = [NoTokenPermission]
    def post(self, request, *args, **kwargs):
        serializer_class = Login(data=request.data)
        if serializer_class.is_valid():
            username = serializer_class.validated_data['username']
            password = serializer_class.validated_data['password']
            user = authenticate(request, username=username, password=password)
            if user is not None:
                user_profile = User.objects.get(username=username)
                verification_code = generate_random_digits()
                user_profile.otp = verification_code
                user_profile.otp_expiry_time = timezone.now() + timedelta(hours=1)
                user_profile.save()

                from_email = "transcendance30@gmail.com"
                recipient_list = [user_profile.email]
                subject = "Verification Code"
                message = f"Your verification code is : {verification_code}"

                send_mail(subject, message, from_email, recipient_list, fail_silently=False)
                return Response({'detail': 'Verification code sent successfully.'}, status=status.HTTP_200_OK)

        return Response({'detail': 'Invalid credentials.'}, status=status.HTTP_400_BAD_REQUEST)

@method_decorator(csrf_exempt, name='dispatch')
class VerificationAPIView(APIView):
    def post(self, request, *args, **kwargs):
        permission_classes = [NoTokenPermission]
        serializer_class = Verification(data=request.data)
        if serializer_class.is_valid():
            username = serializer_class.validated_data['username']
            password = serializer_class.validated_data['password']
            code_otp = serializer_class.validated_data['code_otp']
            user = authenticate(request, username=username, password=password)
            if user is not None:
                user_profile = User.objects.get(username=username)
                if (
                    user_profile.otp == code_otp and
                    user_profile.otp_expiry_time is not None and
                    user_profile.otp_expiry_time > timezone.now()
                ):
                    user_profile.otp = ''
                    user_profile.otp_expiry_time = None
                    refresh = RefreshToken.for_user(user)
                    access_token = str(refresh.access_token)
                    user_profile.jwt_access = access_token
                    user_profile.jwt_refresh = str(refresh)
                    user_profile.is_online = 1
                    user_profile.tournaments_invit = False
                    user_profile.is_connect_game = False
                    user_profile.save()
                    return Response({'access_token': access_token, 'refresh_token': str(refresh)}, status=status.HTTP_200_OK)

        return Response({'detail': 'Invalid verification code or credentials.'}, status=status.HTTP_400_BAD_REQUEST)




@method_decorator(csrf_exempt, name='dispatch')    
class User_PictureAPIView(APIView):
    permission_classes = [IsAuthenticated]
    def get(self, request, *args, **kwargs):
        user = request.user
        if user.profile_photo:
            image_url = user.profile_photo.url
            return Response({'profile_image_url': image_url}, status=status.HTTP_200_OK)
        return Response(status=status.HTTP_404_NOT_FOUND)

@method_decorator(csrf_exempt, name='dispatch')     
class User_DetailAPIView(APIView):
    permission_classes = [IsAuthenticated]
    def get(self, request, username=None):
        if username:
            try:
                user = User.objects.get(username=username)
            except User.DoesNotExist:
                return Response({'detail': f' {username} doesn\'t exist.'}, status=status.HTTP_404_NOT_FOUND)
        else:
            user = request.user
        serializer = User_Detail(user)
        return Response(serializer.data)
    
@method_decorator(csrf_exempt, name='dispatch')
class UpdateInformationAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def get_object(self):
        return self.request.user

    def put(self, request):
        user = self.get_object()
        serializer = Update_Profile(user, data=request.data, partial=True)
        if serializer.is_valid():
            serializer.save()
            return Response({'detail': 'Informations update successfuly.'}, status=status.HTTP_200_OK)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@method_decorator(csrf_exempt, name='dispatch')
class UpdatePasswordAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def get_object(self):
        return self.request.user
    def put(self, request):
        user = self.get_object()
        serializer = Update_Password(user, data=request.data, context={'request': request})
        if serializer.is_valid():
            serializer.save()
            return Response({'detail': 'Password update successfuly.'}, status=status.HTTP_200_OK)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
    
@method_decorator(csrf_exempt, name='dispatch')
class FriendsListAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request):
        friendships = Friendship.objects.filter(from_user=request.user).select_related('to_user')

        if not friendships:
            return Response({"detail": "You don't have any friends yet."}, status=status.HTTP_404_NOT_FOUND)

        friends = [{"username": friendship.to_user.username, "profile_photo": friendship.to_user.profile_photo.url, "status": friendship.to_user.is_online} for friendship in friendships]

        return Response({"friends": friends}, status=status.HTTP_200_OK)

@method_decorator(csrf_exempt, name='dispatch')
class FriendshipAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request):
        username = request.data.get('username')
        if username is None:
            return Response({"detail": "Username not provided"}, status=status.HTTP_400_BAD_REQUEST)

        user = get_user_model().objects.filter(username=username).first()
        if user is None:
            return Response({"detail": "User not found"}, status=status.HTTP_404_NOT_FOUND)
        
        if Friendship.objects.filter(from_user=request.user, to_user=user).exists():
            return Response({"detail": "Friendship already exists"}, status=status.HTTP_400_BAD_REQUEST)
        
        if request.user.username == username:
            return Response({'detail': 'You can\'t invite yourself.'}, status=status.HTTP_400_BAD_REQUEST)

        Friendship.objects.create(from_user=request.user, to_user=user)
        Friendship.objects.create(from_user=user, to_user=request.user)

        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f'user_{user.username}',
            {
                'type': 'send_notifications_information',
                'text': f"{request.user.username} you added to his friends.",
                'bool': "0",
            }
        )
        return Response({"detail": f"{username} added succesfully."}, status=status.HTTP_200_OK)


@method_decorator(csrf_exempt, name='dispatch')
class RemoveFriendAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request):
        friend_username = request.data.get('username')

        if not friend_username:
            return Response({"detail": "Friend username is required"}, status=status.HTTP_400_BAD_REQUEST)


        friend = get_user_model().objects.filter(username=friend_username).first()
        if not friend:
            return Response({"detail": "Friend not found"}, status=status.HTTP_404_NOT_FOUND)


        friendship = Friendship.objects.filter(from_user=request.user, to_user=friend).first()
        friendship_two = Friendship.objects.filter(from_user=friend, to_user=request.user).first()
        if not friendship:
            return Response({"detail": "Friendship not found"}, status=status.HTTP_404_NOT_FOUND)


        friendship.delete()
        friendship_two.delete()
        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f'user_{friend.username}',
            {
                'type': 'send_notifications_information',
                'text': f"{request.user.username} deleted you from his friends",
                'bool': "0",
            }
        )

        return Response({"detail": f"{friend_username} removed successfully."}, status=status.HTTP_200_OK)


class Send_Invitations_TournamentsAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request):
        invited_user_one = request.data.get('username_one')
        invited_user_two = request.data.get('username_two')
        invited_user_three = request.data.get('username_three')

        if not invited_user_one or not invited_user_two or not invited_user_three :
            return Response({'detail': 'Username is required.'}, status=status.HTTP_400_BAD_REQUEST)
        
        try:
            user_one = User.objects.get(username=invited_user_one)
            user_two = User.objects.get(username=invited_user_two)
            user_three = User.objects.get(username=invited_user_three)
        except User.DoesNotExist:
            return Response({'detail': 'This username doesn\'t exist.'}, status=status.HTTP_400_BAD_REQUEST)

        if request.user.username == invited_user_one or request.user.username == invited_user_two or request.user.username == invited_user_three:
            return Response({'detail': 'You can\'t invite yourself.'}, status=status.HTTP_400_BAD_REQUEST)
        
        if not Friendship.objects.filter(from_user=request.user, to_user= user_one).exists() and \
            not Friendship.objects.filter(from_user= user_one, to_user=request.user).exists() or \
            not Friendship.objects.filter(from_user=request.user, to_user= user_two).exists() and \
            not Friendship.objects.filter(from_user= user_two, to_user=request.user).exists() or \
            not Friendship.objects.filter(from_user=request.user, to_user= user_three).exists() and \
            not Friendship.objects.filter(from_user= user_three, to_user=request.user).exists():
            return Response({'detail' : 'It\'s not yours friends.'}, status=status.HTTP_400_BAD_REQUEST)
        
        game_user_one = Game.objects.filter(player_2=user_one, is_active=True).first()
        game_user_one_two = Game.objects.filter(player_1=user_one, is_active=True).first()
        game_user_two = Game.objects.filter(player_2=user_two, is_active=True).first()
        game_user_two_two = Game.objects.filter(player_1=user_two, is_active=True).first()
        game_user_three = Game.objects.filter(player_2=user_three, is_active=True).first()
        game_user_three_two = Game.objects.filter(player_1=user_three, is_active=True).first()
        if game_user_one:
            if game_user_one.is_active == True:
                return Response({'detail': 'This user is already in a game.'}, status=status.HTTP_400_BAD_REQUEST)
        elif game_user_one_two:
            if game_user_one_two.is_active == True:
                return Response({'detail': 'This user is already in a game.'}, status=status.HTTP_400_BAD_REQUEST)
        elif game_user_two:
            if game_user_two.is_active == True:
                return Response({'detail': 'This user is already in a game.'}, status=status.HTTP_400_BAD_REQUEST)
        elif game_user_two_two:
            if game_user_two_two.is_active == True:
                return Response({'detail': 'This user is already in a game.'}, status=status.HTTP_400_BAD_REQUEST)
        elif game_user_three:
            if game_user_three.is_active == True:
                return Response({'detail': 'This user is already in a game.'}, status=status.HTTP_400_BAD_REQUEST)
        elif  game_user_three_two:
            if game_user_three_two.is_active == True:
                return Response({'detail': 'This user is already in a game.'}, status=status.HTTP_400_BAD_REQUEST)
        invitation = Tournaments_Invitations.objects.create(
            inviting_user=request.user,
            invited_user_one = user_one,
            invited_user_two = user_two,
            invited_user_three = user_three,
            accepted=None,
            id=generate_random_digits(4),
        )
        user = request.user
        user.is_online = 2
        user.save()
        Timer(10, make_invitation_tournaments_obsolete, args=(invitation.id,)).start()

        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f'user_{user_one.username}',
            {
                'type': 'send_notifications_confirmation',
                'text': f"Join {request.user.username} for a game ?",
            }
        )
        async_to_sync(channel_layer.group_send)(
            f'user_{user_one.username}',
            {
                'type': 'send_notifications_no_display',
                'text': f"{invitation.id}",
                'bool' : "450",
            }
        )
        async_to_sync(channel_layer.group_send)(
            f'user_{user_two.username}',
            {
                'type': 'send_notifications_confirmation',
                'text': f"Join {request.user.username} for a game ?",
            }
        )
        async_to_sync(channel_layer.group_send)(
            f'user_{user_two.username}',
            {
                'type': 'send_notifications_no_display',
                'text': f"{invitation.id}",
                'bool' : "450",
            }
        )
        async_to_sync(channel_layer.group_send)(
            f'user_{user_three.username}',
            {
                'type': 'send_notifications_confirmation',
                'text': f"Join {request.user.username} for a game ?",
            }
        )
        async_to_sync(channel_layer.group_send)(
            f'user_{user_three.username}',
            {
                'type': 'send_notifications_no_display',
                'text': f"{invitation.id}",
                'bool' : "450",
            }
        )
        return Response({'status': 'Invitation send successfully'}, status=status.HTTP_200_OK)


class Response_Invitation_TournamentsAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request, *args, **kwargs):
        invitation_id = request.data.get('invitation_id')
        accepted = request.data.get('accepted')
        if not invitation_id or accepted is None:
            return Response({'detail': 'Invitation ID or accepted is required'}, status=status.HTTP_400_BAD_REQUEST)

        try:
            invitation = Tournaments_Invitations.objects.get(id=invitation_id)
            if invitation.accepted == False:
                channel_layer = get_channel_layer()
                async_to_sync(channel_layer.group_send)(
                    f'user_{invitation.inviting_user.username}',
                    {
                        'type': 'send_notifications_information',
                        'text': 'Your invitation was declined.',
                        'bool': "398",
                    }
                )
                return Response({'detail': 'Invitation is expired.'}, status=status.HTTP_400_BAD_REQUEST)
        except Invitation.DoesNotExist:
            return Response({'detail': 'Invitation doesn\'t exist'}, status=status.HTTP_404_NOT_FOUND)

        if accepted == "True":
            if request.user.tournaments_invit == False:
                invitation.incr += 1
                request.user.tournaments_invit = True
                request.user.save()
                invitation.save()
            if invitation.incr >= 3:
                print("Ca doit rentrer ici")
                room = Name_Tournaments_Game.objects.create(
                    semi_finals_one = fake.pystr(max_chars=25, min_chars=15),
                    semi_finals_two = fake.pystr(max_chars=25, min_chars=15),
                    finals = fake.pystr(max_chars=25, min_chars=15),
                    is_deconnect = False,
                    is_finish = False,
                )
                game_one = Game.objects.create(
                    player_1 = invitation.inviting_user,
                    player_2 = invitation.invited_user_two,
                    player_1_username = invitation.inviting_user.username,
                    player_2_username = invitation.invited_user_two.username,
                    game_name = room.semi_finals_one,
                    is_active = True,
                    is_finish = False,
                    created_at=timezone.now(),
                    is_semifinals = True,
                    is_finals = False,
                    other_semi_finals_name = room.semi_finals_two,
                    other_finals_name = room.finals
                )
                game_two = Game.objects.create(
                    player_1 = invitation.invited_user_one,
                    player_2 = invitation.invited_user_three,
                    player_1_username = invitation.invited_user_one.username,
                    player_2_username = invitation.invited_user_three.username,
                    game_name = room.semi_finals_two,
                    is_active = True,
                    is_finish = False,
                    created_at=timezone.now(),
                    is_semifinals = True,
                    is_finals = False,
                    other_semi_finals_name = room.semi_finals_one,
                    other_finals_name = room.finals
                )
                finals = Game.objects.create(
                    game_name = room.finals,
                    is_active = True,
                    is_finish = False,
                    created_at=timezone.now(),
                    is_semifinals = False,
                    is_finals = True,
                )
                invitation.inviting_user.is_online = 2
                invitation.invited_user_one.is_online = 2
                invitation.invited_user_two.is_online = 2
                invitation.invited_user_three.is_online = 2
                invitation.inviting_user.tournaments_invit = False
                invitation.invited_user_one.tournaments_invit = False
                invitation.invited_user_two.tournaments_invit = False
                invitation.invited_user_three.tournaments_invit = False
                invitation.inviting_user.save()
                invitation.invited_user_one.save()
                invitation.invited_user_two.save()
                invitation.invited_user_three.save()
                game_one.allowed_users.add(invitation.inviting_user)
                game_one.allowed_users.add(invitation.invited_user_two)
                game_two.allowed_users.add(invitation.invited_user_one)
                game_two.allowed_users.add(invitation.invited_user_three)
                room.allowed_users.add(invitation.inviting_user)
                room.allowed_users.add(invitation.invited_user_one)
                room.allowed_users.add(invitation.invited_user_two)
                room.allowed_users.add(invitation.invited_user_three)
                finals.allowed_users.add(invitation.inviting_user)
                finals.allowed_users.add(invitation.invited_user_one)
                finals.allowed_users.add(invitation.invited_user_two)
                finals.allowed_users.add(invitation.invited_user_three)
                channel_layer = get_channel_layer()
                async_to_sync(channel_layer.group_send)(
                    f'user_{invitation.inviting_user.username}',
                    {
                        'type': 'send_notifications_no_display',
                        'text': f"{room.semi_finals_one}",
                        'bool': "397",
                    }
                )
                async_to_sync(channel_layer.group_send)(
                    f'user_{invitation.invited_user_two.username}',
                    {
                        'type': 'send_notifications_no_display',
                        'text': f"{room.semi_finals_one}",
                        'bool': "397",
                    }
                )
                async_to_sync(channel_layer.group_send)(
                    f'user_{invitation.invited_user_one.username}',
                    {
                        'type': 'send_notifications_no_display',
                        'text': f"{room.semi_finals_two}",
                        'bool': "397",
                    }
                )
                async_to_sync(channel_layer.group_send)(
                    f'user_{invitation.invited_user_three.username}',
                    {
                        'type': 'send_notifications_no_display',
                        'text': f"{room.semi_finals_two}",
                        'bool': "397",
                    }
                )
                return Response({'detail': 'Invitation accepted'}, status=status.HTTP_200_OK)
        else:
            invitation.incr -= 1
            invitation.accepted = False
            invitation.save()
            channel_layer = get_channel_layer()
            async_to_sync(channel_layer.group_send)(
                f'user_{invitation.inviting_user.username}',
                {
                    'type': 'send_notifications_information',
                    'text': 'Your invitation was declined.',
                    'bool': "398",
                }
            )
            return Response({'detail': 'Invitation refused.'}, status=status.HTTP_200_OK)
        return Response({'detail': 'Invitation accepted'}, status=status.HTTP_200_OK)


class Send_InvitationAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request):
        invited_user_name = request.data.get('username')

        if not invited_user_name:
            return Response({'detail': 'Username is required.'}, status=status.HTTP_400_BAD_REQUEST)

        try:
            invited_user = User.objects.get(username=invited_user_name)
        except User.DoesNotExist:
            return Response({'detail': 'This username doesn\'t exist.'}, status=status.HTTP_400_BAD_REQUEST)

        if request.user.username == invited_user_name:
            return Response({'detail': 'You can\'t invite yourself.'}, status=status.HTTP_400_BAD_REQUEST)
        
        if not Friendship.objects.filter(from_user=request.user, to_user=invited_user).exists() and \
           not Friendship.objects.filter(from_user=invited_user, to_user=request.user).exists():
            return Response({'detail' : 'It\'s not yours friends.'}, status=status.HTTP_400_BAD_REQUEST)
        
        game = Game.objects.filter(player_2=invited_user, is_active=True).first()
        game_two = Game.objects.filter(player_1=invited_user, is_active=True).first()
        if game:
            if game.is_active == True:
                return Response({'detail': 'This user is already in a game.'}, status=status.HTTP_400_BAD_REQUEST)
        elif game_two:
            if game_two.is_active == True:
                return Response({'detail': 'This user is already in a game.'}, status=status.HTTP_400_BAD_REQUEST)

        invitation = Invitation.objects.create(
            inviting_user=request.user,
            invited_user=invited_user,
            accepted=None,
            id=generate_random_digits(4),
        )
        user = request.user
        user.is_online = 2
        user.save()
        Timer(5, make_invitation_obsolete, args=(invitation.id,)).start()

        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f'user_{invited_user.username}',
            {
                'type': 'send_notifications_confirmation',
                'text': f"Join {request.user.username} for a game ?",
            }
        )
        async_to_sync(channel_layer.group_send)(
            f'user_{invited_user.username}',
            {
                'type': 'send_notifications_no_display',
                'text': f"{invitation.id}",
                'bool' : "0",
            }
        )
        return Response({'status': 'Invitation send successfully'}, status=status.HTTP_200_OK)

class Response_InvitationAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request, *args, **kwargs):
        invitation_id = request.data.get('invitation_id')
        accepted = request.data.get('accepted')
        if not invitation_id or accepted is None:
            return Response({'detail': 'Invitation ID or accepted is required'}, status=status.HTTP_400_BAD_REQUEST)

        try:
            invitation = Invitation.objects.get(id=invitation_id)
            if invitation.accepted == False:
                channel_layer = get_channel_layer()
                async_to_sync(channel_layer.group_send)(
                    f'user_{invitation.inviting_user.username}',
                    {
                        'type': 'send_notifications_information',
                        'text': 'Your invitation was declined.',
                        'bool': "398",
                    }
                )
                return Response({'detail': 'Invitation is expired.'}, status=status.HTTP_400_BAD_REQUEST)
        except Invitation.DoesNotExist:
            return Response({'detail': 'Invitation doesn\'t exist'}, status=status.HTTP_404_NOT_FOUND)

        if accepted == "True":
            if invitation.invited_user != request.user:
                return Response({'detail': 'You are not the invited user'}, status=status.HTTP_400_BAD_REQUEST)
            room_name = fake.pystr(max_chars=25, min_chars=15)
            invitation.accepted = True
            invitation.save()

            game = Game.objects.create(
            player_1 = invitation.inviting_user,
            player_2 = invitation.invited_user,
            player_1_username = invitation.inviting_user.username,
            player_2_username = invitation.invited_user.username,
            game_name = room_name,
            is_active = True,
            is_finish = False,
            created_at=timezone.now(),
            is_semifinals = False,
            is_finals = False,
        )
            invitation.inviting_user.is_online = 2
            invitation.invited_user.is_online = 2
            invitation.invited_user.save()
            invitation.invited_user.save()
            game.allowed_users.add(invitation.inviting_user)
            game.allowed_users.add(invitation.invited_user)
            channel_layer = get_channel_layer()
            async_to_sync(channel_layer.group_send)(
                f'user_{invitation.inviting_user.username}',
                {
                    'type': 'send_notifications_no_display',
                    'text': f"{room_name}",
                    'bool': "397",
                }
            )
            async_to_sync(channel_layer.group_send)(
                f'user_{invitation.invited_user}',
                {
                    'type': 'send_notifications_no_display',
                    'text': f"{room_name}",
                    'bool': "397",
                }
            )
            return Response({'detail': 'Invitation accepted'}, status=status.HTTP_200_OK)
        else:
            invitation.accepted = False
            invitation.save()
            channel_layer = get_channel_layer()
            async_to_sync(channel_layer.group_send)(
                f'user_{invitation.inviting_user.username}',
                {
                    'type': 'send_notifications_information',
                    'text': 'Your invitation was declined.',
                    'bool': "398",
                }
            )
            return Response({'detail': 'Invitation refused.'}, status=status.HTTP_200_OK)


@method_decorator(csrf_exempt, name='dispatch')
class VerifyTokenAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def post(self, request, *args, **kwargs):
        token = request.data.get('token')
        if not token:
            return Response({'detail': 'Token is required.'}, status=status.HTTP_400_BAD_REQUEST)
        try:
            UntypedToken(token)
        except (InvalidToken, TokenError) as e:
            return Response({'detail': 'Invalid'}, status=status.HTTP_401_UNAUTHORIZED)
        
        return Response({'detail': 'Valid'}, status=status.HTTP_200_OK)

@method_decorator(csrf_exempt, name='dispatch')     
class User_Detail_Game_APIView(APIView):
    permission_classes = [IsAuthenticated]
    def post(self, request, username=None):
        room = request.data.get('room')

        if not room:
            return Response({'detail': 'room is required'}, status=status.HTTP_400_BAD_REQUEST)

        try:
            game = Game.objects.get(game_name=room)
            if game.player_1.username == request.user.username:
                return Response({'profile_photo': f'{game.player_2.profile_photo}', 'name': f'{game.player_2.username}'}, status=status.HTTP_200_OK)
            if game.player_2.username == request.user.username:
                return Response({'profile_photo': f'{game.player_1.profile_photo}', 'name': f'{game.player_1.username}'}, status=status.HTTP_200_OK)
        except Game.DoesNotExist:
            return Response({'detail': 'This room game doesn\'t exist.'}, status=status.HTTP_400_BAD_REQUEST)
        
@method_decorator(csrf_exempt, name='dispatch')  
class UserGameWinAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request):
        user = request.user
        games = Game.objects.filter(allowed_users=user)
        if not games:
            return Response({'detail': 'No games found'}, status=status.HTTP_404_NOT_FOUND)
        wins = 0
        losses = 0
        if Game.objects.filter(player_1=user).exists():
            games = Game.objects.filter(player_1=user)
            for game in games:
                winner = get_winner_player_one(game)
                if winner:
                    wins += 1
                elif winner == False:
                    losses += 1
                else:
                    pass
        if Game.objects.filter(player_2=user).exists():
            games = Game.objects.filter(player_2=user)
            for game in games:
                winner = get_winner_player_two(game)
                if winner:
                    wins += 1
                elif winner == False:
                    losses += 1
                else:
                    pass
        return Response({
            'wins': wins,
            'losses': losses
        })


class UserGameStatsAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request):
        user = request.user
        games = Game.objects.filter(allowed_users=user)
        if not games:
            return Response({'detail': 'No games found'}, status=status.HTTP_404_NOT_FOUND)
        game_stats = []
        for game in games:
            if game.player_1 is not None and game.player_2 is not None:
                game_stats.append({
                    'player_one': game.player_1.username,
                    'player_two': game.player_2.username,
                    'created_at': game.created_at,
                    'score_one': game.score_player_1,
                    'score_two': game.score_player_2,
                })

        return Response(game_stats)
    
class UserLogoutAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request):
        user = request.user
        if user is None:
            return Response({'detail': 'User not found.'}, status=status.HTTP_404_NOT_FOUND)
        user.is_online = 0
        user.save()
        return Response({'detail': 'Logout successful.'}, status=status.HTTP_200_OK)


class UserLogoutAPIView(APIView):
    permission_classes = [IsAuthenticated]

    def get(self, request):
        user = request.user
        if user is None:
            return Response({'detail': 'User not found.'}, status=status.HTTP_404_NOT_FOUND)
        user.is_online = 0
        user.save()
        return Response({'detail': 'Logout successful.'}, status=status.HTTP_200_OK)
