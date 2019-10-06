/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:49:00 by ohachim           #+#    #+#             */
/*   Updated: 2019/06/26 18:57:27 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ret_line_read(int ret, char c, size_t len)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && c == '\0' && !len)
		return (0);
	return (1);
}

static int	ft_fill_fill(char **fill, char *buf, const int fd)
{
	int		ret;
	char	*temp;

	if (*fill == NULL)
		*fill = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = *fill;
		*fill = ft_strjoin(*fill, buf);
		free(temp);
		if ((ft_strchr(buf, '\n')))
			break ;
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*fill[4094];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			cn;
	int			ret;

	cn = 0;
	if (!line || BUFF_SIZE < 0 || read(fd, buf, 0) == -1 || fd < 0)
		return (-1);
	ret = ft_fill_fill(&fill[fd], buf, fd);
	if (!(*line = ft_strndup(fill[fd], '\n')))
		return (0);
	while (fill[fd][cn] != '\n' && fill[fd][cn] != '\0')
		cn++;
	if (fill[fd][cn] == '\n')
	{
		cn++;
		temp = fill[fd];
		fill[fd] = ft_strdup(&fill[fd][cn]);
		free(temp);
		return (1);
	}
	return (ft_ret_line_read(ret, *fill[fd], ft_strlen(*line)));
}
