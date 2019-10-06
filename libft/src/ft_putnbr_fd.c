/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:47:49 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/20 15:47:52 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnegative_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long int dec;
	long int fn;

	if (n < 0)
		ft_putnegative_fd(n, fd);
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
			ft_putchar_fd((n / dec) + '0', fd);
			n = n % dec;
			dec = dec / 10;
		}
	}
}
