 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_vertex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:03:27 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/07 21:56:22 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static int		ft_find_duplicat(t_data *data, int hash, char *line)
{
	t_vertices	*temp;
	char		*name;

	if (!(name = ft_extract_name(line)))
		return (0);
	temp = data->hash_table[hash];
	while (temp)
	{
		if (!ft_strcmp(temp->name, name))
			return (1);
		temp = temp->next;
	}
	ft_strdel(&name);
	return (0);
}

static int		ft_first_node(t_data *data, int hash, char *line,
		int vertex_position)
{
	while (data->hash_table[hash])
		data->hash_table[hash] = data->hash_table[hash]->next;
	if (!(data->hash_table[hash] = (t_vertices*)malloc(sizeof(t_vertices))))
		return (0);
	if (!(data->hash_table[hash]->name = ft_extract_name(line)))
		return (0);
	data->hash_table[hash]->status = 1;
	data->hash_table[hash]->hash = hash;
	data->hash_table[hash]->next = NULL;
	data->hash_table[hash]->edges = NULL;
	if (vertex_position == 0)
	{
		if (data->start)
			return (0);
		data->start = data->hash_table[hash];
	}
	if (vertex_position == 9)
	{
		if (data->end)
			return (0);
		data->end = data->hash_table[hash];
	}
	return (1);
}

int				ft_append_vertex(t_data *data, int hash, char *line,
		int vertex_position)
{
	t_vertices	*current;

	if (!data->hash_table[hash])
		return (ft_first_node(data, hash, line, vertex_position));
	else
	{
		if (ft_find_duplicat(data, hash, line))
			return (0);
		current = data->hash_table[hash];
		while (current->next)
			current = current->next;
		if (!(current->next = (t_vertices*)malloc(sizeof(t_vertices)))
			|| !(current->next->name = ft_extract_name(line)))
			return (0);
		current->next->status = 1;
		current->next->hash = hash;
		current->next->next = NULL;
		current->next->edges = NULL;
		if (vertex_position == 0) // gotta check for double start/end.
			data->start = current->next;
		else if (vertex_position == 9)
			data->end = current->next;
	}
	return (1);
}
