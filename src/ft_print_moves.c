/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:11:52 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/21 18:37:35 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static int		ft_init_ants(t_data *data)
{
	int			an;

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

void			ft_init_paths(t_data *data)
{
	int			gn;

	gn = 0;
	while (gn < data->result->n_pths)
	{
		data->array_result[gn]->status = 0;
		gn++;
	}
}

static int		ft_find_ant_path(t_data *data, int ant_index)
{
	int			gn;

	gn = 0;
	while (gn < data->result->n_pths)
	{
		if (data->array_result[gn]->status == 0)
		{
			if (data->array_result[gn]->load > 0)
			{
				data->moving_ant[ant_index].path = data->array_result[gn]->path;
				data->array_result[gn]->load--;
				data->array_result[gn]->status = 1;
				return (1);
			}
		}
		gn++;
	}
	return (0);
}

static void		ft_move(t_data *data, int ant_index, int si, int *arrived)
{
	while (ant_index < data->ants)
	{
		if (data->moving_ant[ant_index].in_end == 1 && (ant_index += 1))
			continue ;
		if (data->moving_ant[ant_index].path == 0)
			if (!(ft_find_ant_path(data, ant_index)))
				break ;
		if (data->moving_ant[ant_index].in_end == 0)
		{
			if (!ft_strcmp(data->moving_ant[ant_index].path->vertex->name,
						data->end->name) && (*arrived = *arrived + 1))
				data->moving_ant[ant_index].in_end = 1;
			if (si > 0)
				ft_printf(" ");
			si++;
			ft_printf("L%d-%s", ant_index + 1,
					data->moving_ant[ant_index].path->vertex->name);
			if (data->moving_ant[ant_index].path->next != NULL)
				data->moving_ant[ant_index].path =
				data->moving_ant[ant_index].path->next;
		}
		ant_index++;
	}
}

int				ft_print_moves(t_data *data, int ant_index, int si, int arrived)
{
	if (!(ft_init_ants(data)))
		return (0);
	ft_printf("\n");
	while (arrived != data->ants)
	{
		ant_index = 0;
		ft_init_paths(data);
		ft_move(data, ant_index, 0, &arrived);
		ft_printf("\n");
	}
	return (1);
}
