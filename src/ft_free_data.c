/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 04:30:19 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/06 19:08:56 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static int		ft_free_edges(t_vertices **vertex)
{
	t_edges		*temp_edge;
	t_edges		*head_edge;

	if (!(*vertex)->edges)
		return (0);
	head_edge = (*vertex)->edges;
	while (head_edge)
	{
		temp_edge = head_edge;
		head_edge = head_edge->next;
		ft_memdel((void**)&temp_edge);
	}
	return (1);
}

static int		ft_free_htable(t_data *data)
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
	return (0);
}

static void	ft_free_queue(t_data *data)
{
        t_queue *head_queue;
        t_queue *temp_queue;

        head_queue = data->queue;
        while (head_path)
        {
                temp = head_queue;
               	ft_free_paths(head_queue->path);
                head_path = head_path->next;
                ft_memdel((void**)&temp);
        }
}

static void	ft_free_paths(t_data *data)
{
	t_paths *head_path;
	t_paths *temp_path;

	head_path = data->paths;
	while (head_path)
	{
		temp = head_path;
		ft_strdel(&head_path->path);
		head_path = head_path->next;
		ft_memdel((void**)&temp);
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














