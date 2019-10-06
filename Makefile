# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <ohachim@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 13:47:22 by ohachim           #+#    #+#              #
#    Updated: 2019/10/06 11:24:29 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME = ft_lem_in.c \
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
	   ft_initialize_hdata.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS =-Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

NAME = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

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