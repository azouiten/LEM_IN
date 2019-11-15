/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:53:21 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/15 11:35:06 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

int	ft_print_moves(t_data *data)
{
	t_group	*temp;
	int	gn;

	gn = 0;
	temp = data->result->group;
	if (!(data->array_result = (t_group*)malloc(data->result->n_pths + 1)))
		return (0);
	data->array_result[data->result->n_pths] = NULL;
	while (temp)
	{
		array_result[gn] = temp;
		temp = temp->next;
		gn++;
	}
	gn = 0;
	while (arrqy_result[gn])
	{
		while (data->array_result[gn]->path)
		{
			ft_printf("%s--\n", data->array_result[gn]->path->vertex->name);
			data->array_result[gn]->path =  data->array_result[gn]->path->next;
		}
		gn++;
	}
	return (0);
}
