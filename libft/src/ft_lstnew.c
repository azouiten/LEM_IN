/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:51:04 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/19 22:23:18 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*copy;
	void	*dupcont;

	if (!(copy = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		copy->content = NULL;
		copy->content_size = 0;
		copy->next = NULL;
		return (copy);
	}
	dupcont = (void*)malloc(content_size);
	dupcont = ft_memcpy(dupcont, content, content_size);
	copy->content = dupcont;
	copy->content_size = content_size;
	copy->next = NULL;
	return (copy);
}
