/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:23:19 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/10 13:28:57 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

SDL_Texture	*ft_load_texture(char *path, t_visud *visud)
{
	SDL_Surface *surface;
	SDL_Texture *texture;

	if (!(surface = IMG_Load(path)))
		return (0);
	if (!(texture = SDL_CreateTextureFromSurface(visud->renderer, surface)))
	{
		SDL_FreeSurface(surface);
		surface = 0;
	}
	return (texture);
}
