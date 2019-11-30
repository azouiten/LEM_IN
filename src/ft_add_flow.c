/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:37:45 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 18:21:42 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void			ft_add_flow(t_data *data)
{
	t_edges	*edg;

	edg = data->start->edges;
	while (data->path && data->path->vertex != data->start)
	{
		if (data->path->edg->edge_end->flow == 1)
			data->path->edg->edge_end->flow = 0;
		else
		{
			data->path->edg->flow = 1;
			if (data->path->edg->connection != data->end &&
					data->path->edg->connection != data->start)
				data->path->vertex->flow = 1;
		}
		data->path = data->path->next;
	}
}
