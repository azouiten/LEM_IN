/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_rep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:29:41 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 05:40:46 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bi_rep(unsigned char *fl, int i)
{
	char	*box;
	char	*temp;
	char	*to_bi;

	box = ft_strnew(1);
	temp = box;
	while (i >= 0)
	{
		to_bi = ft_to_bi(fl[i]);
		box = ft_strjoin(box, ft_normalize(&to_bi));
		free(temp);
		temp = box;
		free(to_bi);
		i--;
	}
	return (box);
}
