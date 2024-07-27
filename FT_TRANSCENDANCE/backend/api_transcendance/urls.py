from django.urls import path, include
from .views import RegisterAPIView, LoginAPIView, VerificationAPIView, User_PictureAPIView, User_DetailAPIView, UpdateInformationAPIView, UpdatePasswordAPIView \
    , FriendshipAPIView, FriendsListAPIView, RemoveFriendAPIView, VerifyTokenAPIView, Send_InvitationAPIView, Response_InvitationAPIView, User_Detail_Game_APIView \
    , UserGameWinAPIView, UserGameStatsAPIView, UserLogoutAPIView, Send_Invitations_TournamentsAPIView, Response_Invitation_TournamentsAPIView
from rest_framework_simplejwt.views import TokenRefreshView

urlpatterns = [
    path('register/', RegisterAPIView.as_view(), name="register_transcendance"),
    path('login/', LoginAPIView.as_view(), name="login_transcendance"),
    path('verification/', VerificationAPIView.as_view(), name="verification_transcendance"),
    path('token/refresh/', TokenRefreshView.as_view(), name='tokenrefresh_transcendance'),
    path('user_picture/', User_PictureAPIView.as_view(), name="userpicture_transcendance"),
    path('user/', User_DetailAPIView.as_view(), name='userdetail_transcendace'),
    path('user/<str:username>', User_DetailAPIView.as_view(), name='userdetailother_transcendace'),
    path('update/', UpdateInformationAPIView.as_view(), name='updateinformation_transcendace'),
    path('update_password/', UpdatePasswordAPIView.as_view(), name='updatepassword_transcendace'),
    path('friends_add/', FriendshipAPIView.as_view(), name='addfriends_transcendace'),
    path('friends_list/', FriendsListAPIView.as_view(), name='friendslist_transcendace'),
    path('remove_friends/', RemoveFriendAPIView.as_view(), name='removefriends_transcendace'),
    path('verify-token/', VerifyTokenAPIView.as_view(), name="verify_transcendance" ),
    path('send_invitation/', Send_InvitationAPIView.as_view(), name='sendinvitation_transcendace'),
    path('send_invitation_tournaments/', Send_Invitations_TournamentsAPIView.as_view(), name='sendinvitation_tournaments_transcendace'),
    path('response_invitation/', Response_InvitationAPIView.as_view(), name='responseinvitation_transcendace'),
    path('response_invitation_tournaments/', Response_Invitation_TournamentsAPIView.as_view(), name='responseinvitation_tournaments_transcendace'),
    path('user_detail_game/', User_Detail_Game_APIView.as_view(), name='userdetailgame_transcendace'),
    path('user_game_win/', UserGameWinAPIView.as_view(), name='usergamewin_transcendace'),
    path('user_game_stats/', UserGameStatsAPIView.as_view(), name='usergamestats_transcendace'),
    path('logout/', UserLogoutAPIView.as_view(), name='userlogout_transcendace'),

]