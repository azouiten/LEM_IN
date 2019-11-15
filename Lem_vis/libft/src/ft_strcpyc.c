/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:58:12 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/29 20:01:38 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyc(char *dst, const char *src, char c)
{
	int	cn;

	if (ft_strlen(src) == 0)
		return (NULL);
	cn = 0;
	while (src[cn] != c && src[cn] != '\0')
	{
		dst[cn] = src[cn];
		cn++;
	}
	dst[cn] = '\0';
	return (dst);
}
