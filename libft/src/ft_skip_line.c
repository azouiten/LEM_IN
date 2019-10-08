/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:47:19 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/08 19:43:38 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_error_return(char **str)
{
	ft_strdel(str);
	return (-1);
}

static int	ft_get_nline(char **line, int fd, int retadd)
{
	char	buf[2];
	char	*temp;
	int		ret;

	temp = NULL;
	if (!(*line = ft_strnew(1)))
		return (-1);
	while ((ret = read(fd, buf, 1)))
	{
		if (ret < -1)
			return (ft_error_return(&temp));
		retadd = ret + retadd;
		buf[ret] = '\0';
		temp = *line;
		if (!(ft_isascii(buf[0])) || !(*line = ft_strjoin(*line, buf)))
			return (ft_error_return(&temp));
		ft_strdel(&temp);
		if ((ft_strchr(buf, '\n')))
			break ;
	}
	ft_strdel(&temp);
	line[0][retadd ? retadd - 1 : retadd] = '\0';
	return (retadd);
}

int			ft_skip_line(char **line, int fd)
{
	char	*temp;
	int		t;

	ft_strdel(line);
	t = ft_get_nline(line, fd, 0);
	return (t);
}
