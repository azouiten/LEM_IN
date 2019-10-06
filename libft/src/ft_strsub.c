/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:54:37 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 22:04:36 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mys;
	int		stp;

	if (s == NULL)
		return (NULL);
	stp = 0;
	if (!(mys = (char*)malloc(len + 1)))
		return (0);
	while (stp < (int)len)
	{
		mys[stp] = s[start];
		start++;
		stp++;
	}
	mys[stp] = '\0';
	return (mys);
}
