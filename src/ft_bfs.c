/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:13:18 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 19:01:44 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static	void		ft_init_queue(t_data *data)
{
	if (!(data->queue = (t_queue*)malloc(sizeof(t_queue))))
		ft_exit(data);
	if (!(data->queue->path = (t_path*)malloc(sizeof(t_path))))
		ft_exit(data);
	data->free_q = data->queue;
	data->queue->path->vertex = data->start;
	data->queue->path->edg = data->start->edges;
	data->queue->path->next = NULL;
	data->queue->item = data->start;
	data->queue->last = data->queue;
	data->queue->access = 0;
	data->queue->next = NULL;
	data->start->visited = 1;
}

static	int			ft_check_last(t_data *data, t_queue *queue)
{
	t_edges	*edg;

	edg = data->queue->item->edges;
	if (data->queue->item == data->end)
		return (1);
	while (edg)
	{
		if (edg->connection->visited == 1 || edg->flow == 1 ||
				(data->queue->item->flow == 1 && data->queue->access == 0
				&& edg->edge_end->flow == 0))
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

static	t_agroups	*ft_result(t_data *data)
{
	if ((data->agroups && !data->agroups->next) || (data->agroups->next &&
			data->agroups->score <= data->agroups->next->score))
		return (ft_swing_paths(data, data->agroups));
	else if (data->agroups->next && data->agroups->score >
			data->agroups->next->score)
		return (ft_swing_paths(data, data->agroups->next));
	return (NULL);
}

void				ft_bfs(t_data *data)
{
	t_path	*path;
	t_queue	*queue;

	while (!data->agroups || !data->agroups->next ||
			data->agroups->score <= data->agroups->next->score)
	{
		ft_init_queue(data);
		while ((data->c = ft_check_last(data, queue)) == 0)
			;
		if (data->c == -1)
			break ;
		path = data->queue->path;
		data->path = data->queue->path;
		ft_flush_vbuffer(data);
		ft_add_flow(data);
		ft_collect_paths(data);
		ft_add_to_agroup(data);
		ft_free_queue(data);
	}
	if (data->c == -1 && !data->agroups)
		ft_exit(data);
	data->result = ft_result(data);
	ft_sort_result(data);
	ft_enhance_groups(data);
}
