from rest_framework.permissions import BasePermission
from rest_framework.exceptions import PermissionDenied




class NoTokenPermission(BasePermission):
    def has_permission(self, request, view):
        if request.user and request.user.is_authenticated:
            raise(PermissionDenied(detail="Authenticated users are not allowed to access this view."))
        return True
    

class IsInvitee(BasePermission):
    def has_object_permission(self, request, view, obj):
        if obj.invited_user != request.user:
            raise(PermissionDenied(detail="This invitations is not for you."))


