#-----------------MAKEFILE------------------
#--------------------------------------------
# VARIABLES FOR DOT C

TEST = ft_verification_conversion/ft_verification.c ft_verification_conversion/ft_conversion.c ft_verification_conversion/ft_alloc.c\
	ft_verification_conversion/ft_alloc2.c ft_verification_conversion/ft_move.c ft_verification_conversion/ft_split.c \
	ft_verification_conversion/ft_verification_bis.c ft_verification_conversion/utils.c ft_verification_conversion/ft_move2.c\
	ft_verification_conversion/ft_main.c ft_verification_conversion/ft_move3.c \

FT_PRINTF	= ft_printf/ft_printf.c ft_printf/ft_void_percent.c ft_printf/ft_string_letters.c \
				ft_printf/ft_numbers_base_ten.c ft_printf/ft_numbers_base_sixteen.c ft_printf/ft_external_functions.c \


#--------------------------------------------
# VARIABLES FOR DOT O
TEST_OBJ = $(TEST:.c=.o)
FT_PRINTF_OBJ = $(FT_PRINTF:.c=.o)
#--------------------------------------------
# VARIABLES FOR DO A COMPILATION
CC = gcc 

CFLAGS = -Wall -Werror -Wextra

NAME	=	push_swap

RM = rm -rf

#-----------------EXECUTING------------------
#--------------------------------------------

all : $(NAME)


$(NAME) : $(TEST_OBJ) $(FT_PRINTF_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(FT_PRINTF_OBJ) -o $(NAME)

clean :
	$(RM) $(TEST_OBJ) $(FT_PRINTF_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------