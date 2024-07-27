from django.contrib import admin
from .models import User, Game, Invitation, Tournaments_Invitations, Name_Tournaments_Game

admin.site.register(User)
admin.site.register(Game)
admin.site.register(Invitation)
admin.site.register(Tournaments_Invitations)
admin.site.register(Name_Tournaments_Game)