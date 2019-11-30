/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swing_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:09:21 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 19:05:26 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static	void	ft_free_pth(t_path **path)
{
	t_path *tmp;

	tmp = NULL;
	while (*path)
	{
		tmp = *path;
		*path = (*path)->next;
		ft_memdel((void**)&tmp);
	}
}

t_agroups		*ft_swing_paths(t_data *data, t_agroups *agroup)
{
	t_path	*path_rep;
	t_path	*tmp;
	t_path	*pth;
	t_group	*group;

	group = agroup->group;
	while (group)
	{
		pth = group->path;
		tmp = NULL;
		while (group->path)
		{
			if (!(path_rep = (t_path*)malloc(sizeof(t_path))))
				ft_exit(data);
			path_rep->vertex = group->path->vertex;
			path_rep->edg = NULL;
			path_rep->next = tmp;
			tmp = path_rep;
			group->path = group->path->next;
		}
		ft_free_pth(&pth);
		group->path = path_rep;
		group = group->next;
	}
	return (agroup);
}
