/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:30:33 by ohachim           #+#    #+#             */
/*   Updated: 2019/03/06 16:30:35 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_null(char c, t_rem *rems)
{
	ft_putchar(c);
	rems->counter++;
}

void		ft_print_char(va_list arg, const char *format, t_rem *rems)
{
	char	c;
	char	*str_c;
	char	*pre_zeros;
	char	*temp;

	c = va_arg(arg, int);
	if (c == 0 && rems->fg[1] == '-')
		ft_putchar_null(0, rems);
	str_c = ft_make_s(1, c);
	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	if (rems->fg[5] == '0')
		pre_zeros = ft_make_s(rems->fi_wi - 1, '0');
	else
		pre_zeros = ft_make_s(rems->fi_wi - 1, ' ');
	temp = str_c;
	if (rems->fg[1] == '-')
		str_c = ft_strjoin(str_c, pre_zeros);
	else
		str_c = ft_strjoin(pre_zeros, str_c);
	free(temp);
	free(pre_zeros);
	ft_putstr_rem(str_c, rems);
	free(str_c);
	if (c == 0 && rems->fg[1] != '-')
		ft_putchar_null(0, rems);
}
