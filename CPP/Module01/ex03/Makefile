# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haze <haze@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 08:40:42 by mthea             #+#    #+#              #
#    Updated: 2023/09/05 14:26:15 by haze             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
WEAPON = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
# VARIABLES FOR DOT O
WEAPON_OBJ = $(WEAPON:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = weapon
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)

$(NAME) : $(WEAPON_OBJ)
	$(CC) $(CXXFLAGS) $(WEAPON_OBJ) -o $(NAME)

clean :
	$(RM) $(WEAPON_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
