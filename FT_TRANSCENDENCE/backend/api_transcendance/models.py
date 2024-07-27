from django.db import models
from django.contrib.auth.models import AbstractUser
from django.conf import settings

class User(AbstractUser):
    profile_photo = models.ImageField(verbose_name="Photo de Profile", blank=True, null=True, default='default/42_icon.png', upload_to="users/")
    otp = models.CharField(max_length=6, blank=True)
    otp_expiry_time = models.DateTimeField(blank=True, null=True)
    jwt_access = models.CharField(max_length=255, blank=True)
    jwt_refresh = models.CharField(max_length=255, blank=True)
    is_online = models.IntegerField(default=0)
    tournaments_invit = models.BooleanField(default=False)

class Friendship(models.Model):
    from_user = models.ForeignKey(settings.AUTH_USER_MODEL, related_name='friendships_from', on_delete=models.CASCADE)
    to_user = models.ForeignKey(settings.AUTH_USER_MODEL, related_name='friendships_to', on_delete=models.CASCADE)


class Tournaments_Invitations(models.Model):
    inviting_user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='sent_invitations_tournaments')
    invited_user_one = models.ForeignKey(User, on_delete=models.CASCADE, related_name='received_invitations_one_tournaments')
    invited_user_two = models.ForeignKey(User, on_delete=models.CASCADE, related_name='received_invitations_two_tournaments')
    invited_user_three = models.ForeignKey(User, on_delete=models.CASCADE, related_name='received_invitations_three_tournaments')
    accepted = models.BooleanField(null=True, blank=True)
    incr = models.IntegerField(default=0)

class Invitation(models.Model):
    inviting_user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='sent_invitations')
    invited_user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='received_invitations')
    accepted = models.BooleanField(null=True, blank=True)

class Name_Tournaments_Game(models.Model):
    semi_finals_one = models.CharField(max_length=255)
    semi_finals_two = models.CharField(max_length=255)
    finals = models.CharField(max_length=255)
    allowed_users = models.ManyToManyField(User, related_name='Name_Tournaments_Game_finals_allowed')
    authorize_for_finals = models.ManyToManyField(User, related_name='Name_Tournaments_Game_authorize_finals', blank=True)
    incr = models.IntegerField(default=0)
    is_deconnect = models.BooleanField(default=False)
    is_finish = models.BooleanField(default=False)

class Game(models.Model):
    game_name = models.CharField(max_length=255)
    player_1 = models.ForeignKey(User, on_delete=models.CASCADE, related_name='player_1', null=True)
    player_2 = models.ForeignKey(User, on_delete=models.CASCADE, related_name='player_2', null=True)
    player_1_username = models.CharField(max_length=255, blank=True, null=True)
    player_2_username = models.CharField(max_length=255, blank=True, null=True)
    score_player_1 = models.IntegerField(default=0)
    score_player_2 = models.IntegerField(default=0)
    is_active = models.BooleanField(default=False)
    is_finish = models.BooleanField(default=False)
    created_at = models.DateTimeField(auto_now_add=True)
    allowed_users = models.ManyToManyField(User, related_name='rooms')
    is_semifinals = models.BooleanField(default=False)
    is_finals = models.BooleanField(default=False)
    other_semi_finals_name = models.CharField(max_length=255, blank=True, null=True)
    other_finals_name = models.CharField(max_length=255, blank=True, null=True)