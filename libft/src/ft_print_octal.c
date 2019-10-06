/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 03:56:51 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:49:16 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_conv_make(unsigned long long int convert)
{
	char	*oct_ray;
	char	*converted;
	char	*temp;
	char	*oct_char;
	int		out;

	out = 0;
	converted = ft_strnew(1);
	oct_ray = ft_strjoin("", "01234567");
	while (convert != 0 || out == 0)
	{
		oct_char = ft_make_s(1, oct_ray[convert % 8]);
		temp = converted;
		converted = ft_strjoin(oct_char, converted);
		free(temp);
		free(oct_char);
		convert = convert / 8;
		out++;
	}
	free(oct_ray);
	return (converted);
}

void		ft_print_octal(va_list arg, const char *format, t_rem *rems)
{
	char	*p_r;
	char	type_spec;

	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	rems->precision = ft_precision(format, rems->cursor, arg);
	type_spec = ft_scan_flag(format, rems->cursor);
	if (type_spec == 'l')
		p_r = ft_conv_make((unsigned long int)va_arg(arg, unsigned long int));
	else if (type_spec == 'L')
		p_r = ft_conv_make(va_arg(arg, unsigned long long int));
	else if (type_spec == 'H')
		p_r = ft_conv_make((unsigned char)va_arg(arg, unsigned int));
	else if (type_spec == 'h')
		p_r = ft_conv_make((unsigned short int)va_arg(arg, unsigned int));
	else
		p_r = ft_conv_make((unsigned int)va_arg(arg, unsigned int));
	p_r = ft_construct_s(p_r, format, rems, "0");
	ft_putstr_rem(p_r, rems);
	free(p_r);
}
