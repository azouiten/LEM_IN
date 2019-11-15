/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_navigate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:45:20 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:35:50 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static void		ft_decrease_y(t_data *data)
{
	int			ant;
	int			hn;
	t_vertices	*temp;

	ant = 0;
	hn = 0;
	while (ant < data->ants)
	{
		data->motion_ant[ant].y -= 20;
		ant++;
	}
	while (hn <= data->max_hash)
	{
		if (data->hash_table[hn])
		{
			temp = data->hash_table[hn];
			while (temp)
			{
				temp->y -= 20;
				temp = temp->next;
			}
		}
		hn++;
	}
}

static void		ft_increase_y(t_data *data)
{
	int			ant;
	int			hn;
	t_vertices	*temp;

	ant = 0;
	hn = 0;
	while (ant < data->ants)
	{
		data->motion_ant[ant].y += 20;
		ant++;
	}
	while (hn <= data->max_hash)
	{
		if (data->hash_table[hn])
		{
			temp = data->hash_table[hn];
			while (temp)
			{
				temp->y += 20;
				temp = temp->next;
			}
		}
		hn++;
	}
}

static void		ft_increase_x(t_data *data)
{
	int			ant;
	int			hn;
	t_vertices	*temp;

	ant = 0;
	hn = 0;
	while (ant < data->ants)
	{
		data->motion_ant[ant].x += 20;
		ant++;
	}
	while (hn <= data->max_hash)
	{
		if (data->hash_table[hn])
		{
			temp = data->hash_table[hn];
			while (temp)
			{
				temp->x += 20;
				temp = temp->next;
			}
		}
		hn++;
	}
}

static void		ft_decrease_x(t_data *data)
{
	int			ant;
	int			hn;
	t_vertices	*temp;

	ant = 0;
	hn = 0;
	while (ant < data->ants)
	{
		data->motion_ant[ant].x -= 20;
		ant++;
	}
	while (hn <= data->max_hash)
	{
		if (data->hash_table[hn])
		{
			temp = data->hash_table[hn];
			while (temp)
			{
				temp->x -= 20;
				temp = temp->next;
			}
		}
		hn++;
	}
}

void			ft_navigate(t_data *data, int key, t_visud *visud)
{
	if (key == SDLK_LEFT)
		ft_decrease_x(data);
	else if (key == SDLK_RIGHT)
		ft_increase_x(data);
	else if (key == SDLK_UP)
		ft_decrease_y(data);
	else if (key == SDLK_DOWN)
		ft_increase_y(data);
	else if (key == SDLK_w
	|| key == SDLK_s)
		ft_zoom(visud, key);
}
