#VARIABLES
NAME = libftprintf.a

SRC = ft_printf.c ft_void_percent.c ft_string_letters.c ft_numbers_base_ten.c ft_numbers_base_sixteen.c ft_external_functions.c

OBJ = $(SRC:.c=.o) 

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -rf

OBJ = $(SRC:.c=.o) 

#-------------------------------
#INSTRUCTIONS
all : $(NAME)

$(NAME) : $(OBJ)
	 ar -crs $(NAME) $(OBJ)
	
clean :
	$(RM) $(OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
