/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 09:11:48 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:15:29 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		starts;
	size_t		startd;
	size_t		r_sizef;

	startd = ft_strlen((dst));
	starts = 0;
	r_sizef = startd + ft_strlen(src);
	while ((int)(startd + starts) < (int)size - 1 && src[starts])
	{
		dst[startd + starts] = src[starts];
		starts++;
	}
	dst[startd + starts] = '\0';
	if (size + ft_strlen(src) > r_sizef)
		return (r_sizef);
	else
		return ((size + ft_strlen(src)));
}
