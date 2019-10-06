/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:26:15 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/06 16:40:59 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static t_input		*ft_input_node(char *line)
{
	t_input			*node;

	if (!line)
		return (0);
	if (!(node = (t_input*)malloc(sizeof(t_input))))
		return (0);
	if (!(node->line = ft_strdup(line)))
		return (0);
	node->next = NULL;
	return (node);
}

int					ft_get_input(t_data *data)
{
	t_input			*input;
	char			*temp;
	int				ret;

	temp = NULL;
	if ((ft_skip_line(&temp, 0) == -1))
		return (-1);
	if (!(input = ft_input_node(temp)))
		return (-1);
	data->input_head = input;
	while ((ret = ft_skip_line(&temp, 0)))
	{
		if (ret == -1)
			return (-1);
		if (!(input->next = ft_input_node(temp)))
			return (-1);
		input = input->next;
	}
	ft_strdel(&temp);
	return (1);
}

int					main(void)
{
	t_data			data;

	ft_initialize_hdata(&data);
	if (ft_get_input(&data) == -1 || ft_create_data(&data) == -1
			|| !data.start || !data.end)
	{
		ft_printf("ERROR\n");
		return (ft_free_data(&data));
	}
	else
		ft_printf("All good\n");
	ft_printf("%d---[%s][%s]\n", data.max_hash,
	data.hash_table[1]->name, data.hash_table[1]->edges->connection->name);
	ft_free_data(&data);
	return (0);
}
