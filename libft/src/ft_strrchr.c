/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:04:51 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:20:00 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cn;

	cn = ft_strlen(s);
	while (cn >= 0)
	{
		if (s[cn] == (char)c)
			return ((char*)&s[cn]);
		cn--;
	}
	return (NULL);
}
