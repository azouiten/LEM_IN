/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:38:01 by azouiten          #+#    #+#             */
/*   Updated: 2019/10/11 19:40:50 by azouiten         ###   ########.fr       */
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
	if (!(data->queue->path = ft_strdup(data->start->name)))
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
		if (!edg->status || !edg->connection->status || edg->connection->visited == 1)
		{
			edg = edg->next;
			continue ;
		}
		data->queue->last->next = ft_add_queue(data, &edg->connection, data->queue->path); // Must check for NULL return.
		data->queue->last = data->queue->last->next;
		edg = edg->next;
	}
	if (data->queue->next == NULL)
		ft_exit(data);
	data->queue->next->last = data->queue->last;
	queue = data->queue;
	data->queue = data->queue->next;
	ft_memdel((void**)&queue->path);
	ft_memdel((void**)&queue);
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
/*
void	ft_find_patch(t_data *data)
{
	char		**str;
	t_vertices	*ptr1;
	t_vertices	*ptr2;
	t_edges		*edg;

	ptr = NULL;
	if (!(str = ft_split(data->queue->path)))
		ft_exit(data);
	while (str[i] != NULL)
	{
		ptr1 = data->hashtab[ft_hash_it(str[i], data->vertices)];
		ptr2 = data->hashtab[ft_hash_it(str[i + 1], data->vertices)];
		edg = ptr->edges;
		while (edg)
		{
			if (edg->connection == ptr2)
			{
				edg->flow = 1;
				break ;
			}
		}
	}
}
*/
int		main(void)
{
	t_data	data;

	ft_parse(&data);
	ft_bfs(&data);
	//ft_find_patch(&data);
	ft_free_data(&data);
	return (0);
}
