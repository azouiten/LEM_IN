/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:40:06 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 18:36:04 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void	ft_flush_vbuffer(t_data *data)
{
	t_v_buffer	*buff;
	t_v_buffer	*tmp;

	tmp = NULL;
	buff = data->visited;
	while (buff)
	{
		buff->vertex->visited = 0;
		tmp = buff;
		buff = buff->next;
		ft_memdel((void**)&tmp);
	}
	data->visited = NULL;
}
