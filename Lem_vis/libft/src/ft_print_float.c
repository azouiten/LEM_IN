/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:47:11 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:57:28 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_sp_chr(char *p_r)
{
	if (!ft_strchr(p_r, 'n') && !ft_strchr(p_r, 'i'))
		return (1);
	return (0);
}

static char	*ft_normalize_pr(char **p_r)
{
	char	*temp;
	int		len;

	if (!ft_strchr(*p_r, '.') && ft_sp_chr(*p_r))
	{
		temp = *p_r;
		*p_r = ft_strjoin(*p_r, ".");
		free(temp);
	}
	len = ft_strlen(*p_r) - 1;
	while (len != 0 && p_r[0][len] != '.' && p_r[0][len] == '0')
	{
		p_r[0][len] = '\0';
		len--;
	}
	return (*p_r);
}

static char	*ft_flag_it(char **p, t_rem *r, int fin, char s)
{
	char	*temp;

	if ((r->fg[0] == '+' && p[0][0] != '-' && !ft_strchr(*p, 'n')) ||
			(ft_strchr(*p, 'i') && r->fg[0] == '+' && p[0][0] != '-'))
	{
		temp = *p;
		*p = ft_strjoin("+", *p);
		free(temp);
	}
	fin = ft_strlen(*p) - 1;
	if (p[0][fin] == '.' && r->fg[3] != '#')
		p[0][fin] = '\0';
	if (r->fg[4] == ' ' && r->fg[0] != '+' && s != '-' && !ft_strchr(*p, 'a'))
		r->fi_wi--;
	if (r->fg[1] == '-')
		*p = ft_fw_right(r, *p);
	else
		*p = ft_fw_left(r, *p, r->pad);
	if (r->fg[4] == ' ' && r->fg[0] != '+' && s != '-' && !ft_strchr(*p, 'a'))
	{
		temp = *p;
		*p = ft_strjoin(" ", *p);
		free(temp);
	}
	return (*p);
}

static char	*ft_final_fix(char **p_r, t_rem *rems, int preci)
{
	int		clen;
	char	*temp;

	if (!ft_sp_chr(*p_r) || !ft_strchr(*p_r, '.'))
		return (*p_r);
	clen = ft_cstrlen(*p_r, '.') - 1;
	while (clen < preci)
	{
		temp = *p_r;
		*p_r = ft_strjoin(*p_r, "0");
		free(temp);
		clen++;
	}
	if (rems->fg[5] == '0' && rems->fg[1] != '-' && ft_sp_chr(*p_r))
		rems->pad = '0';
	return (*p_r);
}

void		ft_print_float(va_list arg, const char *format, t_rem *rems)
{
	char		*p_r;
	int			precidup;
	char		*temp;
	long double f;

	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	rems->precision = ft_precision(format, rems->cursor, arg);
	precidup = rems->precision;
	if (format[rems->cursor - 1] == 'L')
		f = va_arg(arg, long double);
	else
		f = va_arg(arg, double);
	p_r = ft_make_ldouble(f, 10);
	p_r = ft_normalize_pr(&p_r);
	p_r = ft_round_it(&p_r, rems);
	p_r = ft_final_fix(&p_r, rems, precidup);
	p_r = ft_flag_it(&p_r, rems, 0, p_r[0]);
	if (rems->fg[3] == '#' && !ft_strchr(p_r, '.') && ft_sp_chr(p_r))
	{
		temp = p_r;
		p_r = ft_strjoin(p_r, ".");
		free(temp);
	}
	ft_putstr_rem(p_r, rems);
	free(p_r);
}
