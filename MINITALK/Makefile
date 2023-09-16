# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthea <mthea@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 09:06:02 by mthea             #+#    #+#              #
#    Updated: 2022/12/16 10:51:57 by mthea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
SERVER		=	ft_server/ft_server.c

CLIENT		=	ft_client/ft_client.c

FT_PRINTF	= ft_printf/ft_printf.c ft_printf/ft_void_percent.c ft_printf/ft_string_letters.c \
				ft_printf/ft_numbers_base_ten.c ft_printf/ft_numbers_base_sixteen.c ft_printf/ft_external_functions.c \

#--------------------------------------------
# VARIABLES FOR DOT O
SERVER_OBJ = $(SERVER:.c=.o)

CLIENT_OBJ = $(CLIENT:.c=.o)

FT_PRINTF_OBJ = $(FT_PRINTF:.c=.o)
#--------------------------------------------
# VARIABLES FOR DO A COMPILATION
CC = gcc 

CFLAGS = -Wall -Werror -Wextra 

EXEC_SERVER	=	server

EXEC_CLIENT	=	client

RM = rm -rf

#-----------------EXECUTING------------------
#--------------------------------------------

all : $(EXEC_SERVER) $(EXEC_CLIENT)

$(EXEC_SERVER) : $(FT_PRINTF_OBJ) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(FT_PRINTF_OBJ) $(SERVER_OBJ) -o $(EXEC_SERVER)

$(EXEC_CLIENT) : $(FT_PRINTF_OBJ) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(FT_PRINTF_OBJ) $(CLIENT_OBJ) -o $(EXEC_CLIENT)


clean :
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(FT_PRINTF_OBJ)

fclean :	clean
	$(RM) $(EXEC_SERVER) $(EXEC_CLIENT)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
