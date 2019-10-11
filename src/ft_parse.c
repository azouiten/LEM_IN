/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:26:34 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/11 03:21:56 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void	ft_parse(t_data *data)
{
	ft_initialize_hdata(data);
	if (ft_get_input(data) == -1 || ft_create_data(data) == -1
			|| !data->start || !data->end)
	{
		ft_printf("ERROR\n");
		ft_free_data(data);
		exit(0);
	}
}
