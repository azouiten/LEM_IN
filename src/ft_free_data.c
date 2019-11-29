/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 04:30:19 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/29 20:32:23 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

int j = 0;

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
	data->free_q = NULL;
}

void			ft_free_path(t_group *group)
{
	t_path	*pth;
	t_path	*tmp;

	tmp = NULL;
	pth = group->path;
	while (pth)
	{
		tmp = pth;
		pth = pth->next;
		ft_memdel((void**)&tmp);
	}
}

void			ft_free_group(t_agroups *agroup)
{
	t_group	*grp;
	t_group	*tmp;

	tmp = NULL;
	grp = agroup->group;
	while (grp)
	{
		ft_printf("%d\n", j++);
		ft_free_path(grp);
		tmp = grp;
		grp = grp->next;
		ft_memdel((void**)&tmp);
	}
	ft_printf("++++++++++++++++++++++++++++++\n");
}

void			ft_free_agroups(t_data *data)
{
	t_agroups	*agps;
	t_agroups	*tmp;

	tmp = NULL;
	agps = data->agroups;
	while (agps)
	{
		ft_free_group(agps);
		tmp = agps;
		agps = agps->next;
		ft_memdel((void**)&tmp);
	}
}

int				ft_free_data(t_data *data)
{
	t_input		*head_copy;
	t_input		*temp;
	t_v_buffer	*tmp;

	if (data->agroups)
		ft_free_agroups(data);
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
	while (data->visited)
	{
		tmp = data->visited;
		data->visited = data->visited->next;
		ft_memdel((void**)&tmp);
	}
	if (data->moving_ant)
		ft_memdel((void**)&data->moving_ant);
	if (data->array_result)
	{
		ft_printf("yikes\n");
		ft_memdel((void**)&data->array_result);
	}
	if (data->result)
	{
		//ft_free_group(data->result);
//		ft_memdel((void**)&data->result);
	}
	return (0);	
}
