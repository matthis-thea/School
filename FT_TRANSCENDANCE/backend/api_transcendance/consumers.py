import json
from channels.generic.websocket import AsyncWebsocketConsumer
import asyncio
import logging
from rest_framework import status
from rest_framework.response import Response
import random
from channels.exceptions import StopConsumer


logger = logging.getLogger(__name__)

class PongConsumer(AsyncWebsocketConsumer):
    #------------------------------------------------------- Variable globale
    rooms = {}  # Dictionnaire pour suivre les utilisateurs par room
    connected_users = {}
    game_state = {
        'ball_position': [50, 50],
        'ball_velocity': [1, 1],
        'paddle_positions': { },
        'scores_me': {}
    }
    game_running = False
    game_deconnect = False
    game_error = True
    game_message = {'False': False}
    #------------------------------------------------------------------------------------
    #------------------------------------------------------- Gerer base de donnees
    from channels.db import database_sync_to_async
    @database_sync_to_async
    def get_user_by_id(self, user_id):
        from django.contrib.auth import get_user_model
        User = get_user_model()
        try:
            user = User.objects.get(id=user_id)
            return user
        except User.DoesNotExist:
            return None

    @database_sync_to_async
    def get_username_by_id(self, user_id):
        from django.contrib.auth import get_user_model
        User = get_user_model()
        try:
            user = User.objects.get(id=user_id)
            return user.username
        except User.DoesNotExist:
            return None

    @database_sync_to_async
    def get_game(self, room_name):
        from .models import Game
        try:
            game = Game.objects.get(game_name=room_name)
            return Game.objects.get(game_name=room_name)
        except Game.DoesNotExist:
            return False

    @database_sync_to_async
    def get_allowed_users(self, game):
        return list(game.allowed_users.all())

    @database_sync_to_async
    def get_player_1(self, room_name):
        from .models import Game
        game = Game.objects.get(game_name=room_name)
        return game.player_1


    @database_sync_to_async
    def verification_game_is_active(self, room_name):
        from .models import Game
        game = Game.objects.get(game_name=room_name)
        if game.is_active:
            return True
        return False
    
    @database_sync_to_async
    def put_player_one_and_player_two(self, room_name, user_id):
        from .models import Game
        game = Game.objects.get(game_name=room_name)
        allowed_users = game.allowed_users.all()
        from django.contrib.auth import get_user_model
        User = get_user_model()
        user = User.objects.get(id=user_id)
        for gamer in allowed_users:
            # Vérifier si l'utilisateur est différent de player_1 et player_2
            if user == gamer:
                if game.player_1 is None:
                    from django.contrib.auth import get_user_model
                    game.player_1 = user
                    game.player_1_username = user.username
                    game.save()
                    return True
                if game.player_2 is None and game:
                    from django.contrib.auth import get_user_model
                    game.player_2 = user
                    game.player_2_username = user.username
                    game.save()
                    return True
        if game.player_1 is None or game.player_2 is None:
            return False

    @database_sync_to_async
    def activate_for_player_one(self, room_name, user_id):
        from .models import Game
        game = Game.objects.get(game_name=room_name)
        if user_id == game.player_1.username:
            return True
        return False

    
    @database_sync_to_async
    def desactive_game(self, room_name):
        try:
            # Récupérer le jeu en cours pour ce canal
            from .models import Game
            game = Game.objects.get(game_name=self.room_name)
            game.is_active = False
            game.is_finish = True
            game.save()
        except Game.DoesNotExist:
            pass  # Gérer si le jeu n'est pas trouvé ou d'autres erreurs

    @database_sync_to_async
    def update_game_on_disconnect(self, user_id, id):
        try:
            # Récupérer le jeu en cours pour ce canal
            from .models import Game
            game = Game.objects.get(game_name=self.room_name)

            from django.contrib.auth import get_user_model
            User = get_user_model()
            user = User.objects.get(id=id)
            user.is_online = 1
            user.save()
            

            users_to_remove = []
            allowed_users = game.allowed_users.all()
            # Mettre à jour le score du joueur qui se déconnecte
            if user_id == game.player_1.username:
                game.score_player_2 = self.game_state[self.room_name]['scores'][self.get_other_id_user(self.room_name)]
                game.score_player_1 = self.game_state[self.room_name]['scores'][self.user.id]
                game.player_1_username = user_id
            if game.is_finals == True:
                for user in allowed_users:
                    if user != game.player_1 and user != game.player_2:
                        users_to_remove.append(user)
                for user in users_to_remove:
                    game.allowed_users.remove(user)
            

            # Mettre a jour le deuxieme jouers 

            
            # Mettre is_active à True si nécessaire
            game.is_active = False
            game.is_finish = True
            game.is_finals = False
            game.save()
            
            # Autres opérations nécessaires, comme notifier l'autre joueur
            # par exemple, envoyer un message sur un canal ou groupe
            
        except Game.DoesNotExist:
            pass  # Gérer si le jeu n'est pas trouvé ou d'autres erreurs

    
    @database_sync_to_async
    def stay_in_game_finals(self, id):
        from django.contrib.auth import get_user_model
        User = get_user_model()
        user = User.objects.get(id=id)
        user.is_online = 2
        user.save()

    @database_sync_to_async
    def check_is_good_player(self, user):
        from rest_framework_simplejwt.exceptions import InvalidToken, TokenError
        try:
            game = self.get_player_1
            if user.username == game.player_1:
                return True
            else:
                return False
        except (InvalidToken, TokenError) as e:
            return False

    
    @database_sync_to_async
    def create_player_one(self, room_name, id):
        try:
            # Récupérer le jeu en cours pour ce canal
            from .models import Game
            game = Game.objects.get(game_name=room_name)

            if game.player_1 is None:
                from django.contrib.auth import get_user_model
                User = get_user_model()
                user = User.objects.get(id=id)
                game.player_1 = user
                game.player_1_username = id
                game.save()
                return True
            else:
                return False 
        except Game.DoesNotExist:
            pass  # Gérer si le jeu n'est pas trouvé ou d'autres erreurs

    async def check_game(self, token, room_name):
        from rest_framework_simplejwt.exceptions import InvalidToken, TokenError
        try:
            from rest_framework_simplejwt.tokens import UntypedToken
            valid_token = UntypedToken(token)
            user_id = valid_token.get('user_id')
        except (InvalidToken, TokenError) as e:
            return False
        user = await self.get_user_by_id(user_id)
        game = await self.get_game(room_name)
        if game is False:
            return False
        allowed_users = await self.get_allowed_users(game)
        if user in allowed_users:
            return True
        else:
            return False
    
    @database_sync_to_async
    def check_semifinals_finals(self, room_name):
        try:
            # Récupérer le jeu en cours pour ce canal
            from .models import Game
            game = Game.objects.get(game_name=room_name)

            if game.is_semifinals:
                return True
            elif game.is_finals:
                return False
            else:
                return False
            
        except Game.DoesNotExist:
            pass  # Gérer si le jeu n'est pas trouvé ou d'autres erreurs
    
    @database_sync_to_async
    def verify_if_finals_is_possible(self, room_name):
        from .models import Game
        try:
            from .models import Name_Tournaments_Game
            game_one = Game.objects.get(game_name=room_name)
            try:
                game_two = Name_Tournaments_Game.objects.get(semi_finals_one=game_one.other_semi_finals_name)
                if game_two.is_deconnect == True:
                    return False
                else:
                    return True
            except Name_Tournaments_Game.DoesNotExist:
                game_two = Name_Tournaments_Game.objects.get(semi_finals_two=game_one.other_semi_finals_name)
                if game_two.is_deconnect == True:
                    return False
                else:
                    return True
        except Game.DoesNotExist:
            game_two = Game.objects.get(game_name=room_name)
            try:
                game_one = Name_Tournaments_Game.objects.get(semi_finals_one=game_two.other_semi_finals_name)
                if game_one.is_deconnect == True:
                    return False
                else:
                    return True
            except Name_Tournaments_Game.DoesNotExist:
                game_one = Name_Tournaments_Game.objects.get(semi_finals_two=game_two.other_semi_finals_name)
                if game_one.is_deconnect == True:
                    return False
                else:
                    return True

    @database_sync_to_async
    def deconnect_for_semi_and_finals(self, room_name):
        from .models import Game
        try:
            from .models import Name_Tournaments_Game
            name_tournaments_one = Name_Tournaments_Game.objects.get(semi_finals_one=room_name)
            name_tournaments_one.is_deconnect = True
            name_tournaments_one.save()
        except Name_Tournaments_Game.DoesNotExist:
            name_tournaments_two = Name_Tournaments_Game.objects.get(semi_finals_two=room_name)
            name_tournaments_two.is_deconnect = True
            name_tournaments_two.save()

    
    @database_sync_to_async
    def check_if_finals_is_possible_game_one(self, room_name):
        from .models import Game
        try:
            from .models import Name_Tournaments_Game
            name_tournaments = Name_Tournaments_Game.objects.get(semi_finals_two=room_name)
            if name_tournaments.is_deconnect == True:
                return False
            return True
        except Name_Tournaments_Game.DoesNotExist:
            return 2
    
    @database_sync_to_async
    def check_if_finals_is_possible_game_two(self, room_name):
        from .models import Game
        try:
            from .models import Name_Tournaments_Game
            name_tournaments = Name_Tournaments_Game.objects.get(semi_finals_two=room_name)
            if name_tournaments.is_deconnect == True:
                return False
            return True
        except Name_Tournaments_Game.DoesNotExist:
            return 2
    
    @database_sync_to_async
    def check_name_finals_one(self, room_name):
        from .models import Game
        try:
            from .models import Name_Tournaments_Game
            name_tournaments = Name_Tournaments_Game.objects.get(semi_finals_one=room_name)
            finale = name_tournaments.finals
            return finale
        except Name_Tournaments_Game.DoesNotExist:
            name_tournaments = Name_Tournaments_Game.objects.get(semi_finals_two=room_name)
            finale = name_tournaments.finals
            return finale
    

    @database_sync_to_async
    def check_winner(self, room_name):
        try:
            from .models import Game
            game = Game.objects.get(game_name=room_name)

            if game.score_player_2 <  game.score_player_1:
                return game.player_1.username
            else:
                return game.player_2.username
        except Game.DoesNotExist:
            pass
    
    @database_sync_to_async
    def check_winner_id(self, room_name, other_id):
        try:
            from .models import Game
            game = Game.objects.get(game_name=room_name)

            if self.game_state[self.room_name]['scores'][self.user.id] < self.game_state[self.room_name]['scores'][other_id]:
                return other_id
            else:
                return self.user.id
        except Game.DoesNotExist:
            pass

    @database_sync_to_async
    def check_looser_id(self, room_name, other_id):
        try:
            from .models import Game
            game = Game.objects.get(game_name=room_name)

            if self.game_state[self.room_name]['scores'][self.user.id] < self.game_state[self.room_name]['scores'][other_id]:
                return self.user.id
            else:
                return other_id
        except Game.DoesNotExist:
            pass
    
    @database_sync_to_async
    def cancel_finals(self, finals, room_name):
        from .models import Game
        game = Game.objects.get(game_name=room_name)
        if finals == False:
            finals = Game.objects.get(game_name=game.other_finals_name)
            finals.is_active = False
            finals.is_finish = True
            finals.save()
    
    @database_sync_to_async
    def check_network_problem(self, room_name, user_id):
        print(f"Je ne suis pas encore rentre dans les condition de network_problem mais mon id est {self.user.id}")
        if self.game_state[room_name]['network_problem_first'] == False:
            self.game_state[room_name]['network_problem_first'] = True
            return False
        if self.game_state[room_name]['network_problem'][user_id] == False:
            print(f"Je suis le jouers {user_id} et je suis dans la fonction check_network_problem")
            self.game_state[room_name]['network_problem'][user_id] = True
            self.game_state[room_name]['network_problem_int'][0] += 1
        print(f"La valeur de network_problem_int est de {self.game_state[room_name]['network_problem_int']}")
        if self.game_state[room_name]['network_problem_int'][0] >= 2:
            return True
        else:
            return False
    #------------------------------------------------------------------------------------
    #------------------------------------------------------- Gerer le tableau de room
    def add_user_to_room(self, room_name, user_id):
        if room_name not in self.rooms:
            self.rooms[room_name] = []
            self.game_state[room_name] = {
                'ball_position': [50, 50],
                'ball_velocity': [1, 1],
                'paddle_positions': { },
                'scores': {},
                'network_problem' : {},
                'network_problem_int' : [0, 0],
                'network_problem_first' : False,
                'game_is_over' : {}
            }
            self.game_message[room_name] = {
                'False': False
            }
            
        
        if user_id not in self.rooms[room_name]:
            self.rooms[room_name].append(user_id)
    
    def remove_user_from_room(self, room_name, user_id):
        if room_name in self.rooms and user_id in self.rooms[room_name]:
            self.rooms[room_name].remove(user_id)
        if len(self.rooms[room_name]) == 0:
            del self.rooms[room_name]
            del self.game_state[room_name]



    def get_room_info(self, room_name):
        num_users = len(self.rooms.get(room_name, []))
        return room_name, num_users
    
    def get_other_id_user(self, room_name):
        for user_id in self.rooms.get(room_name, []):
            if user_id != self.user.id:
                other_id = user_id
                break
        return other_id

    # def get_users_in_room(self, room_name):
    #     return self.rooms.get(room_name, [])
    

     #------------------------------------------------------------------------------------
     #------------------------------------------------------- Gerer la connect et deconnect et receive
    async def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_name']
        self.room_group_name = f'game_{self.room_name}'

        print("Juste connecte")
        # Parsing token
        query_string = self.scope.get('query_string', b'').decode()
        query_params = dict(param.split('=') for param in query_string.split('&') if '=' in param)
        self.token = query_params.get('token')
        if not self.token:
            await self.accept()
            await self.disconnect(1000)
            return
        print("Token bien verifier")
        # Check if the user is allowed to join the game and if game exist
        autorisation = await self.check_game(self.token, self.room_name)
        if not autorisation:
            await self.accept()
            await self.disconnect(1000)
            return
        print("Joueurs autorise a rejoindre")
        # Check if the game is active
        is_active = await self.verification_game_is_active(self.room_name)
        if not is_active:
            await self.accept()
            await self.disconnect(1000)
            return
        print("Game bien active")
        # # Attribution of the user to the game
        from rest_framework_simplejwt.tokens import UntypedToken
        valid_token = UntypedToken(self.token)
        user_id = valid_token.get('user_id')
        self.user = await self.get_user_by_id(user_id)
        print("Attribution bien realise")

        # Attribuate player_one and player_two
        player_one = await self.put_player_one_and_player_two(self.room_name, self.user.id)
        if player_one is True:
            print("Creation d'un jouers numero 1")
        else:
            print("Pas de creation d'un jouers numero 1")
        self.connected_users[self.user.id] = self.channel_name
        await self.channel_layer.group_add(self.room_group_name, self.channel_name)
        self.scope['user'] = self.user
        self.add_user_to_room(self.room_name, self.user.id)
        await self.accept()
        await asyncio.sleep(5)

        if len(self.rooms[self.room_name]) < 2:
            print("Manque jouers")
            await self.send(text_data=json.dumps({"ready": 'False', "message": 'Not enough to play'}))
            await self.disconnect(1000, True)
            pass
        else:
            self.game_error = False
            await self.send(text_data=json.dumps({"ready": 'True', "message": 'Good'}))
            self.game_state[self.room_name]['paddle_positions'][self.user.id] = 0
            self.game_state[self.room_name]['scores'][self.user.id] = 0
            self.game_state[self.room_name]['network_problem'][self.user.id] = False
            self.game_state[self.room_name]['game_is_over'][self.user.id] = False
            self.game_running = True
            self.game_deconnect = False
            print("Tout est bon")
            self.game_loop_timer = asyncio.create_task(self.game_loop())
            self.game_timer_timer = asyncio.create_task(self.game_timer())

    async def disconnect(self, close_code=1000, custom_param=False):
        if custom_param:
            print("Ca rentre dans une deconnexion normale")
            is_semifinals_or_finals = await self.check_semifinals_finals(self.room_name)
            if is_semifinals_or_finals == True:
                finals_possible = await self.verify_if_finals_is_possible(self.room_name)
                if finals_possible == True:
                    await self.update_game_on_disconnect(self.user.username, self.user.id)
                    other_id = self.get_other_id_user(self.room_name)
                    winner_id = await self.check_winner_id(self.room_name, other_id)
                    looser_id = await self.check_looser_id(self.room_name, other_id)
                    name_finals = await self.check_name_finals_one(self.room_name)
                    if self.user.id == winner_id:
                            await self.channel_layer.send(
                            self.connected_users[winner_id],
                            {
                                'type': 'winner',
                                'status': 'Skip',
                                'final_code': name_finals,
                            })
                            await self.stay_in_game_finals(self.user.id)
                    if self.user.id == looser_id:
                        await self.channel_layer.send(
                            self.connected_users[looser_id],
                                {
                                    'type': 'game_over',
                                    'ready': 'False',
                                    'message': 'Game is over !',
                                }
                        )
                else:
                    await self.update_game_on_disconnect(self.user.username, self.user.id)
                    await self.channel_layer.send(
                        self.connected_users[self.user.id],
                        {
                            'type': 'game_over',
                            'ready': 'False',
                            'message': 'The disconnection of some players resulted in the cancellation of the tournament or the game.'
                        }
                    )    
            else:
                await self.update_game_on_disconnect(self.user.username, self.user.id)
                await self.channel_layer.send(
                    self.connected_users[self.user.id],
                        {
                            'type': 'game_over',
                            'ready': 'False',
                            'message': 'Game is finish !',
                        }
                )
            # self.remove_user_from_room(self.room_name, self.user.id)
            await self.channel_layer.group_discard(self.room_group_name, self.channel_name)
            self.reset_game()
            self.game_deconnect = True
        else:
            if self.game_error:
                print("Authorisation manquante")
            else:
                if self.game_deconnect == False:
                    print("Ca rentre dans deconnexion subite")
                    is_semifinals_or_finals = await self.check_semifinals_finals(self.room_name)
                    if is_semifinals_or_finals == True:
                        await self.deconnect_for_semi_and_finals(self.room_name)
                        self.finals_poss = await self.verify_if_finals_is_possible(self.room_name)
                        await self.cancel_finals(self.finals_poss, self.room_name)
                    other_id = self.get_other_id_user(self.room_name)
                    if other_id is not None:
                        await self.update_game_on_disconnect(self.user.username, other_id)
                    await self.channel_layer.send(
                        self.connected_users[self.user.id],
                        {
                            'type': 'game_over',
                            'ready': 'False',
                            'message': 'The disconnection of some players resulted in the cancellation of the tournament or the game.'
                        }
                    )
                    await self.channel_layer.send(
                        self.connected_users[other_id],
                        {
                            'type': 'game_over',
                            'ready': 'False',
                            'message': 'The disconnection of some players resulted in the cancellation of the tournament or the game.',
                        }
                    )

                    # self.remove_user_from_room(self.room_name, self.user.username)
                    await self.channel_layer.group_discard(self.room_group_name, self.channel_name)
                    await self.update_game_on_disconnect(self.user.username, self.user.id)
                self.reset_game()
        if hasattr(self, 'game_loop_timer'):
            self.game_loop_timer.cancel()
        if hasattr(self, 'game_timer_timer'):
            self.game_timer_timer.cancel()
        if hasattr(self, 'game_timer_task'):
            self.game_timer_task.cancel()
        self.game_state[self.room_name]['game_is_over'][self.user.id] = True
        await asyncio.sleep(0.5)
        await self.close(close_code)


    async def receive(self, text_data):
        try:
            other_id = None
            data = json.loads(text_data)
            if data['type'] == 'paddle_position':
                paddle_position = data['data']['paddle_position']
                if paddle_position <= 80:
                    self.game_state[self.room_name]['paddle_positions'][self.user.id] = paddle_position
                other_id = self.get_other_id_user(self.room_name)
                if other_id is not None:
                    await self.channel_layer.send(
                        self.connected_users[other_id],
                        {
                            'type': 'send_message',
                            'paddle_position': paddle_position
                        }
                    )
            else: 
                print("Error")
        except Exception as e:
            print(e)
            pass
    #------------------------------------------------------------------------------------
    #------------------------------------------------------- Gerer message du jeux
    async def send_game_state(self):
        other_id = self.get_other_id_user(self.room_name)
        if other_id != self.user.id:
            ball_position = self.game_state[self.room_name]['ball_position'].copy()

            ball_position[0] -= 50

            ball_position[0] = 50 - ball_position[0]
            await self.channel_layer.send(
                self.connected_users[other_id],
                {
                    'type': 'send_game',
                    'ball_position': ball_position,
                    'scores_me': self.game_state[self.room_name]['scores'][other_id],
                    'scores_ennemies': self.game_state[self.room_name]['scores'][self.user.id],
                }
            )
        await self.channel_layer.send(
            self.connected_users[self.user.id],
            {
                'type': 'send_game',
                'ball_position': self.game_state[self.room_name]['ball_position'],
                'scores_me': self.game_state[self.room_name]['scores'][self.user.id],
                'scores_ennemies': self.game_state[self.room_name]['scores'][other_id],
            }
        )

    async def send_game(self, event):
        ball_position = event['ball_position']
        scores_me = event['scores_me']
        scores_ennemies = event['scores_ennemies']
        await self.send(text_data=json.dumps({
            'ball_position': ball_position,
            'scores_me': scores_me,
            'scores_ennemies': scores_ennemies,
        }))

    async def send_message(self, event):
        message = event['paddle_position']
        await self.send(text_data=json.dumps({
            'paddle_position': message,
        }))

    async def game_over(self, event):
        status = event['ready']
        mes = event['message']
        await self.send(text_data=json.dumps({
            'ready': status,
            'message' : mes,
        }))
    
    async def winner(self, event):
        status = event['status']
        final_code = event['final_code']
        await self.send(text_data=json.dumps({
            'status': status,
            'final_code' : final_code,
        }))
    
    #------------------------------------------------------------------------------------
    # ------------------------------------------------------- Gestion du jeux
    async def update_ball_position(self):
        ball_x, ball_y = self.game_state[self.room_name]['ball_position']
        ball_dx, ball_dy = self.game_state[self.room_name]['ball_velocity']

        # Update ball position
        ball_x += ball_dx
        ball_y += ball_dy

        # Check for collision with top and bottom walls
        if ball_y <= 0 or ball_y >= 100:
            ball_dy = -ball_dy
        
        paddle_hit = False
        # other_id = self.get_other_id_user(self.room_name)
        for user_id in self.rooms.get(self.room_name, []):
            if user_id != self.user.id:
                other_id = user_id
                break

        random_factor = 0.5
        if ball_x < 2 and ball_x > 0:
            if self.game_state[self.room_name]['paddle_positions'][self.user.id] <= ball_y <= self.game_state[self.room_name]['paddle_positions'][self.user.id] + 20:
                ball_dx = -ball_dx + random.uniform(-random_factor, random_factor)
                paddle_hit = True
        elif ball_x >= 99 and ball_x < 100:
            if self.game_state[self.room_name]['paddle_positions'][other_id] <= ball_y <= self.game_state[self.room_name]['paddle_positions'][other_id] + 20:
                ball_dx = -ball_dx + random.uniform(-random_factor, random_factor)
                paddle_hit = True

        self.game_state[self.room_name]['ball_position'] = [ball_x, ball_y]
        self.game_state[self.room_name]['ball_velocity'] = [ball_dx, ball_dy]

        if ball_x <= 0 and not paddle_hit:
            self.game_state[self.room_name]['scores'][other_id] += 1
            self.reset_ball()
        elif ball_x >= 100 and not paddle_hit:
            self.game_state[self.room_name]['scores'][self.user.id] += 1
            self.reset_ball()

    def reset_ball(self):
        self.game_state[self.room_name]['ball_position'] = [50, 50]
        self.game_state[self.room_name]['ball_velocity'] = [1, 1]

    async def game_loop(self):
        while self.game_running:
            print(f"Dans la bouvle game_loop, je suis le  {self.user.id}")
            probleme = await self.check_network_problem(self.room_name, self.user.id)
            if probleme == True:
                await self.disconnect(1000)
            await self.update_ball_position()
            await self.send_game_state()
            await asyncio.sleep(0.03)

    async def game_timer(self):
        self.game_timer_task = asyncio.create_task(asyncio.sleep(15))  # Création de la tâche du timer
        await self.game_timer_task  # Attente de la fin du timer

        self.game_running = False
        # self.reset_game()  # Réinitialisation du jeu si le timer se termine
        try:
            await asyncio.sleep(0.5)
            await self.disconnect(1000, True)
        except Exception as e:
            print(f"Erreur lors de la déconnexion : {e}")

    def reset_game(self):
        # Réinitialisation de l'état du jeu
        self.game_state['ball_position'] = [50, 50]
        self.game_state['ball_velocity'] = [1, 1]
        self.game_state['paddle_positions'] = {}
        self.game_state['scores'] = {}
        self.game_running = False
        self.game_deconnect = True




class NotificationConsumer(AsyncWebsocketConsumer):

    from channels.db import database_sync_to_async
    @database_sync_to_async
    def put_online(self, id):
        from django.contrib.auth import get_user_model
        User = get_user_model()
        user = User.objects.get(id=id)
        user.is_online = 1
        user.save()

    from channels.db import database_sync_to_async
    @database_sync_to_async
    def get_user_by_id(self, user_id):
        from django.contrib.auth import get_user_model
        User = get_user_model()
        try:
            user = User.objects.get(id=user_id)
            return user
        except User.DoesNotExist:
            return None

    async def connect(self):
        self.username = self.scope['url_route']['kwargs']['username']
        self.group_name = f'user_{self.username}'
    
        query_string = self.scope.get('query_string', b'').decode()
        query_params = dict(param.split('=') for param in query_string.split('&') if '=' in param)
        self.token = query_params.get('token')
        if not self.token:
            await self.disconnect(1000)
        from rest_framework_simplejwt.exceptions import InvalidToken, TokenError
        try:
            from rest_framework_simplejwt.tokens import UntypedToken
            valid_token = UntypedToken(self.token)
            self.user_id = valid_token.get('user_id')
            user = await self.get_user_by_id(self.user_id)
            if f"user_{user.username}" == self.group_name:
                pass
            else:
                await self.disconnect()
        except (InvalidToken, TokenError) as e:
            await self.disconnect(1000)
        
        await self.channel_layer.group_add(
            self.group_name,
            self.channel_name
        )
        await self.put_online(self.user_id)
        await self.accept()

    async def disconnect(self, cclose_code=1000):
        await self.channel_layer.group_discard(
            self.group_name,
            self.channel_name
        )

    async def receive(self, text_data):
        pass

    async def send_notifications_information(self, event):
        text = event['text']
        boole = event['bool']
        await self.send(text_data=json.dumps({
            'information': text,
            'bool': boole
        }))
    
    async def send_notifications_confirmation(self, event):
        text = event['text']
        await self.send(text_data=json.dumps({
            'confirmation': text
        }))

    async def send_notifications_no_display(self, event):
        text = event['text']
        boole = event['bool']
        await self.send(text_data=json.dumps({
            'no-display': text,
            'bool': boole
        }))
