/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 21:02:45 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:27:01 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cn;
	unsigned char	*dups;

	cn = 0;
	dups = (unsigned char*)s;
	while (cn < n)
	{
		if (dups[cn] == (unsigned char)c)
			return ((void*)&dups[cn]);
		cn++;
		s++;
	}
	return (NULL);
}
