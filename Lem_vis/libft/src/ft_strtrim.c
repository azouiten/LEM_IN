/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 11:28:56 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/20 16:20:41 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trimback(char *s)
{
	int	size;

	size = ft_strlen(s) - 1;
	while (s[size] == ' ' || s[size] == '\n' || s[size] == '\t')
	{
		s[size] = '\0';
		size--;
	}
	return (s);
}

static int	ft_strlentrim(char *s)
{
	int size;

	size = ft_strlen(s);
	while (s[size - 1] == ' ' || s[size - 1] == '\n' || s[size - 1] == '\t')
	{
		size--;
	}
	return (size);
}

char		*ft_strtrim(char const *s)
{
	char	*dups;
	char	*trims;
	int		cn;

	if (s == NULL)
		return (NULL);
	cn = 0;
	dups = ft_strdup(s);
	if (dups == NULL)
		return (NULL);
	while (*dups == ' ' || *dups == '\n' || *dups == '\t')
		dups++;
	if (*dups == '\0')
		return ("\0");
	if (!(trims = (char*)malloc(ft_strlentrim(dups) + 1)))
		return (NULL);
	while (dups[cn] != '\0')
	{
		trims[cn] = dups[cn];
		cn++;
	}
	trims[cn] = '\0';
	trims = ft_trimback(trims);
	return (trims);
}
