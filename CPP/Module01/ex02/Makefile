# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthea <mthea@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 08:13:07 by mthea             #+#    #+#              #
#    Updated: 2023/08/30 08:13:58 by mthea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
ZOMBIE = main.cpp
# VARIABLES FOR DOT O
ZOMBIE_OBJ = $(ZOMBIE:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = cerveau
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)

$(NAME) : $(ZOMBIE_OBJ)
	$(CC) $(CFLAGS) $(ZOMBIE_OBJ) -o $(NAME)

clean :
	$(RM) $(ZOMBIE_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
