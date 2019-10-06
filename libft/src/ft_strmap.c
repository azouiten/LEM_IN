/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 13:56:03 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/20 15:25:14 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*sdres;
	int		cn;

	if (s == NULL)
		return (NULL);
	cn = 0;
	if (!(sdres = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[cn] != '\0')
	{
		sdres[cn] = f(s[cn]);
		cn++;
	}
	sdres[cn] = '\0';
	return (sdres);
}
