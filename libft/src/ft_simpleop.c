/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simpleop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 01:43:50 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/17 18:44:40 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_simpleop(int a, int b, char c)
{
	if (c == '*')
	{
		ft_putstr(ft_itoa(a * b));
		ft_putchar('\n');
	}
	else if (c == '/')
	{
		ft_putstr(ft_itoa(a / b));
		ft_putchar('\n');
	}
	else if (c == '+')
	{
		ft_putstr(ft_itoa(a + b));
		ft_putchar('\n');
	}
	else if (c == '-')
	{
		ft_putstr(ft_itoa(a - b));
		ft_putchar('\n');
	}
	else if (c == '/')
	{
		ft_putstr(ft_itoa(a % b));
		ft_putchar('\n');
	}
}
