/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:33:53 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/21 19:20:48 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dupst;
	char		*duprc;
	const char	*duprc1;
	size_t		looper;

	duprc1 = (const char*)src;
	looper = 0;
	duprc = (char*)malloc(len);
	if (duprc == NULL)
		return (NULL);
	dupst = ((char*)dst);
	while (looper < len)
	{
		*(duprc + looper) = *(duprc1 + looper);
		looper++;
	}
	looper = 0;
	while (looper < len)
	{
		*(dupst + looper) = *(duprc + looper);
		looper++;
	}
	free(duprc);
	duprc = NULL;
	return (dst);
}
