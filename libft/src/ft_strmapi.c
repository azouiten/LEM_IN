/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:42:05 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/20 15:25:44 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		cn;
	char	*mys;

	if (s == 0)
		return (NULL);
	cn = 0;
	if (!(mys = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[cn] != '\0')
	{
		mys[cn] = f(cn, s[cn]);
		cn++;
	}
	mys[cn] = '\0';
	return (mys);
}
