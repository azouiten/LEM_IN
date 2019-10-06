/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:06:32 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/20 21:27:53 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubn(char *s, char c, char d)
{
	char	*sub;
	size_t	len;

	if (s == NULL)
		return (NULL);
	while (*s != c)
		s++;
	if (*s == '\0')
		return ("\0");
	len = ft_strlenc(s, d);
	if (!(sub = (char*)malloc(len + 1)))
		return (0);
	while (*s != d && *s != '\0')
	{
		*sub = *s;
		sub++;
		s++;
	}
	if (*s == d)
		*sub = *s;
	else
		*sub = '\0';
	return (sub);
}
