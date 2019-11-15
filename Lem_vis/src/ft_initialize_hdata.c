/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_hdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:25:38 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/08 04:40:57 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

void	ft_initialize_hdata(t_data *data)
{
	data->ants = 0;
	data->vertices = 0;
	data->max_hash = 0;
	data->max_y = 0;
	data->max_x = 0;
	data->hash_table = NULL;
	data->start = NULL;
	data->end = NULL;
	data->input_head = NULL;
	data->moves_head = NULL;
	data->motion_ant = NULL;
	data->vertex_ray = NULL;
	data->room_size = 50;
}
