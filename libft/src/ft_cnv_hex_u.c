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

char	*ft_cnv_hex_u(unsigned long long int num, char spec)
{
	char	*hex_ray;
	char	*converted;
	char	*temp;
	char	*hex_char;
	int		i;

	i = 0;
	converted = ft_strnew(1);
	if (spec == 'l')
		hex_ray = ft_strjoin("", "0123456789abcdef");
	else if (spec == 'u')
		hex_ray = ft_strjoin("", "0123456789ABCDEF");
	while (num != 0 || i == 0)
	{
		hex_char = ft_make_s(1, hex_ray[num % 16]);
		temp = converted;
		converted = ft_strjoin(hex_char, converted);
		free(temp);
		free(hex_char);
		num = num / 16;
		i++;
	}
	free(hex_ray);
	return (converted);
}
