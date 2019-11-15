/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 09:57:57 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 16:08:17 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

int	ft_hash_it(char *name, int vertices)
{
	int	hash_num;
	int	cn;

	if (!name || !vertices)
		return (-1);
	cn = 0;
	hash_num = 0;
	while (name[cn] != '\0')
	{
		hash_num = hash_num + name[cn] + cn;
		cn++;
	}
	return (hash_num % vertices);
}
