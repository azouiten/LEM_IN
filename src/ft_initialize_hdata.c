/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_hdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:25:38 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/30 15:04:52 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void	ft_initialize_hdata(t_data *data)
{
	data->c = 0;
	data->ants = 0;
	data->vertices = 0;
	data->max_hash = 0;
	data->queue = NULL;
	data->free_q = NULL;
	data->hash_table = NULL;
	data->path = NULL;
	data->start = NULL;
	data->end = NULL;
	data->groups = NULL;
	data->input_head = NULL;
	data->visited = NULL;
	data->agroups = NULL;
	data->moving_ant = NULL;
	data->array_result = NULL;
	data->result = NULL;
}
