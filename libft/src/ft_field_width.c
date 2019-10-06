/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:21:03 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 05:54:17 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_field_width(const char *format, int csr, va_list arg)
{
	int		fi_wi;

	csr--;
	while (1)
	{
		while ((format[csr] < '0' || format[csr] > '9') && format[csr] != '%')
		{
			if (format[csr] == '*' && format[csr - 1] != '.')
				return (va_arg(arg, int));
			csr--;
		}
		while (format[csr] >= '0' && format[csr] <= '9')
			csr--;
		if (format[csr] != '.' || format[csr] == '%')
			break ;
	}
	fi_wi = ft_atoi(&format[csr + 1]);
	if (fi_wi < 0)
		fi_wi = 0;
	return (fi_wi);
}
