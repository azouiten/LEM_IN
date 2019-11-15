/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:15:40 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:13:50 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

void	ft_draw_menu(t_visud *visud)
{
	SDL_Rect	stretch;

	stretch.x = 0;
	stretch.y = 0;
	stretch.w = HEIGHT;
	stretch.h = HEIGHT;
	SDL_RenderCopy(visud->renderer, visud->menu, NULL, &stretch);
	SDL_RenderPresent(visud->renderer);
}
