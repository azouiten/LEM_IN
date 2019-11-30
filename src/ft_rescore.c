/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rescore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:44:10 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 20:52:24 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

int			ft_rescore(t_data *data, t_group *group)
{
	t_group	*grp;
	int		n_pths;
	int		n_vrtx;

	n_pths = 0;
	n_vrtx = 0;
	grp = data->result->group;
	while (grp)
	{
		n_vrtx += grp->size - 1;
		n_pths++;
		if (group == grp)
			break ;
		grp = grp->next;
	}
	return (ft_load_paths(data, group, n_pths, n_vrtx));
}
