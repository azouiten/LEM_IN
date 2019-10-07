/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:38:01 by azouiten          #+#    #+#             */
/*   Updated: 2019/10/07 20:27:25 by azouiten         ###   ########.fr       */
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
	ft_printf("data queue last item  name %s, data-queue item name %s\n", data->queue->last->item->name, data->queue->item->name);
	data->queue->next = NULL;
}

static	int		ft_check_last(t_data *data)
{
	t_vertices	*ptr;
	t_queue		*tmp;

	write(1, "first in\n", 8);	
	ptr = data->queue->item;
	if (ptr == data->end)
		return (0);
	tmp = data->queue;
	write(1, "while in\n", 8);
	while (ptr->edges)
	{
		if (!(tmp->last->next = (t_queue*)malloc(sizeof(t_queue))))
			ft_exit(data);
		if (!(tmp->last->next->path = ft_strjoin(ptr->edges->connection->name,
							tmp->item->name)))
			ft_exit(data);
		//if (!(tmp->last->next-> = (t_queue*)malloc(sizeof(t_queue))))
		//	ft_exit(data);
		write(1, "checkpoint0\n", 12);
		tmp->last->next->item = ptr->edges->connection;
		tmp->last->last = NULL;

		tmp->next->last = tmp->last->next;
		write(1, "checkpoint1\n", 12);
		tmp->last = tmp->last->next;
		ptr->edges = ptr->edges->next;
		tmp = tmp->next;
		write(1, "checkpoint2\n", 12);
	}
	write(1, "first out\n", 9);
	tmp = data->queue;
	data->queue = data->queue->next;
	free(tmp->path);
	free(tmp->item);
	free(tmp);
	return (1);
}

void			ft_bfs(t_data *data)
{
	ft_init_queue(data);
	while (ft_check_last(data));
	printf("path : %s\n", data->queue->path);
	//ft_exit(data);
}

int		main(void)
{
	t_data	data;

	ft_parse(&data);
	ft_bfs(&data);
	return (0);
}
