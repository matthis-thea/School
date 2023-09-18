# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haze <haze@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 03:13:11 by haze              #+#    #+#              #
#    Updated: 2023/09/18 03:13:34 by haze             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
CLAPTRAP = main.cpp
# VARIABLES FOR DOT O
CLAPTRAP_OBJ = $(CLAPTRAP:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = polymorphism
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)
%.o : %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@
$(NAME) : $(CLAPTRAP_OBJ)
	$(CC) $(CXXFLAGS) $(CLAPTRAP_OBJ) -o $(NAME)

clean :
	$(RM) $(CLAPTRAP_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------