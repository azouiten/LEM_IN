/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_edge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 09:20:52 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/05 14:11:49 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

char	*ft_extract_edge(char *line)
{
	int	size;

	size = 0;
	if (!line)
		return (0);
	while (line[size] != '\0' && line[size] != '-')
		size++;
	return (ft_strsub(line, 0, size));
}
