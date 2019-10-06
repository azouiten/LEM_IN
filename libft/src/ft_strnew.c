/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 09:45:08 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 21:39:00 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mystr;

	if (!(mystr = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(mystr, size + 1);
	return (mystr);
}
