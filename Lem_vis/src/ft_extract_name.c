/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 09:20:52 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/10 16:45:46 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

char	*ft_extract_name(char *line)
{
	int	size;

	size = 0;
	if (!line)
		return (0);
	while (line[size] != '\0' && line[size] != ' ' && line[size] != '-')
		size++;
	return (ft_strsub(line, 0, size));
}
