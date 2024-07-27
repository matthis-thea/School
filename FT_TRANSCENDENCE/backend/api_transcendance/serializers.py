from rest_framework import serializers
from .models import User
from rest_framework.validators import UniqueValidator
from django.contrib.auth.password_validation import validate_password
from django.core.exceptions import ValidationError
from django.contrib.auth.hashers import check_password
from django.contrib.auth import get_user_model


User = get_user_model()


class UserSerializer_friend(serializers.ModelSerializer):
    class Meta:
        model = User
        fields= ['username', 'profile_photo']

class Update_Password(serializers.ModelSerializer):
    old_password = serializers.CharField(write_only=True)
    password1 = serializers.CharField(write_only=True)
    password2 = serializers.CharField(write_only=True)

    class Meta:
        model = User
        fields = ['old_password', 'password1', 'password2']
    def validate_old_password(self, value):
        user = self.context['request'].user
        if not check_password(value, user.password):
            raise serializers.ValidationError({"password": "The actual password is incorrect."})
    def validate(self, data):
        if data.get('password1') != data.get('password2'):
            raise serializers.ValidationError({"password": "The new password doesn't match."})

        try:
            validate_password(data.get('password1'))
        except ValidationError as e:
            raise serializers.ValidationError({"password": e.messages})

        return data
    def update(self, instance, validated_data):
        instance.set_password(validated_data.get('password1'))
        instance.save()
        return instance

class Update_Profile(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['username', 'email', 'profile_photo',]
        extra_kwargs = {
            'username': {'validators': [UniqueValidator(queryset=User.objects.all())]},
            'email': {'validators': [UniqueValidator(queryset=User.objects.all())]}
        }
    def validate_username(self, value):
        if value is not None:
            if not (5 <= len(value) <= 15):
                raise serializers.ValidationError({"username": "The username must contain at least 5 characters and a maximum of 15."})
        return value
    def update(self, instance, validated_data):
        instance.username = validated_data.get('username', instance.username)
        instance.email = validated_data.get('email', instance.email)
        instance.profile_photo = validated_data.get('profile_photo', instance.profile_photo)
        instance.save()
        return instance

class User_Detail(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['username', 'email', 'profile_photo']

class Access_Refresh_Token(serializers.Serializer):
    access_token = serializers.CharField()
    refresh_token = serializers.CharField()

class Verification(serializers.Serializer):
    password = serializers.CharField(write_only=True)
    username = serializers.CharField()
    code_otp = serializers.CharField()

class Login(serializers.Serializer):
    password = serializers.CharField(write_only=True)
    username = serializers.CharField()

class Register(serializers.ModelSerializer):
    password1 = serializers.CharField(write_only=True)
    password2 = serializers.CharField(write_only=True)

    class Meta:
        model = User
        fields = ['username', 'email', 'password1', 'password2',]
        extra_kwargs = {
            'username': {'validators': [UniqueValidator(queryset=User.objects.all())]},
            'email': {'validators': [UniqueValidator(queryset=User.objects.all())]}
        }

    def validate(self, data):
        if len(data.get('username')) < 5 or  len(data.get('username')) > 15:
            raise serializers.ValidationError({"username": "The username must contain at least 5 characters and a maximum of 15."})

        if data.get('password1') != data.get('password2'):
            raise serializers.ValidationError({"password": "The passwords don't match."})

        try:
            validate_password(data.get('password1'))
        except ValidationError as e:
            raise serializers.ValidationError({"password": e.messages})

        return data
    
    
    def create(self, validated_data):
        username = validated_data.pop('username')
        email = validated_data.pop('email')
        password = validated_data.pop('password1')

        user = User.objects.create_user(username=username, email=email, password=password)
        
        user.save()
        return user
    



