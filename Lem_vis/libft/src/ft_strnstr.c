/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:29:00 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:24:30 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_checkernstr(const char *haystack, const char *needle,
		size_t len, int cnph)
{
	int		cnsh;
	int		cnne;

	cnne = 0;
	while (haystack[cnph] != '\0')
	{
		cnsh = cnph;
		while (haystack[cnph] == needle[cnne] && haystack[cnph]
				&& needle[cnne] && cnph < (int)len)
		{
			cnph++;
			cnne++;
		}
		if (needle[cnne] == '\0')
			return ((char*)&haystack[cnsh]);
		cnne = 0;
		cnph = cnsh + 1;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int cnph;

	cnph = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	return (ft_checkernstr(haystack, needle, len, cnph));
}
