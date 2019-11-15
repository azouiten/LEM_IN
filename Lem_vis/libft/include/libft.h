/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:28:13 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 17:22:46 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 20
# define LD_BUFF_SIZE 64

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <string.h>

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

typedef	struct				s_rem
{
	int						cursor;
	char					pad;
	int						counter;
	int						fi_wi;
	int						precision;
	int						pref;
	char					*fg;
}							t_rem;

typedef struct				s_ld
{
	int						iexpo;
	char					*p_r;
	char					*one;
}							t_ld;

typedef struct				s_op
{
	char					*temp;
	int						tl;
	int						dupa;
	int						*counter;
	int						carry;
	int						clen1;
	int						clen2;
	int						lenc1;
	int						lenc2;
	int						len1;
	int						len2;
	int						dlen1;
	int						diff;
	int						rescn;
	int						ires;
	int						alloc;
	char					*mcarry;
	int						pnt;
}							t_op;

typedef struct				s_fdta
{
	int						len;
	int						lenc;
	int						clen;
	char					*zros;
	char					*temp;
}							t_fdta;
int							ft_strdel_imp(char ***as);
int							ft_abs(int n);
int							ft_atoi(const char *str);
int							ft_isalnum(int c);
int							ft_isalpha(int c);
int							ft_isascii(int c);
int							ft_isdigit(int c);
int							ft_isprint(int c);
int							ft_strcmp(const char *s1, const char *s2);
char						*ft_strdup(const char *s1);
size_t						ft_strlen(const char *str);
int							ft_strncmp(const char *s1, const char *s2
							, size_t n);
char						*ft_strstr(const char *hstk, const char *ndle);
int							ft_tolower(int c);
int							ft_toupper(int c);
char						*ft_strnstr(const char *haystack
							, const char *needle, size_t len);
void						ft_bzero(void *s, size_t n);
char						*ft_strcpy(char *dst, char const *src);
char						*ft_strncpy(char *dst, char const *src, size_t len);
char						*ft_strcat(char *s1, const char *s2);
void						*ft_memset(void	*b, int c, size_t len);
char						*ft_strncat(char *s1, char *s2, size_t n);
char						*ft_strchr(const char *s, int c);
void						ft_putchar(char c);
char						*ft_strrchr(const char *s, int c);
void						ft_putchar_fd(char c, int fd);
void						ft_putstr(char const *s);
void						ft_putnbr(int n);
void						ft_putnbr_fd(int n, int fd);
void						ft_putstr_fd(char const *s, int fd);
void						*ft_memcpy(void *dst, const void *src, size_t n);
void						*ft_memccpy(void *dst
							, const void *src, int c, size_t n);
void						*ft_memmove(void *dst, const void *src, size_t len);
void						*ft_memchr(const void *s, int c, size_t n);
void						*ft_memalloc(size_t size);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
void						ft_memdel(void **ap);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
void						ft_strclr(char *s);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s
							, void (*f)(unsigned int, char*));
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s
							, char (*f)(unsigned int, char));
int							ft_strequ(char const *s1, char const *s2);
int							ft_strnequ(char const *s1
							, char const *s2, size_t n);
char						*ft_strsub(char const *s
							, unsigned int start, size_t len);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
void						ft_putendl(char const *s);
void						ft_putendl_fd(char const *s, int fd);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s);
char						**ft_strsplit(char const *s, char c);
char						*ft_itoa(int n);
t_list						*ft_lstnew(void const *content
							, size_t content_size);
void						ft_lstdelone(t_list **alst
							, void (*del)(void*, size_t));
void						ft_lstdel(t_list **alst
							, void(*del)(void *, size_t));
void						ft_lstadd(t_list **alst, t_list *new);
void						ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list						*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void						ft_simpleop(int a, int b, char c);
void						ft_swpdress(char **s1, char **s2);
void						ft_plstcont(t_list *lst);
int							ft_countlst(t_list *list);
size_t						ft_strlenc(const char *s, char c);
char						*ft_dreplace(const char *s, char tor, char r);
char						*ft_strsubn(char *s, char c, char d);
char						*ft_craadd(char *s, char c);
char						*ft_strcpyc(char *dst, const char *src, char c);
char						*ft_strndup(char *src, char c);
int							get_next_line(const int fd, char **line);
int							ft_atoi_base(char *str, char *base);
double						ft_frexp(double value, int *expo);
void						ft_print_bonus(va_list arg, const char *format \
							, t_rem *rems, char type);
char						*ft_zero_scp(char **p_r);
char						*ft_bi_mult(char **m1, char **m2);
char						*ft_bi_add(char **a1, char **a2, int fre);
char						*ft_special_n(char **bi_fl, char fcm, int iexpo);
char						*ft_check_neg(char **bi_fl \
							, char **p_r, int ztrue);
char						*ft_round_it(char **p_r \
							, t_rem *rems);
size_t						ft_cstrlen(const char *str, char c);
char						*ft_div_one(long double twos \
							, long double one, long double start);
char						*ft_finish_fract(char **mantissa \
							, char **expo, int iexpo);
char						*ft_bi_rep(unsigned char *fl, int i);
char						*ft_make_ldouble(long double xtrct, int len);
void						ft_print_float(va_list arg \
							, const char *format, t_rem *rems);
char						*ft_to_bi(long long int dec);
char						*ft_normalize(char **sh);
void						ft_flagge_rino(t_rem *rems, char c, char b);
void						ft_print_percent(va_list arg \
							, const char *format, t_rem *rems);
void						ft_print_uns_hex_low(va_list arg \
							, const char *format, t_rem *rems);
char						*ft_cnv_hex_u(unsigned long long int num \
							, char spec);
void						ft_print_uns_hex_up(va_list arg \
							, const char *format, t_rem *rems);
void						ft_print_unsigned(va_list arg \
							, const char *format, t_rem *rems);
char						*ft_construct_s(char *conv \
							, const char *format, t_rem *rems, char *pref);
char						*ft_itoa_imp_u(unsigned long long int n);
char						*ft_cnv_hex(long long int adress);
void						ft_print_octal(va_list arg \
							, const char *format, t_rem *rems);
char						*ft_fw_left(t_rem *rems, char *num, char pad);
char						*ft_fw_right(t_rem *rems, char *num);
void						ft_print_adressp(va_list arg \
							, const char *format, t_rem *rems);
void						ft_print_str(va_list arg \
							, const char *format, t_rem *rems);
void						ft_print_char(va_list arg \
							, const char *format, t_rem *rems);
void						ft_putstr_rem(char *str, t_rem *rems);
char						ft_scan_flag(const char *format, int cursor);
char						*ft_make_s(int len, char fill);
char						*ft_itoa_imp(long long int n);
int							ft_field_width(const char *format \
							, int csr, va_list arg);
int							ft_precision(const char *format \
							, int cursor, va_list arg);
void						ft_putchar_rem(char c, t_rem *rems);
int							ft_printf(const char *restrict format, ...);
void						ft_print_int(va_list arg \
							, const char *format, t_rem *rems);
void						ft_print_grbg(va_list arg \
							, const char *format, t_rem *rems, char type);
void						ft_putstr_imp_fd(char **dbl_str, int fd);
int							ft_skip_line(char **line, int fd);
#endif
