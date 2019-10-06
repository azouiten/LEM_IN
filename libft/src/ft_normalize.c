/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:27:50 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:16:48 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_normalize(char **sh)
{
	char	*temp;

	while (ft_strlen(*sh) < 8)
	{
		temp = *sh;
		*sh = ft_strjoin("0", *sh);
		free(temp);
	}
	return (*sh);
}
