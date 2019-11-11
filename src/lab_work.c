/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:38:01 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/10 17:38:30 by azouiten         ###   ########.fr       */
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
	data->queue->next = NULL;
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
		if (edg->connection->visited == 1 || edg->flow == 1)
		{
			edg = edg->next;
			continue ;
		}
		data->queue->last->next = ft_add_queue(data, &edg->connection, &edg, &data->queue->path);
		data->queue->last = data->queue->last->next;
		edg = edg->next;
	}
	if (data->queue->next == NULL)
		return (-1); // needs more work!
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
			data->path->edg->flow = 1;
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
	if (data->groups == NULL)
		group->nbr_id = 1;
	else
		group->nbr_id = data->groups->nbr_id + 1;
	group->t_vrtx = 0;
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
	group = data->groups;
	ft_printf("new group -----------------\n");
	while (group)
	{
		ft_printf("%d\n", group->size);
		while (group->path)
		{
			ft_printf("{%s}[%d]<-", group->path->vertex->name, group->size);
			group->path = group->path->next;
		}
		write (1, "\n", 1);
		group = group->next;
	}
}

void			ft_add_to_agroup(t_data *data)
{
	t_agroups	*all_groups;

	if (!(all_groups = (t_agroups*)malloc(sizeof(t_agroups))))
		ft_exit(data);
	all_groups->group = data->groups;
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
	while (i < 20)// data->agroups->score < data->agroups->next->score!
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
}

int		main(void)
{
	t_data	data;

	ft_parse(&data);
	ft_bfs(&data);
	ft_free_data(&data);
	return (0);
}
// work on optimizing the groups from within!
// huston we have a problem! .. the four links problem! better fix it even if noone is ever gonna find it! 
