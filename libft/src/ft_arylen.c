/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 03:46:54 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/24 05:56:01 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arylen(char **ary)
{
	size_t counter;

	counter = 0;
	while (*ary)
	{
		counter += ft_strlen(*ary);
		ary++;
	}
	return (counter);
}
