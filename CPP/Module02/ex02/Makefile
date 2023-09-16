# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haze <haze@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 21:11:22 by haze              #+#    #+#              #
#    Updated: 2023/09/08 21:11:25 by haze             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
FIXED = main.cpp Fixed.cpp
# VARIABLES FOR DOT O
FIXED_OBJ = $(FIXED:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fixed
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)
%.o : %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@
$(NAME) : $(FIXED_OBJ)
	$(CC) $(CXXFLAGS) $(FIXED_OBJ) -o $(NAME)

clean :
	$(RM) $(FIXED_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
