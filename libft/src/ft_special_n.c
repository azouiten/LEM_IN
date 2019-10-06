/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:14:42 by ohachim           #+#    #+#             */
/*   Updated: 2019/04/30 15:14:44 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_special_n(char **bi_fl, char fcm, int iexpo)
{
	char	*temp;

	temp = ft_strnew(1);
	if (iexpo == -127 || iexpo == -16383 || iexpo == -1023)
		return (ft_check_neg(bi_fl, &temp, 1));
	if (iexpo == 128 || iexpo == 16384 || iexpo == 1024)
	{
		if (fcm == '1')
			return (ft_strjoin("nan", ""));
		if (fcm == '0')
		{
			if (bi_fl[0][0] == '1')
				return (ft_strjoin("-inf", ""));
			return (ft_strjoin("inf", ""));
		}
	}
	return (ft_make_s(1, '0'));
}
