/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grbg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:03:07 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:43:05 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_grbg(va_list arg, const char *format, t_rem *rems, char type)
{
	char	*str_type;
	char	*pre_zeros;
	char	*temp;

	str_type = ft_make_s(1, type);
	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	if (rems->fg[5] == '0')
		pre_zeros = ft_make_s(rems->fi_wi - 1, '0');
	else
		pre_zeros = ft_make_s(rems->fi_wi - 1, ' ');
	temp = str_type;
	if (rems->fg[1] == '-')
		str_type = ft_strjoin(str_type, pre_zeros);
	else
		str_type = ft_strjoin(pre_zeros, str_type);
	free(temp);
	free(pre_zeros);
	ft_putstr_rem(str_type, rems);
	free(str_type);
}
