/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 21:08:52 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 21:09:46 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void		ft_free_queue(t_data *data)
{
	t_queue	*head_queue;
	t_queue	*temp_queue;

	head_queue = data->free_q;
	while (head_queue)
	{
		temp_queue = head_queue;
		ft_memdel((void**)&temp_queue->path);
		head_queue = head_queue->next;
		ft_memdel((void**)&temp_queue);
	}
	data->free_q = NULL;
}
