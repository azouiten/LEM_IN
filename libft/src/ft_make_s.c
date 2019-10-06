/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_zs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:15:25 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:14:58 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_make_s(int len, char fill)
{
	char	*str;
	int		cn;

	cn = 0;
	if (len <= 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		return (str);
	}
	else
	{
		if (!(str = ft_strnew(len + 1)))
			return (NULL);
	}
	while (cn < len)
	{
		str[cn] = fill;
		cn++;
	}
	str[cn] = '\0';
	return (str);
}
