# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthea <mthea@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 09:06:02 by mthea             #+#    #+#              #
#    Updated: 2023/08/21 12:42:02 by mthea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-----------------VARIABLES------------------
#--------------------------------------------
# VARIABLES FOR DOT C
MINISHELL = ft_alloc/ft_alloc_all.c \
			ft_builtins/ft_if_or_not_builtins.c ft_builtins/ft_builtins_pwd.c ft_builtins/ft_builtins_env.c ft_builtins/ft_if_or_not_builtins_bis.c \
			ft_builtins/ft_builtins_export.c ft_builtins/ft_builtins_export_two.c ft_builtins/ft_builtins_unset.c ft_builtins/ft_builtins_export_three.c \
			ft_builtins/ft_builtins_echo.c ft_builtins/ft_builtins_cd.c ft_builtins/ft_builtins_cd_bis.c ft_builtins/ft_builtins_cd_three.c ft_builtins/ft_builtins_cd_four.c \
			ft_builtins/ft_builtins_exit.c ft_builtins/ft_builtins_echo_bis.c\
			ft_env/ft_for_env.c \
			ft_parsing/alloc_nmbr_line_bis.c ft_parsing/alloc_nmbr_line_ter.c ft_parsing/alloc_nmbr_line.c ft_parsing/parsing_bis.c \
			 ft_parsing/parsing.c ft_parsing/push_to_tab_bis.c  ft_parsing/push_to_tab_ter.c ft_parsing/push_to_tab.c\
			ft_parsing/signal.c ft_parsing/utils.c ft_parsing/quater.c\
			ft_parsing/verification_bis.c ft_parsing/verification.c \
			ft_utils/ft_split.c ft_utils/ft_utils.c ft_utils/ft_free_mini.c \
			ft_redirection_pipes/ft_redirection_pipes.c ft_redirection_pipes/ft_pipelines.c ft_redirection_pipes/ft_redirection_pipes_three.c ft_redirection_pipes/ft_redirection_pipes_four.c\
			ft_redirection_pipes/ft_redirection_pipes_two.c  ft_redirection_pipes/ft_pipelines_two.c \
			main.c
#--------------------------------------------
# VARIABLES FOR DOT O
MINISHELL_OBJ = $(MINISHELL:.c=.o)
#--------------------------------------------
# VARIABLES FOR DO A COMPILATION
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = -L /Users/$$USER/.brew/Cellar/readline/8.2.1/lib -l readline
INC = -I /Users/$$USER/.brew/Cellar/readline/8.2.1/include
NAME	= minishell
RM = rm -rf
#--------------------------------------------
#-----------------EXECUTING------------------
#--------------------------------------------
all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(INC) -g

$(NAME) : $(MINISHELL_OBJ)
	$(CC) $(CFLAGS) $(MINISHELL_OBJ) $(LIB) -o $(NAME)

clean :
	$(RM) $(MINISHELL_OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
#--------------------------------------------
