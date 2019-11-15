/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:53:21 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/15 18:55:37 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h" // Care for headers.

static int	ft_init_ants(t_data *data)
{
	int	an;

	an = 0;
	if (!(data->moving_ant = (t_ants*)malloc(sizeof(t_ants) * data->ants)))
		return (0);
	while (an < data->ants)
	{
		data->moving_ant[an].path = 0;
		data->moving_ant[an].in_end = 0;
		an++;
	}
	return (1);
}

void	ft_init_paths(t_data *data)
{
	int	gn;

	gn = 0;
	while (gn < data->result->n_pths)
	{
		data->array_result[gn]->path->status = 0;
		gn++;
	}
}
static int	ft_find_ant_path(t_data *data, int ant_index) // Will be improved.
{
	int	gn;

	gn = 0;
	while (gn < data->result->n_pths)
	{
		if (data->array_result[gn]->path->status == 0)
		{
			if (data->array_result[gn]->load != 0)
			{
				data->moving_ant[ant_index].path = data->array_result[gn]->path;
				data->array_result[gn]->load--;
			}
			else
				break ;
			return (1);
		}
		gn++;
	}
	return (0);
}

int	ft_print_moves(t_data *data)
{
	t_group	*temp;
	int	gn;
	int	ant_index;
	int	arrived;
	int	si;

	si = 0;
	gn = 0;
	temp = data->result->group;
	if (!(data->array_result = (t_group**)malloc(sizeof(t_group*) * data->result->n_pths + 1)) || !ft_init_ants(data))
		return (0);
	data->array_result[data->result->n_pths] = NULL;
	while (temp)
	{
		data->array_result[gn] = temp;
		temp = temp->next;
		gn++;
	}
	ft_qsort_group(data, 0, data->result->n_pths - 1);
	arrived = 0;
	while (arrived != data->ants)
	{
		ant_index = 0;
		ft_init_paths(data);
		si = 0;
		while (ant_index < data->ants)
		{
			if (data->moving_ant[ant_index].path == 0)
			{
				if (!(ft_find_ant_path(data, ant_index)))
					break ;
			}
			if (data->moving_ant[ant_index].in_end == 0)
			{
				if (!ft_strcmp(data->moving_ant[ant_index].path->vertex->name, data->end->name))
				{
					data->moving_ant[ant_index].in_end = 1;
					arrived++;
				}
				if (si > 0)
					ft_printf(" ");
				si++;
				ft_printf("L%d-%s", ant_index + 1, data->moving_ant[ant_index].path->vertex->name);
				if (ft_strcmp(data->moving_ant[ant_index].path->vertex->name, data->end->name))
					data->moving_ant[ant_index].path->status = 1;
				data->moving_ant[ant_index].path = data->moving_ant[ant_index].path->next;
			}
			ant_index++;
		}
		ft_printf("\n");
	}
	return (0);
}
