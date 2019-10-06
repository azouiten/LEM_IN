/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_neg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:35:38 by ohachim           #+#    #+#             */
/*   Updated: 2019/06/09 19:33:44 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_neg(char **bi_fl, char **p_r, int ztrue)
{
	char	*temp;
	char	*zro;

	if (!ztrue)
	{
		temp = *p_r;
		if (bi_fl[0][0] == '1')
			*p_r = ft_strjoin("-", *p_r);
		if (bi_fl[0][0] == '1')
			free(temp);
	}
	else
	{
		free(*p_r);
		zro = ft_make_s(1, '0');
		temp = zro;
		if (bi_fl[0][0] == '1')
			zro = ft_strjoin("-", zro);
		if (bi_fl[0][0] == '1')
			free(temp);
		free(*bi_fl);
		return (zro);
	}
	free(*bi_fl);
	return (*p_r);
}
