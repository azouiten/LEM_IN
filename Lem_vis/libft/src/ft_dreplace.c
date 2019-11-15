/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dreplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:58:02 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/20 17:00:13 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dreplace(const char *s, char tor, char r)
{
	char	*dups;
	size_t	len;
	size_t	cn;

	cn = 0;
	len = ft_strlen(s);
	if (!(dups = (char*)malloc(len + 1)))
		return (NULL);
	while (s[cn] != '\0')
	{
		if (s[cn] == tor)
			dups[cn] = r;
		else
			dups[cn] = s[cn];
		cn++;
	}
	dups[cn] = '\0';
	return (dups);
}
