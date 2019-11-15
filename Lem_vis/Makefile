# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 02:54:22 by ohachim           #+#    #+#              #
#    Updated: 2019/11/13 13:50:04 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME = ft_get_input.c \
	   ft_append_vertex.c \
	   ft_create_data.c \
	   ft_create_edges.c \
	   ft_create_hash.c \
	   ft_parse.c \
	   ft_extract_name.c \
	   ft_extract_edge.c \
	   ft_extract_connection.c \
	   ft_check_validity.c \
	   ft_error_input.c \
	   ft_hash_it.c \
	   ft_initialize_hdata.c \
	   ft_free_data.c \
	   ft_visualize.c \
	   ft_init_visualization.c \
	   ft_draw_edges.c \
	   ft_draw_rooms.c \
	   ft_copy_ants.c \
	   ft_draw_ants.c \
	   ft_braze_red.c \
	   ft_get_events.c \
	   ft_normalize_vertices.c \
	   ft_zoom.c \
	   ft_load_texture.c \
	   ft_draw_menu.c \
	   ft_init_ants.c \
	   ft_navigate.c

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LDFLIBS = -L /Users/$(USER)/.brew/Cellar/sdl2/2.0.9_1/lib -lSDL2-2.0.0 -lSDL2 \
	  -L /Users/$(USER)/.brew/Cellar/sdl2_image/2.0.5/lib -lSDL2_image \
	  -lSDL2_image-2.0.0 \
	  -L libft -lft


CPPFLAGS = -I /Users/$(USER)/.brew/Cellar/sdl2_image/2.0.5/include/SDL2 \
	   -I /Users/$(USER)/.brew/Cellar/sdl2/2.0.9_1/include/SDL2 \
	   -I include \
	   -I libft/include \

CC = gcc

CFLAGS = #-Wall -Werror -Wextra

NAME = visu_lem_in

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft ; make
	$(CC) $(LDFLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@rm -vf $(NAME)

re: fclean all
