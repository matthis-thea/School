# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thib <thib@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 11:51:44 by tserdet           #+#    #+#              #
#    Updated: 2023/11/17 14:32:59 by thib             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
SRC = Bureaucrat.cpp AForm.cpp main.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp\
 PresidentialPardonForm.cpp Intern.cpp
# VARIABLES FOR DOT O
SRC_OBJ = $(SRC:.cpp=.o)
# VARIABLES FOR DO A COMPILATION
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bureaucrat
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)

$(NAME) : $(SRC_OBJ)
	$(CC) $(CXXFLAGS) $(SRC_OBJ) -o $(NAME)

clean :
	$(RM) $(SRC_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
