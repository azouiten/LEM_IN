/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_fract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:27:42 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:13:10 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fix_res(char **res)
{
	char	*temp;

	if (res[0][0] == '.')
	{
		temp = *res;
		*res = ft_strjoin("0", *res);
		free(temp);
	}
	return (*res);
}

static char	*ft_chs_hlf(int iexpo)
{
	char	*half;

	if (iexpo == 1)
		half = ft_strjoin("0.5", "");
	if (iexpo == 2)
		half = ft_strjoin("0.25", "");
	if (iexpo == 3)
		half = ft_strjoin("0.125", "");
	if (iexpo == 4)
		half = ft_strjoin("0.0625", "");
	if (iexpo == 5)
		half = ft_strjoin("0.03125", "");
	return (half);
}

static char	*ft_finish_fractn(char **mantissa, int iexpo)
{
	char	*expo;
	char	*res;
	char	*half;

	expo = ft_make_s(1, '1');
	while (iexpo > 5)
	{
		half = ft_strjoin("0.015625", "");
		expo = ft_bi_mult(&expo, &half);
		iexpo -= 6;
	}
	if (iexpo)
	{
		half = ft_chs_hlf(iexpo);
		expo = ft_bi_mult(&expo, &half);
	}
	res = ft_bi_mult(mantissa, &expo);
	return (ft_fix_res(&res));
}

char		*ft_finish_fract(char **mantissa, char **expo, int iexpo)
{
	char	*res;

	if (iexpo == 0)
		return (*mantissa);
	if (iexpo < 0)
		return (ft_finish_fractn(mantissa, iexpo * -1));
	res = ft_bi_mult(expo, mantissa);
	return (res);
}
