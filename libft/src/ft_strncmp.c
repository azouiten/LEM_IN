/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:25:32 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/20 21:34:36 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cn;

	cn = 0;
	if (n == 0)
		return (0);
	while (s1[cn] != '\0' && s2[cn] != '\0' && cn < n - 1)
	{
		if (s2[cn] == s1[cn])
			cn++;
		else
			return ((unsigned char)s1[cn] - (unsigned char)s2[cn]);
	}
	return ((unsigned char)s1[cn] - (unsigned char)s2[cn]);
}
