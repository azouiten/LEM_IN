/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_edges.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:17:10 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/14 01:16:32 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static t_edges	*ft_create_connection(t_vertices **edge_end)
{
	t_edges		*edge;

	if (!(edge = (t_edges*)malloc(sizeof(t_edges))))
		return (0);
	edge->status = 1;
	edge->connection = *edge_end;
	edge->next = NULL;
	return (edge);
}

static t_edges		*ft_assign_connection(t_vertices **end1, t_vertices **end2)
{
	t_edges		*temp_edge;

	if (!((*end1)->edges))
	{
		if (!((*end1)->edges = ft_create_connection(end2)))
			return (0);
		return ((*end1)->edges);
	}
	temp_edge = (*end1)->edges;
	while (temp_edge->next)
		temp_edge = temp_edge->next;
	if (!(temp_edge->next = (t_edges*)malloc(sizeof(t_edges))))
		return (0);
	temp_edge->next->status = 1;
	temp_edge->next->connection = *end2;
	temp_edge->next->next = NULL;
	return (temp_edge->next);
}

static int		ft_finish_assign(char **name, char **connection,
						t_vertices **temp_name, t_vertices **temp_connection)
{
	t_edges	*temp_edge0;
	t_edges	*temp_edge1;

	while (*temp_name && ft_strcmp((*temp_name)->name, *name))
		*temp_name = (*temp_name)->next;
	while (*temp_connection && ft_strcmp((*temp_connection)->name, *connection))
		*temp_connection = (*temp_connection)->next;
	if (!(temp_edge0 = ft_assign_connection(temp_name, temp_connection))
		|| !(temp_edge1 = ft_assign_connection(temp_connection, temp_name)))
		return (0);
	temp_edge0->edge_end = temp_edge1;
	temp_edge1->edge_end = temp_edge0;
	ft_strdel(name);
	ft_strdel(connection);
	return (1);
}

static int		ft_make_connection(t_data *data, t_input *put,
					int hash_name, int hash_connection)
{
	char		*nod;
	char		*connection;
	t_vertices	*temp_name;
	t_vertices	*temp_connection;

	while (put)
	{
		if (put->line[0] == '#' && (put = put->next))
			continue ;
		else if (!put)
			break ;
		if (!ft_strchr(put->line, '-') || !(nod = ft_extract_edge(put->line))
			|| !(connection = ft_extract_connection(put->line))
			|| !(ft_check_validity(data, nod, connection)))
			return (0);
		if ((((hash_name = ft_hash_it(nod, data->vertices)) == -1))
		|| ((hash_connection = ft_hash_it(connection, data->vertices)) == -1))
			return (0);
		if (!(temp_name = data->hash_table[hash_name]) ||
		!(temp_connection = data->hash_table[hash_connection]) ||
		!(ft_finish_assign(&nod, &connection, &temp_name, &temp_connection)))
			return (0);
		put = put->next;
	}
	return (1);
}

int				ft_create_edges(t_data *data)
{
	t_input		*temp;

	if (!data->input_head)
		return (0);
	temp = data->input_head;
	while (!ft_strchr(temp->line, '-'))
		temp = temp->next;
	if (!ft_make_connection(data, temp, 0, 0))
		return (0);
	return (1);
}
