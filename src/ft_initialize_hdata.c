/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_hdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:25:38 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/06 11:25:51 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void	ft_initialize_hdata(t_data *data)
{
	data->hash_table = NULL;
	data->start = NULL;
	data->end = NULL;
	data->input_head = NULL;
}