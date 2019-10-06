/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_rem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:49:55 by ohachim           #+#    #+#             */
/*   Updated: 2019/03/06 16:49:57 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_rem(char *str, t_rem *rems)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
	rems->counter += len;
	rems->cursor += 1;
}
