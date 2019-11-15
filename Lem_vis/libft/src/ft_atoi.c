/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:08:07 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/17 18:14:15 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	toi;
	int				cn;
	char			*dupstr;

	cn = 0;
	toi = 0;
	dupstr = (char*)str;
	if ((*str == ' ' || (*str >= 9 && *str <= 13)) &&
				((*(str - 1) > '9' && *(str - 1) < '0') || str == dupstr))
		toi = ft_atoi(++str);
	else if (*str == '+' && *(str + 1) >= '0' && *(str + 1) <= '9')
		toi = ft_atoi(++str);
	else if (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9')
	{
		toi = ft_atoi(++str);
		return (toi * -1);
	}
	else
		while (str[cn] >= '0' && str[cn] <= '9' && str[cn] != '\0')
		{
			toi = toi * 10 + (str[cn] - '0');
			cn++;
		}
	return ((int)toi);
}
