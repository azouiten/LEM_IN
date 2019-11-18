/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:58:13 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/18 17:27:41 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static void	ft_array_to_list(t_data *data)
{
	t_agroups *temp;
	t_group *head;
	int	len;

	len = 1;
	temp = (t_agroups*)malloc(sizeof(t_agroups)); // Check NULL;
	temp->n_vrtx = data->result->n_vrtx;
	temp->n_pths = data->result->n_pths;
	temp->score = data->result->score;
	temp->next = NULL;
	temp->group = data->array_result[0];
	head = temp->group;
	while (len < data->result->n_pths)
	{
		temp->group->next = data->array_result[len];
		temp->group = temp->group->next;
		len++;
	}
	temp->group->next = NULL;
	temp->group = head;
	data->result = temp;
}

int	ft_sort_result(t_data *data)
{
	if (!ft_list_to_array(data, 0))
		return (0);
	ft_qsort_group(data, 0, data->result->n_pths - 1);
	ft_array_to_list(data);
	return (1);
}
