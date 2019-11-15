/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:25:03 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/16 19:46:19 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnegative(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else
	{
		ft_putchar('-');
		n = n * -1;
		ft_putnbr(n);
	}
}

void		ft_putnbr(int n)
{
	long int dec;
	long int fn;

	if (n < 0)
		ft_putnegative(n);
	else
	{
		fn = n;
		dec = 1;
		while (fn / 10 != 0)
		{
			dec = dec * 10;
			fn = fn / 10;
		}
		while (dec > 0)
		{
			ft_putchar((n / dec) + '0');
			n = n % dec;
			dec = dec / 10;
		}
	}
}
