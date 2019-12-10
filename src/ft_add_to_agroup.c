/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_agroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:05:28 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/10 17:12:36 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void			ft_add_to_agroup(t_data *data)
{
	t_agroups	*all_groups;
	t_group		*group;

	if (!(all_groups = (t_agroups*)malloc(sizeof(t_agroups))))
		ft_exit(data);
	all_groups->group = data->groups;
	group = data->groups;
	all_groups->n_vrtx = 0;
	all_groups->n_pths = 0;
	while (group)
	{
		all_groups->n_pths += 1;
		all_groups->n_vrtx += group->size;
		group = group->next;
	}
	all_groups->score = ((all_groups->n_vrtx + data->ants) %
	all_groups->n_pths == 0) ? ((all_groups->n_vrtx + data->ants) /
	all_groups->n_pths) - 1 : ((all_groups->n_vrtx + data->ants) /
		all_groups->n_pths);
	all_groups->next = data->agroups;
	data->agroups = all_groups;
	data->groups = NULL;
}
