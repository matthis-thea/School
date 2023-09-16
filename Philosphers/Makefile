# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haze <haze@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 09:06:02 by mthea             #+#    #+#              #
#    Updated: 2023/05/18 02:00:23 by haze             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
PHILOSOPHERS =	ft_parse.c ft_utils.c main.c ft_parse_2.c ft_philosophers.c ft_action.c ft_action_2.c
#--------------------------------------------
# VARIABLES FOR DOT O
PHILOSOPHERS_OBJ = $(PHILOSOPHERS:.c=.o)
#--------------------------------------------
# VARIABLES FOR DO A COMPILATION
CC = gcc 

CFLAGS = -Wall -Werror -Wextra -pthread 
# -fsanitize=thread -g

NAME	=	philo
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME) 

$(NAME) : $(PHILOSOPHERS_OBJ)
	$(CC) $(CFLAGS) $(PHILOSOPHERS_OBJ) -o $(NAME)

clean :
	$(RM) $(PHILOSOPHERS_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------