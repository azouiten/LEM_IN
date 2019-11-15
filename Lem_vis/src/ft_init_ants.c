/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:51:37 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:20:20 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

void	ft_init_ants(t_data *data)
{
	int	an;

	an = 0;
	while (an < data->ants)
	{
		data->motion_ant[an].x = data->start->x;
		data->motion_ant[an].y = data->start->y;
		data->motion_ant[an].destination = 0;
		data->motion_ant[an].arrived = 0;
		data->motion_ant[an].t = 0.01;
		an++;
	}
}
