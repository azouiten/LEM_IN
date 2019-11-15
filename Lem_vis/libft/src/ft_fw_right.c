/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fw_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 23:41:42 by ohachim           #+#    #+#             */
/*   Updated: 2019/03/10 23:41:46 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fw_right(t_rem *rems, char *num)
{
	char	*temp;
	char	*padds;
	int		len;

	len = ft_strlen(num);
	padds = ft_make_s(rems->fi_wi - len, ' ');
	temp = num;
	num = ft_strjoin(temp, padds);
	free(padds);
	free(temp);
	return (num);
}
