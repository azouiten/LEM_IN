# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 15:34:34 by ohachim           #+#    #+#              #
#    Updated: 2019/12/18 14:47:43 by azouiten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
   
SRC_PATH = src
   
SRC_NAME = ft_abs.c  \
               ft_arylen.c \
               ft_atoi.c \
               ft_atoi_base.c \
               ft_bi_add.c \
               ft_bi_mult.c \
               ft_bi_rep.c \
               ft_bzero.c \
               ft_chareplace.c \
               ft_check_neg.c \
               ft_cnv_hex.c \
               ft_cnv_hex_u.c \
               ft_construct_s.c \
               ft_countlst.c \
               ft_craadd.c \
               ft_cstrlen.c \
               ft_div_one.c \
               ft_dreplace.c \
               ft_field_width.c \
               ft_finish_fract.c \
               ft_flagge_rino.c \
               ft_frexp.c \
               ft_fw_left.c \
               ft_fw_right.c \
               ft_isalnum.c \
               ft_isalpha.c \
               ft_isascii.c \
               ft_isdigit.c \
               ft_isprint.c \
               ft_itoa.c \
               ft_itoa_imp.c \
               ft_itoa_imp_u.c \
               ft_lstadd.c \
               ft_lstdel.c \
               ft_lstdelone.c \
               ft_lstiter.c \
               ft_lstmap.c \
               ft_lstnew.c \
               ft_make_ldouble.c \
               ft_make_s.c \
               ft_memalloc.c \
               ft_memccpy.c \
               ft_memchr.c \
               ft_memcmp.c \
               ft_memcpy.c \
               ft_memdel.c \
               ft_memmove.c \
               ft_memset.c \
               ft_normalize.c \
               ft_plstcont.c \
               ft_precision.c \
               ft_print_adressp.c \
               ft_print_bonus.c \
               ft_print_char.c \
               ft_print_float.c \
               ft_print_grbg.c \
               ft_print_int.c \
               ft_print_octal.c \
               ft_print_percent.c \
               ft_print_str.c \
               ft_print_uns_hex_low.c \
               ft_print_uns_hex_up.c \
               ft_print_unsigned.c \
               ft_printf.c \
               ft_putchar.c \
               ft_putchar_fd.c \
               ft_putchar_rem.c \
               ft_putendl.c \
               ft_putendl_fd.c \
               ft_putnbr.c \
               ft_putnbr_fd.c \
               ft_putstr.c \
               ft_putstr_fd.c \
               ft_putstr_imp_fd.c \
               ft_putstr_rem.c \
               ft_round_it.c \
               ft_scan_flag.c \
               ft_simpleop.c \
               ft_special_n.c \
               ft_strcat.c \
               ft_strccpy.c \
               ft_strchr.c \
               ft_strclr.c \
               ft_strcmp.c \
               ft_strcpy.c \
               ft_strcpyc.c \
               ft_strdel.c \
               ft_strdup.c \
               ft_strequ.c \
               ft_striter.c \
               ft_striteri.c \
               ft_strjoin.c \
               ft_strlcat.c \
               ft_strlen.c \
               ft_strlenc.c \
               ft_strmap.c \
               ft_strmapi.c \
               ft_strncat.c \
               ft_strncmp.c \
               ft_strncpy.c \
               ft_strndup.c \
               ft_strnequ.c \
               ft_strnew.c \
               ft_strnstr.c \
               ft_strpos.c \
               ft_strrchr.c \
               ft_strsplit.c \
               ft_strstr.c \
               ft_strsub.c \
               ft_strsubn.c \
               ft_strtrim.c \
               ft_swpdress.c \
               ft_to_bi.c \
               ft_tolower.c \
               ft_toupper.c \
               ft_zero_scp.c \
               get_next_line.c \
	       ft_skip_line.c

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS = -Iinclude

NAME = libft.a

DEPS = include/libft.h

CC = gcc

CFLAGS = -Werror -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -vf $(NAME)

re: fclean all
