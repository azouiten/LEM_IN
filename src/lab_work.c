/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:38:01 by azouiten          #+#    #+#             */
/*   Updated: 2019/10/08 14:51:01 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"
#include <stdio.h>

void			ft_exit(t_data *data)
{
	write(1 ,"ERROR\n", 6);
	ft_free_data(data);
	exit(1);
}

static	void	ft_init_queue(t_data *data)
{
	if (!(data->queue = (t_queue*)malloc(sizeof(t_queue))))
		ft_exit(data);
	if (!(data->queue->path = ft_strdup(data->start->name)))
		ft_exit(data);
	if (!(data->queue->last = (t_queue*)malloc(sizeof(t_queue))))
		ft_exit(data);
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
		if (edg->status == 0 || edg->connection->status == 0)
		{
			edg = edg->next;
			continue ;		
		}
		data->queue->last->next = ft_add_queue(data, &edg->connection, data->queue->path);
		data->queue->last = data->queue->last->next;
		edg = edg->next;
	}
	ft_printf("{%s}\n", data->queue->item->name);
	if (data->queue->next == NULL)
		return (1);
	data->queue->next->last = data->queue->last;
	queue = data->queue;
	data->queue = data->queue->next;
	free(queue->path);
	free(queue);
	return (0);
}

void			ft_bfs(t_data *data)
{
	int	i;

	i = 0;
	ft_init_queue(data);
	while (!ft_check_last(data));
	printf("path : %s\n", data->queue->path);
}

int		main(void)
{
	t_data	data;

	ft_parse(&data);
	ft_bfs(&data);
	return (0);
}
