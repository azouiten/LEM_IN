/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:33:04 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:32:19 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

void	ft_get_events(t_visud *visud, t_data *data)
{
	if (visud->e.type == SDL_QUIT || visud->e.key.keysym.sym == SDLK_q
			|| visud->e.key.keysym.sym == SDLK_ESCAPE)
		visud->quit = 1;
	else if (visud->e.type == SDL_KEYDOWN)
	{
		if (visud->e.key.keysym.sym == SDLK_p)
			visud->speed = -500000;
		else if (visud->e.key.keysym.sym == SDLK_SPACE)
			visud->speed = 1;
		else if (visud->e.key.keysym.sym == SDLK_a)
			visud->speed += 1;
		else if (visud->e.key.keysym.sym == SDLK_d && visud->speed > 1)
			visud->speed -= 1;
		else if (visud->e.key.keysym.sym == SDLK_LEFT
		|| visud->e.key.keysym.sym == SDLK_RIGHT
		|| visud->e.key.keysym.sym == SDLK_UP
		|| visud->e.key.keysym.sym == SDLK_DOWN
		|| visud->e.key.keysym.sym == SDLK_w
		|| visud->e.key.keysym.sym == SDLK_s)
			ft_navigate(data, visud->e.key.keysym.sym, visud);
		else if (visud->e.key.keysym.sym == SDLK_h)
			visud->help *= -1;
		else if (visud->e.key.keysym.sym == SDLK_r)
			visud->restart = 1;
	}
}
