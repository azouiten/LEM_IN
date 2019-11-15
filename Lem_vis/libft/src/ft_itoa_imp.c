/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 10:52:14 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:09:53 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_filltab(char *s, long long int n, int nn, long long int len)
{
	if (n >= 0)
		if (!(s = (char*)malloc(nn + 1)))
			return (0);
	if (n < 0)
		if (!(s = (char*)malloc(nn + 2)))
			return (0);
	if (n < 0)
	{
		nn = 1;
		s[0] = '-';
		n = n * -1;
	}
	else
		nn = 0;
	while (len > 0)
	{
		s[nn++] = (((n > 0) ? (n / len) : (n / len) * -1) + '0');
		n = n % len;
		len = len / 10;
	}
	s[nn] = '\0';
	return (s);
}

char		*ft_itoa_imp(long long int n)
{
	long long int	conv;
	long long int	dec;
	long long int	fn;
	int				nn;
	char			*tab;

	tab = NULL;
	conv = n;
	fn = conv;
	dec = 1;
	nn = 1;
	while ((fn / 10) != 0)
	{
		dec = dec * 10;
		nn++;
		fn = fn / 10;
	}
	tab = ft_filltab(tab, conv, nn, dec);
	return (tab);
}
