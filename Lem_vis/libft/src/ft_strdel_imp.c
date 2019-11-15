/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_imp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:13:49 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 17:22:34 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strdel_imp(char ***as)
{
	int		x;

	x = 0;
	while (as[0][x])
	{
		ft_strdel(&(as[0][x]));
		x++;
	}
	free(as[0]);
	as[0] = NULL;
	return (0);
}