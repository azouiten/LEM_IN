/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:59:16 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:25:50 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dup1;
	char	*dup2;
	void	*dsthold;
	size_t	cn;

	cn = 0;
	dsthold = dst;
	dup1 = (char*)dst;
	dup2 = (char*)src;
	while (cn < n)
	{
		dup1[cn] = dup2[cn];
		cn++;
	}
	return (dsthold);
}
