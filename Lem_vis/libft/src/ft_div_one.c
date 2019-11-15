/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:35:46 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 05:56:02 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_div_fail(char **result, long double *one)
{
	char	*temp;

	temp = *result;
	*result = ft_strjoin(*result, "0");
	free(temp);
	*one *= 10;
	return (*result);
}

char	*ft_div_one(long double twos, long double one, \
		long double start)
{
	char	*result;
	char	*temp[2];

	result = ft_strjoin("0.", "");
	while (1)
	{
		start = 1;
		while (one < twos)
			result = ft_div_fail(&result, &one);
		while (start * twos < one)
			start++;
		if (start * twos > one)
			start--;
		temp[0] = ft_make_s(1, start + '0');
		temp[1] = result;
		result = ft_strjoin(result, temp[0]);
		free(temp[0]);
		free(temp[1]);
		if (!(one = one - (start * twos)))
			break ;
		one *= 10;
	}
	return (result);
}
