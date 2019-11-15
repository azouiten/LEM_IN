/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:36:45 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:51:14 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_len(char *p_r, t_rem *rems)
{
	int		len;
	int		p_r_len;

	p_r_len = ft_strlen(p_r);
	if (rems->precision == 0 && rems->fg[2] == '.')
		len = 0;
	else if (rems->precision < p_r_len && rems->precision > 0)
		len = rems->precision;
	else
		len = p_r_len;
	return (len);
}

static void	ft_print_prec(char *p_r, t_rem *rems)
{
	int		len_npr;

	if (rems->precision == 0 && rems->fg[2] == '.')
		p_r[0] = '\0';
	else if (rems->precision < (int)ft_strlen(p_r) && rems->precision > 0)
		p_r[rems->precision] = '\0';
	len_npr = ft_strlen(p_r);
	write(1, p_r, len_npr);
	rems->counter += len_npr;
}

static void	ft_print_fw(t_rem *rems, int len)
{
	int		t_fw;
	char	*temp;
	int		len_npr;

	t_fw = rems->fi_wi - len;
	if (t_fw > 0)
		temp = ft_make_s(t_fw, rems->pad);
	else
		temp = ft_strnew(1);
	len_npr = ft_strlen(temp);
	write(1, temp, len_npr);
	rems->counter += len_npr;
	free(temp);
}

static void	ft_to_print(char *p_r, t_rem *rems)
{
	int		len;

	len = ft_calc_len(p_r, rems);
	if (rems->fg[5] == '0' && rems->fg[1] != '-')
		rems->pad = '0';
	if (rems->fg[1] == '-')
		ft_print_prec(p_r, rems);
	ft_print_fw(rems, len);
	if (rems->fg[1] != '-')
		ft_print_prec(p_r, rems);
}

void		ft_print_str(va_list arg, const char *format, t_rem *rems)
{
	char	*print_ready;
	char	*temp;

	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	rems->precision = ft_precision(format, rems->cursor, arg);
	print_ready = va_arg(arg, char*);
	if (print_ready != NULL)
	{
		temp = ft_strdup(print_ready);
		ft_to_print(temp, rems);
	}
	else
	{
		temp = ft_strjoin("", "(null)");
		ft_to_print(temp, rems);
	}
	free(temp);
	rems->cursor += 1;
}
