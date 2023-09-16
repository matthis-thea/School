# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haze <haze@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 08:40:42 by mthea             #+#    #+#              #
#    Updated: 2023/09/03 13:22:57 by haze             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
SEDD = main.cpp fileA.cpp
# VARIABLES FOR DOT O
SED_OBJ = $(SEDD:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = sed
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)

$(NAME) : $(SED_OBJ)
	$(CC) $(CFLAGS) $(SED_OBJ) -o $(NAME)

clean :
	$(RM) $(SED_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
