/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_agroups.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:17:21 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 21:21:05 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static void		ft_free_path(t_group *group)
{
	t_path		*pth;
	t_path		*tmp;

	tmp = NULL;
	pth = group->path;
	while (pth)
	{
		tmp = pth;
		pth = pth->next;
		ft_memdel((void**)&tmp);
	}
}

static void		ft_free_group(t_agroups *agroup)
{
	t_group		*grp;
	t_group		*tmp;

	tmp = NULL;
	grp = agroup->group;
	while (grp)
	{
		ft_free_path(grp);
		tmp = grp;
		grp = grp->next;
		ft_memdel((void**)&tmp);
	}
}

void			ft_free_agroups(t_data *data)
{
	t_agroups	*agps;
	t_agroups	*tmp;

	tmp = NULL;
	agps = data->agroups;
	while (agps)
	{
		ft_free_group(agps);
		tmp = agps;
		agps = agps->next;
		ft_memdel((void**)&tmp);
	}
}
