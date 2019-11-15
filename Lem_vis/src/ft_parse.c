/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:26:34 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/13 18:41:43 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

void	ft_parse(t_data *data)
{
	ft_initialize_hdata(data);
	if (ft_get_input(data) == -1 || ft_create_data(data) == -1
			|| !data->start || !data->end)
	{
		ft_printf("ERROR\n");
		ft_free_data(data);
		exit(0);
	}
	ft_normalize_vertices(data);
	data->moves_head = data->input_head;
	while (data->moves_head && data->moves_head->line[0] != 'L')
		data->moves_head = data->moves_head->next;
	data->remember_moves = data->moves_head;
	if (!data->moves_head
	|| !(data->motion_ant = (t_ants*)malloc(sizeof(t_ants) * data->ants)))
	{
		ft_printf("ERROR\n");
		ft_free_data(data);
		exit(0);
	}
	ft_init_ants(data);
}
