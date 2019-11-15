/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:05:58 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:27:12 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static void		ft_all_edges(t_data *data, t_visud *visud)
{
	int			hn;
	t_vertices	*room;

	hn = 0;
	while (hn <= data->max_hash)
	{
		if (data->hash_table[hn])
		{
			room = data->hash_table[hn];
			while (room)
			{
				ft_draw_edges(visud, room, data->room_size);
				room = room->next;
			}
		}
		hn++;
	}
}

static void		ft_draw_room(t_vertices *ant_room, t_visud *visud, t_data *data)
{
	SDL_Rect	stretch;
	SDL_Texture	*room;

	if (ant_room == data->start)
		room = visud->start;
	else if (ant_room == data->end)
		room = visud->end;
	else
		room = visud->room;
	stretch.x = ant_room->x * visud->scale;
	stretch.y = ant_room->y * visud->scale;
	stretch.w = data->room_size * visud->scale;
	stretch.h = data->room_size * visud->scale;
	SDL_RenderCopy(visud->renderer, room, NULL, &stretch);
}

static void		ft_draw_hash(t_data *data, t_vertices *rooms, t_visud *visud)
{
	if ((rooms->x * visud->scale >= 0
				&& rooms->x * visud->scale < HEIGHT)
			|| ((rooms->x + data->room_size) * visud->scale > 0
				&& (rooms->x + data->room_size) * visud->scale < HEIGHT)
			|| (rooms->y * visud->scale >= 0
				&& rooms->y * visud->scale < HEIGHT)
			|| ((rooms->y + data->room_size) * visud->scale > 0
				&& (rooms->y + data->room_size) * visud->scale < HEIGHT))
		ft_draw_room(rooms, visud, data);
}

void			ft_draw_rooms(t_data *data, t_visud *visud, int init)
{
	int			hn;

	hn = 0;
	if (init == 0)
		data->room_size = data->room_size * visud->scale;
	ft_all_edges(data, visud);
	while (hn < data->vertices)
	{
		ft_draw_hash(data, data->vertex_ray[hn], visud);
		hn++;
	}
}
