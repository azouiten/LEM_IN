/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:40:49 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 07:08:01 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_unsigned(va_list arg, const char *format, t_rem *rems)
{
	char	*p;
	char	type_spec;

	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	rems->precision = ft_precision(format, rems->cursor, arg);
	type_spec = ft_scan_flag(format, rems->cursor);
	if (type_spec == 'l')
		p = ft_construct_s(ft_itoa_imp_u(va_arg(arg, unsigned long int)) \
		, format, rems, "");
	else if (type_spec == 'L')
		p = ft_construct_s(ft_itoa_imp_u(va_arg(arg \
		, unsigned long long int))
		, format, rems, "");
	else if (type_spec == 'H')
		p = ft_construct_s(ft_itoa_imp_u((unsigned char)va_arg(arg \
		, unsigned int)), format, rems, "");
	else if (type_spec == 'h')
		p = ft_construct_s(ft_itoa_imp_u((unsigned short int)va_arg(arg \
		, unsigned int)), format, rems, "");
	else
		p = ft_construct_s(ft_itoa_imp_u(va_arg(arg, unsigned int)), \
		format, rems, "");
	ft_putstr_rem(p, rems);
	free(p);
}
