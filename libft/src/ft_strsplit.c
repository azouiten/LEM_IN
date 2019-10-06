/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:54:28 by ohachim           #+#    #+#             */
/*   Updated: 2018/11/07 21:34:20 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int cn;
	int words;

	words = 0;
	cn = 0;
	if (s[0] != c)
		words++;
	while (s[cn + 1] != '\0')
	{
		if (s[cn] == c && s[cn + 1] != c)
		{
			words++;
		}
		cn++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptop;
	int		words;
	int		wn;
	char	*dups;

	if (s == NULL)
		return (NULL);
	dups = (char*)s;
	wn = 0;
	words = ft_countwords(s, c);
	if (!(ptop = (char**)malloc(sizeof(char**) * words + 1)))
		return (NULL);
	ptop[words] = 0;
	while (wn < words)
	{
		while (*dups == c)
			dups++;
		if (!(ptop[wn] = (char*)malloc(ft_strlenc(dups, c) + 1)))
			return (NULL);
		ptop[wn] = ft_strcpyc(ptop[wn], (const char*)dups, c);
		wn++;
		while (*dups != c && *dups != '\0' && wn < words)
			dups++;
	}
	return (ptop);
}
