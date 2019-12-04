# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 13:47:22 by ohachim           #+#    #+#              #
#    Updated: 2019/12/04 15:12:48 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME = ft_get_input.c \
	ft_free_data.c \
	ft_create_data.c \
	ft_error_input.c \
	ft_create_hash.c \
	ft_append_vertex.c \
	ft_extract_name.c \
	ft_hash_it.c \
	ft_create_edges.c \
	ft_check_validity.c \
	ft_extract_edge.c \
	ft_extract_connection.c \
	ft_initialize_hdata.c \
	ft_parse.c \
	ft_add_queue.c \
	ft_unvisit.c \
	ft_print_moves.c \
	ft_qsort_group.c \
	ft_sort_result.c \
	ft_list_to_array.c \
	ft_exit.c \
	ft_add_flow.c \
	ft_flush_v.c \
	ft_collect_paths.c \
	ft_add_to_agroup.c \
	ft_enhance_groups.c \
	ft_swing_paths.c \
	ft_calibrate.c \
	ft_bfs.c \
	ft_rescore.c \
	ft_free_agroups.c \
	ft_free_queue.c \
	main.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS =-Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME) visu

visu:
	cd Lem_vis ; make
visur:
	cd Lem_vis ; make re
visuc:
	cd Lem_vis ; make clean
visufc:
	cd Lem_vis ; make fclean

$(NAME): $(OBJ)
	@cd libft ; make
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

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
