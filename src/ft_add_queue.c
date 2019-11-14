/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:39:38 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/13 18:51:44 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static t_v_buffer	*ft_visited_node(t_vertices **vertex)
{
	t_v_buffer *node;

	if (!(node = (t_v_buffer*)malloc(sizeof(t_v_buffer))))
		return (0);
	node->vertex = *vertex;
	node->vertex->visited = 1;
	node->next = NULL;
	return (node);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * is v_buffer smthing u want, is it the best u can do ? *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static int	ft_add_vbuffer(t_data *data, t_vertices **vertex)
{
	t_v_buffer	*visited;

	if (!(visited = ft_visited_node(vertex)))
		return (0);
	visited->next = data->visited;
	data->visited = visited;
	return (1);
}

t_queue	*ft_add_queue(t_data *data, t_vertices **vertex, t_edges **edg, t_path **pth)
{
	t_queue *queue;

	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		ft_exit(data);
	queue->item = *vertex;
	if ((*vertex)->flow == 1 && (*edg)->connection->flow == 1)
		queue->access = 1;
	else
		queue->access = 0;
	if (!(ft_add_vbuffer(data, vertex)))
		return (0);
	if (!(queue->path = (t_path*)malloc(sizeof(t_path))))
		ft_exit(data);
	queue->path->vertex = *vertex;
	queue->path->edg = *edg;
	queue->path->next = *pth;
	queue->last = NULL;
	queue->next = NULL;
	return (queue);
}
