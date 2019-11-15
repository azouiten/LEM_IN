/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:07:52 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 17:07:55 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static int		ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int		ft_check_coor(char *line)
{
	int			cn;

	cn = 0;
	while (line[cn] != ' ' && line[cn] != '\0')
		cn++;
	while (line[++cn] != '\0')
	{
		if (!ft_isdigit(line[cn]) && line[cn] != ' ')
			return (0);
	}
	return (1);
}

int				ft_error_input(char *line)
{
	int			cn;
	int			space;

	space = 0;
	cn = 0;
	if (!line)
		return (1);
	while (line[cn] != '\0')
	{
		if (ft_isspace(line[cn]))
			return (1);
		while (!(ft_isspace(line[cn])) && line[cn] != '\0')
			cn++;
		if (line[cn] == ' ')
			space++;
		else if (ft_isspace(line[cn]))
			return (1);
		if (line[cn] == '\0')
			break ;
		cn++;
	}
	if (space != 2 || !ft_check_coor(line))
		return (1);
	return (0);
}
