/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 01:15:14 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 20:27:51 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int cn;

	cn = 0;
	while (s1[cn] == s2[cn] && s1[cn] != '\0' && s2[cn] != '\0')
		cn++;
	return ((unsigned char)s1[cn] - (unsigned char)s2[cn]);
}
