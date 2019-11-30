/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:38:01 by azouiten          #+#    #+#             */
/*   Updated: 2019/11/30 16:34:39 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

int		main(void)
{
	t_data	data;

	ft_parse(&data);
	ft_bfs(&data);
	ft_calibrate_loads(&data);
	ft_print_moves(&data, 0, 0, 0);
	ft_free_data(&data);
	return (0);
}
