/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 03:01:54 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:26:34 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dup1;
	unsigned char	*dup2;
	size_t			cn;

	cn = 0;
	dup1 = dst;
	dup2 = (unsigned char*)src;
	while (cn < n && *dup2 != (unsigned char)c)
	{
		*dup1 = *dup2;
		dup1++;
		dup2++;
		cn++;
	}
	if (*dup2 == (unsigned char)c)
	{
		*dup1 = (unsigned char)c;
		dup1++;
		return (dup1);
	}
	return (NULL);
}
