/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:14:45 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:21:32 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	cnph;
	int	cnsh;
	int	cnne;

	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	cnph = 0;
	cnne = 0;
	while (haystack[cnph] != '\0')
	{
		cnsh = cnph;
		while (haystack[cnph] == needle[cnne] && haystack[cnph] && needle[cnne])
		{
			cnph++;
			cnne++;
		}
		if (needle[cnne] == '\0')
			return ((char*)&haystack[cnsh]);
		cnne = 0;
		if (haystack[cnph] == '\0')
			return (NULL);
		cnph = cnsh + 1;
	}
	return (NULL);
}
