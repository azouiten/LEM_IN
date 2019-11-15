/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_visualization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 04:24:01 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:22:03 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static int	ft_get_textures(t_visud *visud)
{
	if (!(visud->background_t =
	ft_load_texture("media/sand.png", visud)))
		return (0);
	if (!(visud->end = ft_load_texture("media/end.png", visud)))
		return (0);
	if (!(visud->start = ft_load_texture("media/start.png", visud)))
		return (0);
	if (!(visud->room = ft_load_texture("media/room.png", visud)))
		return (0);
	if (!(visud->ant_t = ft_load_texture("media/ant.png", visud)))
		return (0);
	if (!(visud->menu = ft_load_texture("media/menu.png", visud)))
		return (0);
	return (1);
}

static void	ft_init_vvalues(t_visud *visud)
{
	visud->renderer = NULL;
	visud->window = NULL;
	visud->menu = NULL;
	visud->init = 1;
	visud->restart = 0;
	visud->help = 1;
	visud->scale = 1;
	visud->pause = 0;
	visud->speed = 0;
	visud->arrived = 0;
	visud->ant_t = NULL;
	visud->background_t = NULL;
	visud->end = NULL;
	visud->start = NULL;
	visud->room = NULL;
	visud->quit = 0;
	visud->move_sum = 0;
}

static int	ft_get_renderer(t_visud *visud)
{
	if (!(visud->renderer = SDL_CreateRenderer(visud->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		return (0);
	return (1);
}

int			ft_init_visualization(t_visud *visud)
{
	int		img_flags;

	ft_init_vvalues(visud);
	img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 ||
			!(IMG_Init(img_flags) & img_flags))
		return (0);
	if (!(visud->window = SDL_CreateWindow("lemme in"
					, SDL_WINDOWPOS_CENTERED
					, SDL_WINDOWPOS_CENTERED
					, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		return (0);
	if (!ft_get_renderer(visud))
		return (0);
	if (!ft_get_textures(visud))
		return (0);
	return (1);
}
