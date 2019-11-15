/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:49:22 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/21 16:21:39 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*duplst;
	t_list	*dlhold;
	int		i;

	dlhold = 0;
	i = 0;
	duplst = (t_list*)malloc(sizeof(t_list));
	while (lst != NULL)
	{
		if (!(duplst->next = f(lst)))
			return (NULL);
		if (i == 0)
			dlhold = duplst->next;
		lst = lst->next;
		duplst = duplst->next;
		i++;
	}
	duplst->next = NULL;
	return (dlhold);
}
