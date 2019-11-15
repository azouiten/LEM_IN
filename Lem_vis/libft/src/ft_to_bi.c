/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_bi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 22:26:37 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 07:09:04 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_bi(long long int dec)
{
	char	*base;
	char	*converted;
	char	*temp;
	char	*bi_char;

	if (dec == 0)
	{
		converted = ft_make_s(1, '0');
		return (converted);
	}
	base = ft_strjoin("", "01");
	converted = ft_strnew(1);
	while (dec)
	{
		bi_char = ft_make_s(1, base[dec % 2]);
		temp = converted;
		converted = ft_strjoin(bi_char, converted);
		free(temp);
		free(bi_char);
		dec = dec / 2;
	}
	free(base);
	return (converted);
}
