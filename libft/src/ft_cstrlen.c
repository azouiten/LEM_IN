/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:47:13 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 05:43:12 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cstrlen(const char *str, char c)
{
	int	cn;
	int	len;

	len = 0;
	cn = 0;
	while (str[cn] != '\0' && str[cn] != c)
		cn++;
	while (str[cn] != '\0')
	{
		len++;
		cn++;
	}
	return (len);
}
