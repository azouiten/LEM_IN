/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:39:38 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/08 15:44:51 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

t_queue	*ft_add_queue(t_data *data, t_vertices **vertex, char *path)
{
	t_queue *queue;
	char	*temp;

	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		ft_exit(data);
	queue->item = *vertex;
	(*vertex)->visited = 1;
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
