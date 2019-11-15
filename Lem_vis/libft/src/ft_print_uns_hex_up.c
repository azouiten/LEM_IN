/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_hex_up.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:03:17 by ohachim           #+#    #+#             */
/*   Updated: 2019/03/15 10:03:18 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_uns_hex_up(va_list arg, const char *format, t_rem *rems)
{
	char	type_spec;
	char	*p_r;

	rems->pref = 0;
	rems->precision = ft_precision(format, rems->cursor, arg);
	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	type_spec = ft_scan_flag(format, rems->cursor);
	if (type_spec == 'l')
		p_r = ft_cnv_hex_u(va_arg(arg, unsigned long int), 'u');
	else if (type_spec == 'L')
		p_r = ft_cnv_hex_u(va_arg(arg, unsigned long long int), 'u');
	else if (type_spec == 'H')
		p_r = ft_cnv_hex_u((unsigned char)va_arg(arg, unsigned int), 'u');
	else if (type_spec == 'h')
		p_r = ft_cnv_hex_u((unsigned short int)va_arg(arg, unsigned int), 'u');
	else
		p_r = ft_cnv_hex_u(va_arg(arg, unsigned int), 'u');
	p_r = ft_construct_s(p_r, format, rems, "0X");
	ft_putstr_rem(p_r, rems);
	free(p_r);
}
