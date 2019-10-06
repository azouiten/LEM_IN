/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:04:53 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/25 21:33:18 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, char c)
{
	size_t len;

	len = 0;
	while (src[len] != '\0' && src[len] != c)
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
