/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 00:45:42 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 19:50:30 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	l;

	l = 0;
	while (src[l] != '\0')
	{
		dst[l] = src[l];
		l++;
	}
	dst[l] = '\0';
	return (dst);
}
