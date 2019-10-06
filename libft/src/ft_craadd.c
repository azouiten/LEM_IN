/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_craadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:08:52 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/20 16:19:38 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_craadd(char *s, char c)
{
	char	*dups;
	int		cn;
	size_t	len;

	if (s == NULL)
		return (NULL);
	cn = 0;
	len = ft_strlen(s) + 1;
	dups = (char*)malloc(len + 1);
	dups[cn] = c;
	while (s[cn] != '\0')
	{
		dups[cn + 1] = s[cn];
		cn++;
	}
	dups[cn + 1] = '\0';
	return (dups);
}
