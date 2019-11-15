/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:34:40 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:11:56 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static void		ft_draw_it(t_visud *visud, t_data *data, int antn)
{
	SDL_Rect	stretch;

	stretch.x = (data->motion_ant[antn].x + data->room_size / 4) * visud->scale;
	stretch.y = (data->motion_ant[antn].y + data->room_size / 4) * visud->scale;
	stretch.w = (data->room_size / 2) * visud->scale;
	stretch.h = (data->room_size / 2) * visud->scale;
	SDL_RenderCopy(visud->renderer, visud->ant_t, NULL, &stretch);
}

void			ft_copy_ants(t_data *data, t_visud *visud)
{
	int			antn;

	antn = 0;
	while (antn < data->ants)
	{
		if ((data->motion_ant[antn].x * visud->scale >= 0
		&& data->motion_ant[antn].x * visud->scale < HEIGHT)
		|| ((data->motion_ant[antn].x + data->room_size) * visud->scale > 0
		&& (data->motion_ant[antn].x + data->room_size) * visud->scale < HEIGHT)
		|| (data->motion_ant[antn].y * visud->scale >= 0
		&& data->motion_ant[antn].y * visud->scale < HEIGHT)
		|| ((data->motion_ant[antn].y + data->room_size) * visud->scale > 0
		&& (data->motion_ant[antn].y + data->room_size) * visud->scale
		< HEIGHT))
			ft_draw_it(visud, data, antn);
		antn++;
	}
}
