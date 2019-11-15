/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 06:15:43 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:15:55 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_precision(const char *format, int cursor, va_list arg)
{
	int		precision;

	precision = 0;
	while (format[cursor] != '.' && format[cursor] != '%')
	{
		if (format[cursor] == '*' && format[cursor - 1] == '.')
			return (va_arg(arg, int));
		cursor--;
	}
	if (format[cursor] == '%')
		return (0);
	if (format[cursor + 1] >= '0' && format[cursor] <= '9')
		precision = ft_atoi(&format[cursor + 1]);
	if (precision < 0)
		precision = -1;
	return (precision);
}
