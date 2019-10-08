/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:39:38 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/08 16:37:19 by ohachim          ###   ########.fr       */
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

static int	ft_add_vbuffer(t_data *data, t_vertices **vertex)
{
	t_v_buffer	*visited;

	/*if (!data->visted)
	{
		if (!(data->visited = ft_visited_node(data, vertex)))
			return (0);
		return (1);
	}*/
	if (!(visited = ft_visited_node(vertex)))
		return (0);
	visited->next = data->visited;
	data->visited = visited;
	return (1);
}

t_queue	*ft_add_queue(t_data *data, t_vertices **vertex, char *path)
{
	t_queue *queue;
	char	*temp;

	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		ft_exit(data);
	queue->item = *vertex;
	if (!(ft_add_vbuffer(data, vertex)))
		return (0);
	if (!(queue->path = ft_strjoin(path, " ")))
		ft_exit(data);
	temp = queue->path;
	if (!(queue->path = ft_strjoin(queue->path, (*vertex)->name)))
		ft_exit(data);
	ft_strdel(&temp);
	queue->last = NULL;
	queue->next = NULL;
	return (queue);
}
