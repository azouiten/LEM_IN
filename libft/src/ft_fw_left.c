/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fw_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:43:45 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:08:24 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fw_left(t_rem *rems, char *num, char pad)
{
	char	*first;
	char	*pre_zeros;
	char	*temp;

	first = ft_make_s(1, num[0]);
	pre_zeros = ft_make_s(rems->fi_wi - ft_strlen(num), pad);
	if (first[0] == '+' || first[0] == '-')
	{
		if (pad == '0')
		{
			temp = ft_strdup(num + 1);
			free(num);
			num = temp;
			temp = pre_zeros;
			pre_zeros = ft_strjoin(first, temp);
			free(temp);
		}
	}
	free(first);
	temp = num;
	num = ft_strjoin(pre_zeros, temp);
	free(temp);
	free(pre_zeros);
	return (num);
}
