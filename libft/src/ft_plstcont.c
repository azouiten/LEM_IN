/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plstcont.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:30:35 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/17 16:30:39 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_plstcont(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putstr((char const*)lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
}
