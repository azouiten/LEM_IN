/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:18:41 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 21:59:55 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	cn;

	if (s1 != NULL && s2 != NULL)
	{
		cn = 0;
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		while (s1[cn] != '\0')
		{
			if (s1[cn] != s2[cn])
				return (0);
			cn++;
		}
	}
	else
		return (0);
	return (1);
}
