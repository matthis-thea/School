from urllib.parse import parse_qs
from channels.middleware.base import BaseMiddleware
from channels.db import database_sync_to_async
from django.contrib.auth.models import AnonymousUser
from rest_framework_simplejwt.tokens import AccessToken
from django.contrib.auth import get_user_model

User = get_user_model()

@database_sync_to_async
def get_user(token_key):
    try:
        access_token = AccessToken(token_key)
        user_id = access_token['user_id']
        return User.objects.get(id=user_id)
    except Exception:
        return AnonymousUser()

class JWTAuthMiddleware(BaseMiddleware):
    """
    Middleware pour authentifier l'utilisateur via un token JWT
    passé en paramètre de requête dans l'URL de connexion websocket.
    """

    async def __call__(self, scope, receive, send):
        # Récupérer le token JWT depuis les paramètres de requête
        query_string = parse_qs(scope['query_string'].decode())
        token_key = query_string.get('token', [None])[0]

        # Vérifier et attribuer l'utilisateur à scope['user']
        scope['user'] = await get_user(token_key)

        return await super().__call__(scope, receive, send)