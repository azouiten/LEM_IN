/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:29:39 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/05 17:38:36 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static int		ft_ants(t_data *data)
{
	int	cn;

	cn = 0;
	if (!data->input_head->line)
		return (0);
	while (data->input_head->line[cn] != '\0')
	{
		if (!(ft_isdigit(data->input_head->line[cn])))
			return (0);
		cn++;
	}
	data->ants = ft_atoi(data->input_head->line);
	if (data->ants < 1)
		return (0);
	return (1);
}

static int		ft_vertex_check(t_input *input, int *vertices)
{
	t_input		*temp;

	temp = input->next;
	*vertices = 0;
	while (temp)
	{
		if (ft_strchr(temp->line, '-'))
			break ;
		if (temp->line[0] == 'L')
			return (0);
		if (temp->line[0] != '#' && ft_error_input(temp->line))
			return (0);
		if (temp->line[0] != '#')
			(*vertices)++;
		temp = temp->next;
	}
	return (1);
}

int				ft_create_data(t_data *data)
{
	if (!(ft_ants(data))
			|| !(ft_vertex_check(data->input_head, &data->vertices))
			|| !ft_create_hash(data)
			|| !ft_create_edges(data))
		return (-1);
	return (1);
}
