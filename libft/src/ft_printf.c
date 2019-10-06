/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:14:17 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 07:12:46 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_decide(const char *format, t_rem *rems)
{
	int		cn;

	cn = 1;
	while (format[cn] == '+' || format[cn] == '-' || format[cn] == '.'
			|| format[cn] == '#' || format[cn] == '0' || format[cn] == ' '
			|| format[cn] == '.' || format[cn] == 'l' || format[cn] == 'h'
			|| format[cn] == 'L' || (format[cn] >= '0' && format[cn] <= '9')
			|| format[cn] == '*')
	{
		ft_flagge_rino(rems, format[cn], format[cn - 1]);
		cn++;
	}
	rems->cursor += cn;
	return (format[cn]);
}

static char	ft_percent(const char *format, t_rem *rems)
{
	while (format[rems->cursor] != '\0' && format[rems->cursor] != '%')
	{
		write(1, &format[rems->cursor], 1);
		rems->cursor++;
		rems->counter++;
	}
	if (format[rems->cursor] == '\0')
		return (0);
	return (ft_decide(&format[rems->cursor], rems));
}

static void	ft_decide_n_print(char type, va_list arg \
		, const char *format, t_rem *rems)
{
	if (type == '%')
		ft_print_percent(arg, format, rems);
	else if (type == 'c')
		ft_print_char(arg, format, rems);
	else if (type == 's')
		ft_print_str(arg, format, rems);
	else if (type == 'i' || type == 'd')
		ft_print_int(arg, format, rems);
	else if (type == 'p')
		ft_print_adressp(arg, format, rems);
	else if (type == 'o')
		ft_print_octal(arg, format, rems);
	else if (type == 'u')
		ft_print_unsigned(arg, format, rems);
	else if (type == 'X')
		ft_print_uns_hex_up(arg, format, rems);
	else if (type == 'x')
		ft_print_uns_hex_low(arg, format, rems);
	else if (type == 'f')
		ft_print_float(arg, format, rems);
	else if (type == 'a' || type == 'A' || type == 'b' || type == 'g')
		ft_print_bonus(arg, format, rems, type);
	else
		ft_print_grbg(arg, format, rems, type);
}

static void	ft_initialize_rems(t_rem *rems)
{
	rems->pad = ' ';
	rems->fi_wi = 0;
	rems->precision = 0;
	rems->pref = 0;
	rems->fg = ft_make_s(6, '$');
}

int			ft_printf(const char *restrict format, ...)
{
	t_rem	rems;
	va_list arg;
	char	conv;

	if (!format)
		return (0);
	rems.cursor = 0;
	rems.counter = 0;
	ft_initialize_rems(&rems);
	va_start(arg, format);
	while ((conv = ft_percent(format, &rems)))
	{
		ft_decide_n_print(conv, arg, format, &rems);
		free(rems.fg);
		ft_initialize_rems(&rems);
	}
	free(rems.fg);
	va_end(arg);
	return (rems.counter);
}
