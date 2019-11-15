/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:06:59 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 19:43:10 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		stp;
	const char	*dup1;
	const char	*dup2;

	stp = 1;
	dup1 = (const char*)s1;
	dup2 = (const char*)s2;
	if (n == 0)
		return (0);
	while (*dup1 == *dup2 && stp < n && s1 && s2)
	{
		dup1++;
		dup2++;
		stp++;
	}
	return ((unsigned char)*dup1 - (unsigned char)*dup2);
}
