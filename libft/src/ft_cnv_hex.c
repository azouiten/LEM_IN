/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnv_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:54:38 by ohachim           #+#    #+#             */
/*   Updated: 2019/03/14 10:54:40 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cnv_hex(long long int adress)
{
	char	*hex_ray;
	char	*converted;
	char	*temp;
	char	*hex_char;

	if (adress == 0)
	{
		converted = ft_make_s(1, '0');
		return (converted);
	}
	converted = ft_strnew(1);
	hex_ray = ft_strjoin("", "0123456789abcdef");
	while (adress != 0)
	{
		hex_char = ft_make_s(1, hex_ray[adress % 16]);
		temp = converted;
		converted = ft_strjoin(hex_char, converted);
		free(temp);
		free(hex_char);
		adress = adress / 16;
	}
	free(hex_ray);
	return (converted);
}
