/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <othmanehachim@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:20:28 by ohachim           #+#    #+#             */
/*   Updated: 2018/10/08 22:13:32 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int cn;

	if (s != 0)
	{
		cn = 0;
		while (s[cn] != '\0')
		{
			ft_putchar_fd(s[cn], fd);
			cn++;
		}
	}
}
