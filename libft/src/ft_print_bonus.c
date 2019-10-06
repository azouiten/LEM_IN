/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 23:11:58 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:45:13 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_print_hdu(double db, t_rem *rems, const char *format)
{
	unsigned char	fl[8];
	char			*temp;
	char			*res;
	int				cn;
	char			*conved;

	cn = 0;
	res = ft_strnew(1);
	ft_memcpy(fl, &db, 8);
	while (cn < 8)
	{
		conved = ft_cnv_hex_u(fl[cn], 'u');
		temp = res;
		res = ft_strjoin(conved, res);
		free(temp);
		free(conved);
		cn++;
	}
	return (ft_construct_s(res, format, rems, "0X"));
}

static char	*ft_print_hdl(double db, t_rem *rems, const char *format)
{
	unsigned char	fl[8];
	char			*temp;
	char			*res;
	char			*conved;
	int				cn;

	cn = 0;
	res = ft_strnew(1);
	ft_memcpy(fl, &db, 8);
	while (cn < 8)
	{
		conved = ft_cnv_hex_u(fl[cn], 'l');
		temp = res;
		res = ft_strjoin(conved, res);
		free(temp);
		free(conved);
		cn++;
	}
	return (ft_construct_s(res, format, rems, "0x"));
}

static char	*ft_print_bd(double db, t_rem *rems, const char *format)
{
	unsigned char	fl[8];
	char			*bi_fl;

	ft_memcpy(fl, &db, 8);
	bi_fl = ft_bi_rep(fl, 8 - 1);
	return (ft_construct_s(bi_fl, format, rems, ""));
}

static void	ft_concat(char *file, t_rem *rems)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("");
		rems->cursor += 1;
		rems->counter += 1;
	}
	else
	{
		while ((get_next_line(fd, &line)))
		{
			ft_printf("%s\n", line);
			rems->counter += ft_strlen(line) + 1;
			ft_strdel(&line);
		}
		rems->cursor += 1;
	}
}

void		ft_print_bonus(va_list arg, const char *format, t_rem *rems, \
		char type)
{
	char	*p_r;

	rems->precision = ft_precision(format, rems->cursor, arg);
	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	if (type == 'A')
		p_r = ft_print_hdu(va_arg(arg, double), rems, format);
	if (type == 'a')
		p_r = ft_print_hdl(va_arg(arg, double), rems, format);
	if (type == 'b')
		p_r = ft_print_bd(va_arg(arg, double), rems, format);
	if (type == 'g')
		ft_concat(va_arg(arg, char*), rems);
	if (type != 'g')
	{
		ft_putstr_rem(p_r, rems);
		free(p_r);
	}
}
