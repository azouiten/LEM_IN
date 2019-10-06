/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:59:17 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 19:45:16 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		cn;

	cn = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	if (!(dup = (char*)malloc(len + 1)))
		return (NULL);
	while (cn < len)
	{
		dup[cn] = s1[cn];
		cn++;
	}
	dup[cn] = '\0';
	return (dup);
}
