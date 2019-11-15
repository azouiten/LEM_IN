/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_ldouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 06:18:09 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:41:49 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_tissa(char *bi_fl, int len)
{
	char		*store[LD_BUFF_SIZE + 1];
	int			cn;
	long double	twos;
	char		*addi;

	cn = 0;
	twos = 2;
	while (cn < len)
	{
		if (bi_fl[cn] == '1')
			store[cn] = ft_div_one(twos, 10, 1);
		else
			store[cn] = ft_strjoin("0.0", "");
		cn++;
		twos = twos * 2;
	}
	cn = 0;
	addi = ft_make_s(1, '0');
	while (cn < len)
	{
		addi = ft_bi_add(&addi, &store[cn], 1);
		cn++;
	}
	return (addi);
}

static int	ft_get_expo(char *bi_fl, int len)
{
	int cn;
	int expo;
	int val;

	expo = 0;
	cn = 1;
	val = 16384;
	while (cn < len + 1)
	{
		if (bi_fl[cn] == '1')
			expo = expo + val;
		val = val >> 1;
		cn++;
	}
	return (expo);
}

static char	*ft_make_expo(int iexpo)
{
	char	*expo;
	char	*two;

	expo = ft_strjoin("", "2");
	while (iexpo - 1 > 0)
	{
		two = ft_strjoin("", "2");
		expo = ft_bi_mult(&expo, &two);
		iexpo--;
	}
	return (expo);
}

static int	ft_manti_zro(char *mant)
{
	int		cn;

	cn = 0;
	while (mant[cn] != '\0')
	{
		if (mant[cn] != '0')
			return (0);
		cn++;
	}
	return (1);
}

char		*ft_make_ldouble(long double xtrct, int len)
{
	unsigned char	fl[len];
	char			*bi_fl;
	char			*expo;
	char			*mantissa;
	t_ld			var;

	expo = ft_strnew(1);
	var.one = ft_make_s(1, '1');
	ft_memcpy(fl, &xtrct, len);
	bi_fl = ft_bi_rep(fl, len - 1);
	var.iexpo = ft_get_expo(bi_fl, 15) - 16383;
	if ((var.iexpo == -16383 || var.iexpo == 16384) && ft_manti_zro(bi_fl + 19))
		return (ft_special_n(&bi_fl, bi_fl[17], var.iexpo));
	if (var.iexpo > 0)
	{
		free(expo);
		expo = ft_make_expo(var.iexpo);
	}
	mantissa = ft_get_tissa(bi_fl + 17, 63);
	mantissa = ft_bi_add(&mantissa, &var.one, 1);
	var.p_r = ft_finish_fract(&mantissa, &expo, var.iexpo);
	var.p_r = ft_check_neg(&bi_fl, &var.p_r, 0);
	return (var.p_r);
}
