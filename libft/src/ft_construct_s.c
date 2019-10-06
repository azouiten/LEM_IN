/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:49:50 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 05:59:30 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_first_zro(const char *conv)
{
	int		cn;

	cn = 0;
	while (conv[cn] == ' ' && conv[cn] != '\0')
		cn++;
	if (conv[cn] == '0' || conv[cn] == '\0')
		return (1);
	return (0);
}

static int	ft_all_em(const char *conv)
{
	int		cn;
	int		checks;

	checks = 0;
	cn = 0;
	while (conv[cn] != '\0')
	{
		if (conv[cn] != '0' && conv[cn] != ' ')
			checks++;
		cn++;
	}
	if (checks)
		return (0);
	return (1);
}

static char	*ft_pref_adapt(const char *format, t_rem *re, char *pref, char *co)
{
	char	*temp;
	int		check;

	check = 0;
	if (format[re->cursor] == 'o' && ft_first_zro(co))
		re->pref = 1;
	if ((re->fg[5] == '0' && re->fg[2] != '.') && re->fi_wi - ft_strlen(co) > 0)
		check = 1;
	if (((ft_strlen(co) && re->fg[3] == '#'
				&& ft_strlen(pref)) && !check && (((!ft_all_em(co)
				&& format[re->cursor] != 'o') || (format[re->cursor] == 'o'
				&& co[0] != '0'))))
				|| (re->fg[3] == '#' && co[0] == '\0'
				&& format[re->cursor] == 'o'))
	{
		temp = co;
		co = ft_strjoin(pref, co);
		free(temp);
		re->pref = 1;
	}
	return (co);
}

static char	*ft_make_precise(char *converted, int precision)
{
	char	*pre_zeros;
	char	*temp;

	pre_zeros = ft_make_s(precision - ft_strlen(converted), '0');
	temp = converted;
	converted = ft_strjoin(pre_zeros, converted);
	free(temp);
	free(pre_zeros);
	return (converted);
}

char		*ft_construct_s(char *co, const char *format, t_rem *rems, \
		char *pref)
{
	char	*temp;

	if (co[0] == '0' && rems->fg[2] == '.' && !rems->precision)
		co[0] = '\0';
	co = ft_make_precise(co, rems->precision);
	co = ft_pref_adapt(format, rems, pref, co);
	if (rems->fg[5] == '0' && rems->fg[1] != '-' && rems->fg[2] != '.')
		rems->pad = '0';
	if (rems->fg[3] == '#' && ft_strlen(pref) && !rems->pref && !ft_all_em(co))
		rems->fi_wi -= ft_strlen(pref);
	if (rems->fg[1] == '-')
		co = ft_fw_right(rems, co);
	else
		co = ft_fw_left(rems, co, rems->pad);
	if (rems->fg[3] == '#' && ft_strlen(pref) && !rems->pref && !ft_all_em(co))
	{
		temp = co;
		co = ft_strjoin(pref, co);
		free(temp);
	}
	return (co);
}
