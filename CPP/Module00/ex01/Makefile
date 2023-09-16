# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthea <mthea@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 10:02:55 by mthea             #+#    #+#              #
#    Updated: 2023/08/29 09:39:04 by mthea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
PHONEBOOK = PhoneBook.cpp main.cpp Contact.cpp
# VARIABLES FOR DOT O
PHONEBOOK_OBJ = $(PHONEBOOK:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)

$(NAME) : $(PHONEBOOK_OBJ)
	$(CC) $(CFLAGS) $(PHONEBOOK_OBJ) -o $(NAME)

clean :
	$(RM) $(PHONEBOOK_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
