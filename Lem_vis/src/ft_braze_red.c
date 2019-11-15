/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_braze_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:50:51 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/13 13:45:03 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

void	ft_braze_red(t_ants *ant, t_visud *visud)
{
	if (ant->t < 1)
	{
		if (ant->t > 0.30)
		{
			ant->x = ant->destination->x;
			ant->y = ant->destination->y;
			ant->t = 1;
		}
		else
		{
			ant->x = ant->x + ((ant->destination->x - ant->x) * ant->t);
			ant->y = ant->y + ((ant->destination->y - ant->y) * ant->t);
			ant->t += 0.007;
		}
	}
	else if (!ant->arrived)
	{
		visud->arrived++;
		ant->arrived = 1;
	}
}
