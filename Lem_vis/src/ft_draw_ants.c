/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:50:43 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:33:56 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static void		ft_ant_back(t_data *data, t_vertices **dest_hash, int ant,
char **old_dest)
{
	data->motion_ant[ant].destination = *dest_hash;
	data->motion_ant[ant].arrived = 0;
	data->motion_ant[ant].t = 0.01;
	ft_strdel(old_dest);
}

static int		ft_get_destination(int cn, int wn, t_data *data, int ant)
{
	char		**moves;
	char		*destination;
	int			hash;
	t_vertices	*dest_hash;

	if (!(moves = ft_strsplit(data->moves_head->line, ' ')))
		return (0);
	while (moves[wn])
	{
		cn = 0;
		ant = ft_atoi(&moves[wn][1]) - 1;
		while (moves[wn][cn] != '\0' && moves[wn][cn] != '-')
			cn++;
		if (!(destination = ft_extract_name(&moves[wn][cn + 1])))
			return (ft_strdel_imp(&moves));
		hash = ft_hash_it(destination, data->vertices);
		dest_hash = data->hash_table[hash];
		while (dest_hash && ft_strcmp(dest_hash->name, destination))
			dest_hash = dest_hash->next;
		ft_ant_back(data, &dest_hash, ant, &destination);
		wn++;
	}
	ft_strdel(&destination);
	ft_strdel_imp(&moves);
	return (1);
}

static void		ft_othsenham(t_data *data, t_visud *visud)
{
	int			an;
	int			speed;

	an = 0;
	while (an < data->ants)
	{
		speed = 0;
		if (!data->motion_ant[an].destination)
		{
			an++;
			continue ;
		}
		while (speed++ < visud->speed)
			ft_braze_red(&data->motion_ant[an], visud);
		an++;
	}
	ft_copy_ants(data, visud);
}

static void		ft_get_move_sum(t_visud *visud, t_data *data)
{
	int		an;

	an = 0;
	while (data->moves_head->line[an] != '\0')
	{
		if ((data->moves_head->line[an] == 'L' && an == 0) ||
				(data->moves_head->line[an] == 'L' &&
				data->moves_head->line[an - 1] == ' '))
			visud->move_sum++;
		an++;
	}
}

int				ft_draw_ants(t_visud *visud, t_data *data)
{
	if (!data->moves_head)
		return (0);
	if (!(visud->move_sum))
		ft_get_move_sum(visud, data);
	if (visud->init)
		if (!(ft_get_destination(0, 0, data, 0)))
			return (0);
	ft_othsenham(data, visud);
	if (visud->arrived != visud->move_sum)
	{
		visud->init = 0;
		return (1);
	}
	data->moves_head = data->moves_head->next;
	visud->move_sum = 0;
	visud->arrived = 0;
	visud->init = 1;
	return (1);
}
