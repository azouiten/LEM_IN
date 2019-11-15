/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_imp_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:04:49 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:09:11 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_filltab_u(char *s, unsigned long long int n, int nn, \
		unsigned long long int len)
{
	if (!(s = (char*)malloc(nn + 1)))
		return (0);
	nn = 0;
	while (len > 0)
	{
		s[nn++] = ((n / len) + '0');
		n = n % len;
		len = len / 10;
	}
	s[nn] = '\0';
	return (s);
}

char			*ft_itoa_imp_u(unsigned long long int n)
{
	unsigned long long int	conv;
	unsigned long long int	dec;
	unsigned long long int	fn;
	int						nn;
	char					*tab;

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
	tab = ft_filltab_u(tab, conv, nn, dec);
	return (tab);
}
