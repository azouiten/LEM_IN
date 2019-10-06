/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:25:12 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:45:46 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_percent(va_list arg, const char *format, t_rem *rems)
{
	char	*p_r;

	p_r = ft_strnew(1);
	p_r[0] = '%';
	if (rems->fg[5] == '0')
		rems->pad = '0';
	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	if (rems->fg[5] == '-' && rems->fg[1] != '-')
		rems->pad = '0';
	if (rems->fg[1] == '-')
		p_r = ft_fw_right(rems, p_r);
	else
		p_r = ft_fw_left(rems, p_r, rems->pad);
	ft_putstr_rem(p_r, rems);
	free(p_r);
}
