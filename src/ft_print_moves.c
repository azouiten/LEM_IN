/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:53:21 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/15 13:52:55 by ohachim          ###   ########.fr       */
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
	}
	return (0);
}

int	ft_print_moves(t_data *data)
{
	t_group	*temp;
	int	gn;

	gn = 0;
	temp = data->result->group;
	if (!(data->array_result = (t_group**)malloc(sizeof(t_group*) * data->result->n_pths + 1)) || ft_init_ants(data))
		return (0);
	data->array_result[data->result->n_pths] = NULL;
	while (temp)
	{
		data->array_result[gn] = temp;
		temp = temp->next;
		gn++;
	}
	//ft_qsort

	return (0);
}
