/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:30:15 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 23:22:00 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFH_H
# define PRINTFH_H

# define LD_BUFF_SIZE 64

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include <string.h>
# include <fcntl.h>

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
int							ft_check_convs(char c);
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

#endif
