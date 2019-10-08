/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:11:24 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/08 19:37:39 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		cnj;
	int		cn;

	cnj = 0;
	cn = 0;
	if ((s1 == NULL || s2 == NULL)
		|| (!(join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[cn] != '\0')
	{
		join[cnj] = s1[cn];
		cn++;
		cnj++;
	}
	cn = 0;
	while (s2[cn] != '\0')
	{
		join[cnj + cn] = s2[cn];
		cn++;
	}
	join[cnj + cn] = '\0';
	return (join);
}
