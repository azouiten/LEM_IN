/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frexp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:00:57 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/05 14:31:29 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	ft_frexp(double value, int *expo)
{
	int sign;

	sign = 1;
	if (value < 0)
	{
		value *= -1;
		sign *= -1;
	}
	*expo = 0;
	if (value)
	{
		while (value >= 1.0)
		{
			value /= 2;
			*expo += 1;
		}
	}
	else
		value = 0.0;
	return (sign * value);
}
