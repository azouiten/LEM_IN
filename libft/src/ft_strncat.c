/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:10:42 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:17:00 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	int		len;
	size_t	cn;

	cn = 0;
	len = ft_strlen(s1);
	while (s2[cn] != '\0' && cn < n)
	{
		s1[len + cn] = s2[cn];
		cn++;
	}
	s1[len + cn] = '\0';
	return (s1);
}
