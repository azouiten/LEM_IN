/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:29:07 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/15 18:45:19 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static int	ft_error_return(char **str)
{
	if (*str)
		ft_strdel(str);
	return (-1);
}

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
	int			ret;

	temp = NULL;
	if ((ft_skip_line(&temp, 0) == -1))
		return (ft_error_return(&temp));
	if (!(input = ft_input_node(temp)))
		return (ft_error_return(&temp));
	ft_printf("%s\n", input->line);
	data->input_head = input;
	while ((ret = ft_skip_line(&temp, 0)))
	{
		if (temp[0] == '\0')
		{
			input->next = NULL;
			break ;
		}
		if (ret == -1)
			return (ft_error_return(&temp));
		if (!(input->next = ft_input_node(temp)))
			return (ft_error_return(&temp));
		ft_printf("%s\n", input->next->line);
		input = input->next;
	}
	ft_strdel(&temp);
	return (1);
}

/*int					main(void)
{
	t_data			data;

	ft_parse(&data);
	ft_printf("All good\n");
	ft_printf("%d---[%s][%s]\n", data.max_hash,
	data.hash_table[1]->name, data.hash_table[1]->edges->connection->name);
	ft_free_data(&data);
	return (0);
}*/
