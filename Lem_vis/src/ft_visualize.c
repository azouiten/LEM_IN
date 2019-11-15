/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 04:24:16 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:30:53 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static void	ft_delete_textures(t_visud *visud)
{
	if (visud->start)
		SDL_DestroyTexture(visud->start);
	if (visud->end)
		SDL_DestroyTexture(visud->end);
	if (visud->room)
		SDL_DestroyTexture(visud->room);
	if (visud->menu)
		SDL_DestroyTexture(visud->menu);
}

static void	ft_close(t_visud *visud)
{
	if (visud->window)
		SDL_DestroyWindow(visud->window);
	if (visud->renderer)
		SDL_DestroyRenderer(visud->renderer);
	if (visud->background_t)
		SDL_DestroyTexture(visud->background_t);
	if (visud->ant_t)
		SDL_DestroyTexture(visud->ant_t);
	ft_delete_textures(visud);
	IMG_Quit();
	SDL_Quit();
}

static int	ft_draw_render(t_visud *visud, t_data *data)
{
	SDL_RenderClear(visud->renderer);
	SDL_RenderCopy(visud->renderer, visud->background_t, NULL, NULL);
	ft_draw_rooms(data, visud, 1);
	if (!ft_draw_ants(visud, data))
		return (0);
	SDL_RenderPresent(visud->renderer);
	return (1);
}

static int	ft_loop_vis(t_visud *visud, t_data *data)
{
	while (!visud->quit)
	{
		while (SDL_PollEvent(&(visud->e)))
			ft_get_events(visud, data);
		if (visud->restart && !(visud->restart = 0))
		{
			ft_init_ants(data);
			data->moves_head = data->remember_moves;
			visud->move_sum = 0;
			visud->arrived = 0;
			visud->init = 1;
			continue ;
		}
		if (visud->help == 1)
			ft_draw_menu(visud);
		else if (!(ft_draw_render(visud, data)))
		{
			ft_draw_rooms(data, visud, 1);
			ft_copy_ants(data, visud);
			SDL_RenderPresent(visud->renderer);
		}
	}
	return (1);
}

int			main(void)
{
	t_data	data;
	t_visud	visud;

	ft_parse(&data);
	if (!(ft_init_visualization(&visud)))
	{
		ft_close(&visud);
		ft_free_data(&data);
		exit(0);
	}
	ft_draw_rooms(&data, &visud, 0);
	ft_loop_vis(&visud, &data);
	ft_close(&visud);
	ft_free_data(&data);
	exit(0);
}
