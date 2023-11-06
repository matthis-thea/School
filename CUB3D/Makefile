# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 14:44:10 by thib              #+#    #+#              #
#    Updated: 2023/10/31 14:28:36 by tserdet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror
SRC	= 	Get_next_line/ft_get_next_line_utils.c  Get_next_line/ft_get_next_line.c \
		Parsing/ft_parsing_alloc.c \
		Parsing/ft_parsing.c Utils/ft_utils_bis.c Utils/ft_utils.c Utils/ft_parsing_utils.c \
		Parsing/ft_parsing_verif_elements_solo_bis.c Parsing/ft_parsing_verif_elements_solo.c Parsing/ft_parsing_verif_elements.c \
		Parsing/ft_parsing_verif_map_texture.c Parsing/ft_parsing_verif_map_texture_bis.c \
		Parsing/ft_parsing_flood_fill.c \
		Utils/ft_split.c \
		main.c\
		graphical/graph.c graphical/utils.c graphical/utils_rays.c graphical/graph_init.c graphical/draw_rays.c\
		graphical/v_h_check.c graphical/move.c\

OBJ	= $(SRC:.c=.o)

all : 		$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lm MLX42-C/libmlx42.a -I include -lglfw -L "/Users/tserdet/.brew/opt/glfw/lib/" -o $(NAME) -g

clean :
	rm -rf $(OBJ)

fclean :	clean
	rm -f $(NAME) cub3d

re :	fclean all

.PHONY :	all clean fclean re
