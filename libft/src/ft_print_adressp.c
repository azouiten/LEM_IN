/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adressp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 08:25:10 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:16:21 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_adressp(va_list arg, const char *format, t_rem *rems)
{
	char	*converted;
	char	*temp;

	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	converted = ft_cnv_hex(va_arg(arg, long long int));
	if (rems->fg[5] == '0' && rems->fg[1] != '-')
	{
		rems->fi_wi -= 2;
		converted = ft_fw_left(rems, converted, '0');
		temp = converted;
		converted = ft_strjoin("0x", converted);
		free(temp);
	}
	else
	{
		temp = converted;
		converted = ft_strjoin("0x", converted);
		free(temp);
		if (rems->fg[1] == '-')
			converted = ft_fw_right(rems, converted);
		else
			converted = ft_fw_left(rems, converted, ' ');
	}
	ft_putstr_rem(converted, rems);
	free(converted);
}
