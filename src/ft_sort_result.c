/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:58:13 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/24 05:05:52 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static int		ft_array_to_list(t_data *data)
{
	t_agroups	*temp;
	t_group		*head;
	int			len;

	len = 1;
	if (!(temp = (t_agroups*)malloc(sizeof(t_agroups))))
		return (0);
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
	return (1);
}

int				ft_sort_result(t_data *data)
{
	if (!ft_list_to_array(data, 0))
		ft_exit(data);
	ft_qsort_group(data, 0, data->result->n_pths - 1);
	if (!(ft_array_to_list(data)))
		ft_exit(data);
	return (1);
}
