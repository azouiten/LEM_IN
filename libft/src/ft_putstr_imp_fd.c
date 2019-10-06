/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_imp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 03:26:29 by ohachim           #+#    #+#             */
/*   Updated: 2019/06/28 03:35:06 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_imp_fd(char **dbl_str, int fd)
{
	int		x;

	x = 0;
	while (dbl_str[x])
	{
		ft_putendl_fd(dbl_str[x], fd);
		x++;
	}
}
