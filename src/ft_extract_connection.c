/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_connection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 10:26:21 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/05 14:11:22 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

char	*ft_extract_connection(char *line)
{
	int	cn0;
	int	cn1;
	int	size;

	size = 0;
	cn0 = 0;
	if (!line)
		return (0);
	while (line[cn0] != '-' && line[cn0] != '\0')
		cn0++;
	cn0++;
	cn1 = cn0;
	while (line[cn1++] != '\0')
		size++;
	return (ft_strsub(line, cn0, size));
}
