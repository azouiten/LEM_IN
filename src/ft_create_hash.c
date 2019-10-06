/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 00:33:06 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/06 13:36:47 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static t_vertices	**ft_init_table(t_data *data)
{
	int	count;

	if (!(data->hash_table = (t_vertices**)malloc(sizeof(t_vertices) \
					* data->vertices)))
		return (0);
	count = 0;
	while (count < data->vertices)
		data->hash_table[count++] = NULL;
	return (data->hash_table);
}

static int			ft_append_options(t_data *data, t_input **temp,
					int hash, int position)
{
	char	*name;

	if (ft_strcmp((*temp)->line, "##start") == 0)
		position = 0;
	else if (ft_strcmp((*temp)->line, "##end") == 0)
		position = 9;
	if (position == 0 || position == 9)
	{
		(*temp) = (*temp)->next;
		if ((*temp)->line[0] == '#')
			return (0);
	}
	if (!(*temp))
		return (0);
	name = ft_extract_name((*temp)->line);
	hash = ft_hash_it(name, data->vertices);
	if (hash == -1)
		return (0);
	if (hash > data->max_hash)
		data->max_hash = hash;
	ft_strdel(&name);
	return (ft_append_vertex(data, hash, (*temp)->line, position));
}

static int			ft_loop_hash(t_data *data, t_input **temp, int succ)
{
	if ((*temp)->line[0] == '#' && ft_strcmp((*temp)->line, "##start")
			&& ft_strcmp((*temp)->line, "##end"))
	{
		(*temp) = (*temp)->next;
		return (1);
	}
	if (ft_strchr((*temp)->line, '-'))
		return (2);
	succ = ft_append_options(data, temp, 0, 5);
	if (!succ)
		return (0);
	(*temp) = (*temp)->next;
	return (1);
}

int					ft_create_hash(t_data *data)
{
	t_input			*temp;
	int				success;

	data->max_hash = 0;
	temp = data->input_head->next;
	if (!(data->hash_table = ft_init_table(data)))
		return (0);
	while (temp)
	{
		if (!(success = ft_loop_hash(data, &temp, 1)))
			return (0);
		else if (success == 2)
			break ;
	}
	return (1);
}
