/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 04:30:19 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/07 12:44:43 by ohachim          ###   ########.fr       */
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

static void	ft_free_queue(t_data *data)
{
        t_queue *head_queue;
        t_queue *temp_queue;
	t_paths	*temp_path;

        head_queue = data->queue;
        while (head_queue)
        {
		while (head_queue->path)
		{
			temp_path = head_queue->path;
			ft_strdel(&head_queue->path->path);
			head_queue->path = head_queue->path->next;
			ft_memdel((void**)&temp_path);
		}
                temp_queue = head_queue;
                head_queue = head_queue->next;
                ft_memdel((void**)&temp_queue);
        }
}

static void	ft_free_paths(t_data *data)
{
	t_paths *head_path;
	t_paths *temp_path;

	head_path = data->paths;
	while (head_path)
	{
		temp_path = head_path;
		ft_strdel(&head_path->path);
		head_path = head_path->next;
		ft_memdel((void**)&temp_path);
	}
}

int				ft_free_data(t_data *data)
{
	t_input		*head_copy;
	t_input		*temp;

	head_copy = data->input_head;
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
	if (data->paths)
		ft_free_paths(data);
	return (0);
}














