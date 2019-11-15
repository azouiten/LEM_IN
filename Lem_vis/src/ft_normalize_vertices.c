/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_vertices.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 23:28:07 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:22:41 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static void		ft_zoom_it(t_data *data)
{
	int		zoom_int;
	int		rn;

	rn = 0;
	zoom_int = 2;
	while ((data->max_x * zoom_int) + data->room_size < HEIGHT
			&& (data->max_y * zoom_int) + data->room_size < HEIGHT)
		zoom_int += 2;
	zoom_int -= 2;
	if (zoom_int <= 0)
		zoom_int = 2;
	while (rn < data->vertices)
	{
		data->vertex_ray[rn]->x *= zoom_int;
		data->vertex_ray[rn]->y *= zoom_int;
		rn++;
	}
	while ((data->max_x * zoom_int + data->room_size > HEIGHT
				|| data->max_y * zoom_int + data->room_size > HEIGHT)
				&& data->room_size > 10)
		data->room_size -= 10;
}

int				ft_normalize_vertices(t_data *data)
{
	int			hn;
	int			rn;
	t_vertices	*temp;

	hn = 0;
	rn = 0;
	if (!(data->vertex_ray =
	(t_vertices**)malloc(sizeof(t_vertices*) * data->vertices)))
		return (0);
	while (hn <= data->max_hash)
	{
		temp = data->hash_table[hn];
		while (temp)
		{
			data->vertex_ray[rn] = temp;
			rn++;
			temp = temp->next;
		}
		hn++;
	}
	ft_zoom_it(data);
	return (0);
}
