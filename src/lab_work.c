/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:38:01 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/15 11:52:34 by ohachim          ###   ########.fr       */
/*   Updated: 2019/11/15 11:30:37 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"
#include <stdio.h>

void			ft_exit(t_data *data) // Must get its own file.
{
	write(1 ,"ERROR\n", 6);
	ft_free_data(data);
	exit(1);
}

static	void	ft_init_queue(t_data *data)
{
	if (!(data->queue = (t_queue*)malloc(sizeof(t_queue))))
		ft_exit(data);
	if (!(data->queue->path = (t_path*)malloc(sizeof(t_path))))
		ft_exit(data);
	data->free_q = data->queue;
	data->queue->path->vertex = data->start;
	data->queue->path->edg = data->start->edges;// maybe use null
	data->queue->path->next = NULL;
	data->queue->item = data->start;
	data->queue->last = data->queue;
	data->queue->access = 0;
	data->queue->next = NULL;
	data->start->visited = 1; // end quit.
}

static	int		ft_check_last(t_data *data)
{
	t_edges	*edg;
	t_queue	*queue;

	edg = data->queue->item->edges;
	if (data->queue->item == data->end)
		return (1);
	while (edg)
	{
		if (edg->connection->visited == 1 || edg->flow == 1 || (data->queue->item->flow == 1 && data->queue->access == 0 && edg->edge_end->flow == 0))
		{
			edg = edg->next;
			continue ;
		}
		data->queue->last->next = ft_add_queue(data, &edg->connection,
				&edg, &data->queue->path);
		data->queue->last = data->queue->last->next;
		edg = edg->next;
	}
	if (data->queue->next == NULL)
		return (-1);
	data->queue->next->last = data->queue->last;
	queue = data->queue;
	data->queue = data->queue->next;
	return (0);
}

void			ft_add_flow(t_data *data)
{
	t_edges	*edg;

	edg = data->start->edges;
	while (data->path && data->path->vertex != data->start)
	{
		if (data->path->edg->edge_end->flow == 1)
			data->path->edg->edge_end->flow = 0;
		else
		{
			data->path->edg->flow = 1;
			if (data->path->edg->connection != data->end && data->path->edg->connection != data->start)
				data->path->vertex->flow = 1;
		}
		data->path = data->path->next;
	}
}

void	ft_flush_vbuffer(t_data *data)
{
	t_v_buffer	*buff;
	t_v_buffer	*tmp;

	tmp = NULL;
	buff = data->visited;
	while (buff)
	{
		buff->vertex->visited = 0;
		tmp = buff;
		buff = buff->next;
		ft_memdel((void**)&tmp);
	}
	data->visited = NULL;
}

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

void			ft_collect_paths(t_data *data)
{
	t_edges	*edg;
	t_group	*group;

	edg = data->start->edges;
	while (edg)
	{
		if (edg->flow == 1)
			ft_add_path(data, edg->connection);	
		edg = edg->next;
	}
	group = data->groups;
	edg = group->path->vertex->edges;
	while (group)
	{
		edg = group->path->vertex->edges;
		while (!edg || (edg->connection != data->end && edg->edge_end->connection != data->end))
		{
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

void			ft_add_to_agroup(t_data *data)
{
	t_agroups	*all_groups;
	t_group		*group;

	if (!(all_groups = (t_agroups*)malloc(sizeof(t_agroups))))
		ft_exit(data);
	all_groups->group = data->groups;
	group = data->groups;
	all_groups->n_vrtx = 0;
	all_groups->n_pths = 0;
	while (group)
	{
		all_groups->n_pths += 1;
		all_groups->n_vrtx += group->size;
		group = group->next;
	}
	all_groups->score = (((all_groups->n_vrtx + data->ants) / all_groups->n_pths)
			+ (all_groups->n_vrtx + data->ants) % all_groups->n_pths) - 1;
	all_groups->next = data->agroups;
	data->agroups = all_groups;
	data->groups = NULL;
}

void			ft_bfs(t_data *data)
{
	int	i;
	t_path *path;
	int	c;

	c = 0;
	i = 0;
	while (!data->agroups || !data->agroups->next || data->agroups->score <=
			data->agroups->next->score)// data->agroups->score < data->agroups->next->score!
	{
		i++;
		ft_init_queue(data);
		while ((c = ft_check_last(data)) == 0);
		if (c == -1)
			break ;
		path = data->queue->path;
		data->path = data->queue->path;
		ft_flush_vbuffer(data);
		ft_add_flow(data);
		ft_collect_paths(data);
		ft_add_to_agroup(data);
	}
	if (c == -1 && !data->agroups)
		ft_exit(data);
	else if ((data->agroups && !data->agroups->next) || (data->agroups->next &&
			data->agroups->score <= data->agroups->next->score))
		data->result = ft_swing_paths(data, data->agroups);	
	else if (data->agroups->next && data->agroups->score > data->agroups->next->score)
		data->result = ft_swing_paths(data, data->agroups->next);
}

//void	ft_free_path()
//{}

t_agroups	*ft_swing_paths(t_data *data, t_agroups *agroup)
{
	t_path	*path_rep;
	t_path	*tmp;
	t_path	*pth;
	t_group	*group;

	path_rep = NULL;
	tmp = NULL;
	group = agroup->group;
	while (group)
	{
		pth = group->path;
		tmp = NULL;
		while (group->path)
		{
			if (!(path_rep = (t_path*)malloc(sizeof(t_path))))
				ft_exit(data);
			path_rep->vertex = group->path->vertex;
			path_rep->edg = NULL;
			path_rep->next = tmp;
			tmp = path_rep;
			group->path = group->path->next;
		}
		//ft_free_path(pth);
		group->path = path_rep;	
		group = group->next;
	}
	return (agroup);
}

int		main(void)
{
	t_data	data;

	ft_parse(&data);
	ft_bfs(&data);
	ft_print_moves(&data);
//	ft_free_data(&data);
	ft_free_data(&data);
	return (0);
}
// work on optimizing the groups from within!
