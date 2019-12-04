/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enhance_groups.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:07:09 by azouiten          #+#    #+#             */
/*   Updated: 2019/12/04 15:17:18 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void			ft_enhance_groups(t_data *data)
{
	t_group	*grp;
	t_group	*grp_tmp;
	int		res;
	int		past_res;

	past_res = -1;
	grp_tmp = NULL;
	data->result->n_pths = 0;
	grp = data->result->group;
	while (grp)
	{
		if ((res = ft_rescore(data, grp)) >= past_res && past_res != -1)
		{
			grp_tmp = grp;
			break ;
		}
		else
			past_res = res;
		grp = grp->next;
		data->result->n_pths++;
	}
	grp = data->result->group;
	while (grp->next != grp_tmp)
		grp = grp->next;
	ft_rescore(data, grp);
}

int				ft_biggest(t_data *data, t_group *group)
{
	t_group	*grp;
	int		max;

	grp = data->result->group;
	max = grp->load + grp->size;
	while (grp)
	{
		if (grp->load + grp->size > max)
			max = grp->load + grp->size;
		if (grp == group)
			break ;
		grp = grp->next;
	}
	return (max);
}

static	int		ft_max(t_data *data, t_group *group)
{
	t_group	*tmp_grp;
	int		max_size;

	max_size = data->result->group->size;
	tmp_grp = data->result->group;
	while (tmp_grp)
	{
		if (tmp_grp->size > max_size)
			max_size = tmp_grp->size;
		if (tmp_grp == group)
			break ;
		tmp_grp = tmp_grp->next;
	}
	return (max_size);
}

static	void	ft_load(t_group *tmp_grp, int max_size, int *ants)
{
	tmp_grp->load = (*ants - (max_size - tmp_grp->size + 1)) < 0 ?
		*ants : max_size - tmp_grp->size + 1;
	*ants -= tmp_grp->load;
}

int				ft_load_paths(t_data *data, t_group *group,
		int n_pths)
{
	int		max_size;
	t_group	*tmp_grp;
	int		ants;

	ants = data->ants;
	max_size = ft_max(data, group);
	tmp_grp = data->result->group;
	while (tmp_grp && ants > 0)
	{
		ft_load(tmp_grp, max_size, &ants);
		if (tmp_grp == group)
			break ;
		tmp_grp = tmp_grp->next;
	}
	ants = (ants % n_pths == 0) ? ants / n_pths : ants / n_pths + 1;
	tmp_grp = data->result->group;
	while (ants > 0 && tmp_grp)
	{
		if (tmp_grp->load)
			tmp_grp->load += ants;
		if (tmp_grp == group)
			break ;
		tmp_grp = tmp_grp->next;
	}
	return (ft_biggest(data, group));
}
