/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 04:30:19 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/24 05:08:44 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static void		ft_free_edges(t_vertices **vertex)
{
	t_edges		*temp_edge;
	t_edges		*head_edge;

	if (!(*vertex)->edges)
		return ;
	head_edge = (*vertex)->edges;
	while (head_edge)
	{
		temp_edge = head_edge;
		head_edge = head_edge->next;
		ft_memdel((void**)&temp_edge);
	}
}

static void		ft_free_htable(t_data *data)
{
	int			hn;
	t_vertices	*temp;

	hn = 0;
	while (hn < data->vertices)
	{
		if (!data->hash_table[hn])
		{
			hn++;
			continue ;
		}
		while (data->hash_table[hn])
		{
			ft_strdel(&(data->hash_table[hn]->name));
			ft_free_edges(&(data->hash_table[hn]));
			temp = data->hash_table[hn]->next;
			ft_memdel((void**)&(data->hash_table[hn]));
			data->hash_table[hn] = temp;
		}
		hn++;
	}
	free(data->hash_table);
	data->hash_table = 0;
}

void		ft_free_queue(t_data *data)
{
	t_queue *head_queue;
	t_queue *temp_queue;

	head_queue = data->free_q;
	while (head_queue)
	{
		temp_queue = head_queue;
		ft_memdel((void**)&temp_queue->path);
		head_queue = head_queue->next;
		ft_memdel((void**)&temp_queue);
	}
}


int				ft_free_data(t_data *data)
{
	t_input		*head_copy;
	t_input		*temp;
	t_v_buffer	*tmp;
	//t_group		*tmpo;// free the paths in groups

	head_copy = data->input_head;
	/*while (data->groups)
	{
		tmpo = data->groups;
		data->groups = data->groups->next;
		ft_memdel((void**)&tmpo);
	}*/
	while (head_copy)
	{
		temp = head_copy;
		ft_strdel(&(head_copy->line));
		head_copy = head_copy->next;
		ft_memdel((void**)&temp);
	}
	if (data->hash_table)
		ft_free_htable(data);
	if (data->queue)
		ft_free_queue(data);
	while (data->visited)
	{
		tmp = data->visited;
		data->visited = data->visited->next;
		ft_memdel((void**)&tmp);
	}
	if (data->moving_ant)
		ft_memdel((void**)&data->moving_ant);
	if (data->array_result)
		ft_memdel((void**)&data->array_result);
	if (data->result)
		ft_memdel((void**)&data->result);
	return (0);
}














