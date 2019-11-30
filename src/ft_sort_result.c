/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:58:13 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/30 15:30:26 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static int		ft_array_to_list(t_data *data, t_agroups *temp,
		t_group *head, int len)
{
	if (!(temp = (t_agroups*)malloc(sizeof(t_agroups))))
		return (0);
	temp->n_vrtx = data->result->n_vrtx;
	temp->n_pths = data->result->n_pths;
	temp->score = data->result->score;
	temp->next = (data->c == -1) ? data->agroups->next : data->agroups->next->next;
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
	ft_memdel((void**)&data->result);
	data->result = temp;
	if (data->c == -1)
		data->agroups = data->result;
	else
		data->agroups->next = data->result;
	return (1);
}

int				ft_sort_result(t_data *data)
{
	t_agroups	*temp;
	t_group		*head;
	int		len;

	if (!ft_list_to_array(data, 0))
		ft_exit(data);
	ft_qsort_group(data, 0, data->result->n_pths - 1);
	if (!(ft_array_to_list(data, temp, head, 1)))
		ft_exit(data);
	return (1);
}
