/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:58:49 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/24 05:11:34 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

int				ft_list_to_array(t_data *data, int gn)
{
	t_group		*temp;

	temp = data->result->group;
	if (!(data->array_result = (t_group**)malloc(sizeof(t_group*)
	* (data->result->n_pths + 1))))
		return (0);
	data->array_result[data->result->n_pths] = NULL;
	while (temp)
	{
		data->array_result[gn] = temp;
		temp = temp->next;
		gn++;
	}
	return (1);
}
