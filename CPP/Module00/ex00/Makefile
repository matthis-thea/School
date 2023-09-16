# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthea <mthea@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 10:08:47 by mthea             #+#    #+#              #
#    Updated: 2023/08/29 10:08:48 by mthea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
MEGAPHONE = megaphone.cpp
# VARIABLES FOR DOT O
MEGAPHONE_OBJ = $(MEGAPHONE:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)

$(NAME) : $(MEGAPHONE_OBJ)
	$(CC) $(CFLAGS) $(MEGAPHONE_OBJ) -o $(NAME)

clean :
	$(RM) $(MEGAPHONE_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
