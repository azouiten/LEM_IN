/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:38:45 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/17 07:39:07 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuh.h"

static int		ft_vertex_cmp(t_vertices *list, char *name)
{
	if (!list || !name)
		return (0);
	while (list)
	{
		if (!ft_strcmp(name, list->name))
			return (1);
		list = list->next;
	}
	return (0);
}

int				ft_check_validity(t_data *data, char *name, char *connection)
{
	int			hash_name;
	int			hash_connection;
	t_vertices	*temp;

	hash_name = ft_hash_it(name, data->vertices);
	hash_connection = ft_hash_it(connection, data->vertices);
	if (hash_name == -1 || hash_connection == -1)
		return (0);
	temp = data->hash_table[hash_name];
	if (!ft_vertex_cmp(temp, name))
		return (0);
	temp = data->hash_table[hash_connection];
	if (!ft_vertex_cmp(temp, connection))
		return (0);
	return (1);
}
