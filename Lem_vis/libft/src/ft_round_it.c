/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 10:23:10 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 07:10:56 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_data(char *p_r, t_rem *rems, t_fdta *data)
{
	char	*init;

	init = ft_strjoin("0.0", "");
	data->clen = ft_cstrlen(p_r, '.') - 1;
	data->lenc = ft_strlenc(p_r, '.');
	data->len = ft_strlen(p_r);
	if ((rems->precision == 0 && rems->fg[2] != '.') || rems->precision == -1)
		rems->precision = 6;
	if (rems->precision >= 1)
	{
		data->zros = ft_make_s(rems->precision - 1, '0');
		data->temp = data->zros;
		data->zros = ft_strjoin(data->zros, "1");
		free(data->temp);
		data->temp = data->zros;
		data->zros = ft_strjoin("0.", data->zros);
		free(data->temp);
		data->zros = ft_bi_add(&init, &data->zros, 1);
	}
	else
		data->zros = ft_strjoin("1.0", "");
}

int		ft_round_valid(char *p_r, int cn, int cn1)
{
	char	c;

	if (cn == 0)
		return (0);
	c = p_r[cn];
	cn--;
	if (p_r[cn] == '.')
		cn--;
	if (c > '5')
		return (1);
	if (c == '5')
	{
		if ((p_r[cn] - '0') % 2 != 0)
			return (1);
		else
		{
			while (p_r[cn1 + 1] != '\0')
			{
				if (p_r[cn1 + 1] != '0')
					return (1);
				cn1++;
			}
		}
	}
	return (0);
}

char	*ft_round_it(char **p_r, t_rem *rems)
{
	t_fdta	data;
	char	*zero;

	if (ft_strchr(*p_r, 'n'))
		return (*p_r);
	ft_init_data(*p_r, rems, &data);
	if (rems->precision >= data.clen - 1)
	{
		zero = ft_make_s(rems->precision - (data.clen - 1), '0');
		data.temp = *p_r;
		*p_r = ft_strjoin(*p_r, zero);
		free(data.temp);
		free(zero);
	}
	if (ft_round_valid(*p_r, data.lenc + rems->precision + 1, \
				data.lenc + rems->precision + 1))
		*p_r = ft_bi_add(&data.zros, p_r, 1);
	else
		free(data.zros);
	while (p_r[0][data.lenc + rems->precision + 1] != '\0')
	{
		p_r[0][data.lenc + rems->precision + 1] = '\0';
		data.lenc++;
	}
	return (*p_r);
}
