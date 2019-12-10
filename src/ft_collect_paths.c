/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:00:19 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/10 17:43:44 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void			ft_add_path(t_data *data, t_vertices *vertex)
{
	t_group	*group;
	t_path	*path;

	if (!(group = (t_group*)malloc(sizeof(t_group))))
		ft_exit(data);
	if (!(path = (t_path*)malloc(sizeof(t_path))))
		ft_exit(data);
	path->vertex = vertex;
	path->edg = NULL;
	path->next = NULL;
	group->path = path;
	group->size = 1;
	group->load = 0;
	group->next = data->groups;
	data->groups = group;
}

void			ft_add_to_path(t_data *data, t_group *group, t_vertices *vertex)
{
	t_path	*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		ft_exit(data);
	path->vertex = vertex;
	path->edg = NULL;
	path->next = group->path;
	group->path = path;
	group->size++;
}

static	void	ft_head_group(t_data *data, t_edges *edg)
{
	while (edg)
	{
		if (edg->flow == 1)
			ft_add_path(data, edg->connection);
		edg = edg->next;
	}
}

void			ft_collect_paths(t_data *data, t_edges *edg, t_group *group, int a)
{
	edg = data->start->edges;
	ft_head_group(data, edg);
	group = data->groups;
	while (group)
	{
		a = 0;
		edg = group->path->vertex->edges;
		while (!edg || (edg->connection != data->end &&
	edg->edge_end->connection != data->end)
				|| (a == 0 && group->path->vertex != data->end))
		{
			a++;
			edg = group->path->vertex->edges;
			while (edg)
			{
				if (edg->flow == 1)
				{
					ft_add_to_path(data, group, edg->connection);
					break ;
				}
				edg = edg->next;
			}
		}
		group = group->next;
	}
}
