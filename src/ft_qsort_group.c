/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 23:28:07 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/18 16:05:06 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_inh.h"

static void	ft_swap(int i, int j, t_data *data)
{
	t_group *temp;

	temp =  data->array_result[i];
	data->array_result[i] = data->array_result[j];
	data->array_result[j] = temp;
}

static int	ft_partition(t_data *data, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	i = start - 1;
	j = start;
	pivot = data->array_result[end]->size;
	while (j < end)
	{
		if (data->array_result[j]->size < pivot)
		{
			i++;
			ft_swap(j, i, data);
		}
		j++;
	}
	ft_swap(i + 1, end, data);
	return (i + 1);
}

int	ft_qsort_group(t_data *data, int start, int end)
{
	int	p;

	if (start < end)
	{
		p = ft_partition(data, start, end);
		ft_qsort_group(data, start, p - 1);
		ft_qsort_group(data, p + 1, end);
	}
	return (0);
}
