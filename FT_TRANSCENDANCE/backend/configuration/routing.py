from channels.routing import ProtocolTypeRouter, URLRouter
from django.urls import path
from django.urls import re_path
from api_transcendance import consumers

websocket_urlpatterns = [
    re_path(r'ws/notifications/(?P<username>\w+)/$', consumers.NotificationConsumer.as_asgi()),
    re_path(r'ws/pong/(?P<room_name>\w+)/$', consumers.PongConsumer.as_asgi()),
]