#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
MAIN = main.cpp Client/Client_Socket.cpp Utils_Server/Utils.cpp Channel/Channel.cpp Server/server.cpp \
		Commande/NICK.cpp Commande/PASS.cpp Commande/USER.cpp Commande/PONG.cpp Commande/TOPIC.cpp \
		Commande/Command_utils.cpp Commande/JOIN.cpp Commande/PART.cpp Commande/KICK.cpp Commande/PRIVMSG.cpp \
		Commande/MODE.cpp Commande/QUIT.cpp Commande/INVITE.cpp
# VARIABLES FOR DOT O
MAIN_OBJ = $(MAIN:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = irc
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)
%.o : %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@
$(NAME) : $(MAIN_OBJ)
	$(CC) $(CXXFLAGS) $(MAIN_OBJ) -o $(NAME)

clean :
	$(RM) $(MAIN_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------