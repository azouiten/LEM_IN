/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:40:16 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:19:28 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cn;

	cn = 0;
	while (s[cn] != '\0')
	{
		if (s[cn] == (char)c)
			return ((char*)&s[cn]);
		cn++;
	}
	if ((char)c == '\0')
		return ((char*)&s[cn]);
	return (NULL);
}
