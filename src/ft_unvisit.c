/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unvisit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:00:43 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/08 16:07:31 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

void	ft_unvisit(t_vbuffer *visited)
{
	t_vbuffer	*temp_visited;

	temp_visited = visited;
	while (temp_visited)
	{
		temp_visited->vertex->visited = 1;
		temp_visited = temp_visited->next;
	}

}
