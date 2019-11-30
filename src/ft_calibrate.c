/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calibrate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:10:38 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 18:25:38 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

int		ft_count(t_data *data)
{
	int	n_load;
	int	gn;

	n_load = 0;
	gn = 0;
	while (gn < data->result->n_pths)
	{
		n_load = n_load + data->array_result[gn]->load;
		gn++;
	}
	return (n_load);
}

void	ft_calibrate_loads(t_data *data)
{
	int	gn;
	int	n_load;

	gn = data->result->n_pths - 1;
	n_load = ft_count(data);
	while (n_load > data->ants + 1)
	{
		if (gn < 0)
			gn = data->result->n_pths - 1;
		data->array_result[gn]->load -= 1;
		n_load--;
		gn--;
	}
}
