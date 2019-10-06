/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:30:51 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 19:50:49 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int l;

	l = 0;
	while (src[l] && l < (int)len)
	{
		dst[l] = src[l];
		l++;
	}
	while (l < (int)len)
	{
		dst[l] = '\0';
		l++;
	}
	return (dst);
}
