/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:55:02 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/04 15:29:20 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static int		ft_ants(t_data *data, int cn)
{
	t_input *to_free;

	if (!data->input_head || data->input_head->line[0] == '\0')
		return (0);
	while (data->input_head && data->input_head->line[0] == '#')
	{
		ft_printf("%s\n", data->input_head->line);
		to_free = data->input_head;
		ft_strdel(&data->input_head->line);
		data->input_head = data->input_head->next;
		ft_memdel((void**)&to_free);
	}
	if (!data->input_head || data->input_head->line[0] == '\0')
		return (0);
	ft_printf("%s\n", data->input_head->line);
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
		ft_printf("%s\n", temp->line);
		if (temp->line[0] == 'L')
			return (0);
		if (temp->line[0] != '#' && ft_error_input(temp->line))
			return (0);
		if (temp->line[0] != '#')
			(*vertices)++;
		temp = temp->next;
	}
	if (!temp || !ft_strchr(temp->line, '-'))
		return (0);
	return (1);
}

int				ft_create_data(t_data *data)
{
	if (!(ft_ants(data, 0))
			|| !(ft_vertex_check(data->input_head, &data->vertices))
			|| !ft_create_hash(data)
			|| !ft_create_edges(data))
		return (-1);
	return (1);
}
