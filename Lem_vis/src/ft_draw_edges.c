/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_edges.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:37:57 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:15:42 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static void	ft_draw_it(t_visud *visud, t_vertices *room, int size
		, t_edges *temp_edge)
{
	int		i;

	i = 0;
	if (room->x > temp_edge->connection->x)
	{
		SDL_RenderDrawLine(visud->renderer, (room->x +
		(size / 2)) * visud->scale, (i + room->y + (size / 2)) * visud->scale,
		(temp_edge->connection->x + (size / 2)) * visud->scale,
		(i + temp_edge->connection->y + (size / 2)) * visud->scale);
		i++;
	}
	else
	{
		SDL_RenderDrawLine(visud->renderer, (i + room->x +
		(size / 2)) * visud->scale, (room->y + (size / 2)) * visud->scale,
		(i + temp_edge->connection->x + (size / 2)) * visud->scale,
		(temp_edge->connection->y + (size / 2)) * visud->scale);
		i++;
	}
}

void		ft_draw_edges(t_visud *visud, t_vertices *room, int size)
{
	t_edges	*temp_edge;

	temp_edge = room->edges;
	SDL_SetRenderDrawColor(visud->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	while (temp_edge)
	{
		ft_draw_it(visud, room, size, temp_edge);
		temp_edge = temp_edge->next;
	}
}
