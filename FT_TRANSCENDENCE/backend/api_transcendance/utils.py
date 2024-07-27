import datetime
import jwt
from django.conf import settings
from .models import User
import random
from decouple import config
from rest_framework_simplejwt.tokens import AccessToken
from rest_framework.exceptions import PermissionDenied
from jwt import ExpiredSignatureError, InvalidTokenError
from django.conf import settings
from .models import Invitation, Tournaments_Invitations
from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync



def generate_random_digits(n=6):
    return "".join(map(str, random.sample(range(0, 10), n)))

def make_invitation_tournaments_obsolete(invitation_id):
    invitation_to = Tournaments_Invitations.objects.get(id=invitation_id)
    if invitation_to.accepted == None and invitation_to.incr < 3:
        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f'user_{invitation_to.inviting_user.username}',
            {
                'type': 'send_notifications_information',
                'text': 'Your invitation was declined.',
                'bool': "398",
            }
        )
        invitation_to.inviting_user.tournaments_invit = False
        invitation_to.invited_user_one.tournaments_invit = False
        invitation_to.invited_user_two.tournaments_invit = False
        invitation_to.invited_user_three.tournaments_invit = False
        invitation_to.inviting_user.save()
        invitation_to.invited_user_one.save()
        invitation_to.invited_user_two.save()
        invitation_to.invited_user_three.save()
    Tournaments_Invitations.objects.filter(id=invitation_id).update(accepted=False)


def make_invitation_obsolete(invitation_id):
    invitation = Invitation.objects.get(id=invitation_id)
    if invitation.accepted == None:
        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f'user_{invitation.inviting_user.username}',
            {
                'type': 'send_notifications_information',
                'text': 'Your invitation was declined.',
                'bool': "398",
            }
        )
        invitation.inviting_user.is_online = 1
        invitation.inviting_user.save()
    Invitation.objects.filter(id=invitation_id).update(accepted=False)

def get_winner_player_one(game):
    if game.score_player_1 > game.score_player_2:
        return True
    elif game.score_player_1 < game.score_player_2:
        return False
    else:
        return True
    
def get_winner_player_two(game):
    if game.score_player_1 > game.score_player_2:
        return False
    elif game.score_player_1 < game.score_player_2:
        return True
    else:
        return True
