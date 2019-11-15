/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:40:40 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/08 03:55:46 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

void	ft_zoom(t_visud *visud, int key)
{
	if (key == SDLK_w && visud->scale < 30)
		visud->scale += 1;
	else if (key == SDLK_s && visud->scale > 1)
		visud->scale -= 1;
}
