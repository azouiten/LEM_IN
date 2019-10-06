/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:51:23 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:16:45 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int len;
	int cn;

	cn = 0;
	len = ft_strlen(s1);
	while (s2[cn] != '\0')
	{
		s1[len + cn] = s2[cn];
		cn++;
	}
	s1[len + cn] = '\0';
	return (s1);
}
