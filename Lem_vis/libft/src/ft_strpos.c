/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:15:20 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/25 21:01:54 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strpos(char *s, char *find)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	len = ft_strlen(find);
	while (s[++i])
	{
		j = 0;
		if (s[i] == find[j])
		{
			while (find[j])
			{
				if (j + 1 == len)
				{
					return (i);
				}
				j++;
			}
		}
	}
	return (0);
}
