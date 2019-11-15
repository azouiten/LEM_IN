/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:23:47 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:50:06 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_is_p_fw(t_rem *rems, char *num)
{
	char	*temp;
	char	sign;

	sign = num[0];
	if (rems->fg[0] == '+' && num[0] != '-')
	{
		temp = num;
		num = ft_strjoin("+", num);
		free(temp);
	}
	if (rems->fg[5] == '0' && rems->fg[2] != '.' && rems->fg[1] != '-')
		rems->pad = '0';
	if (rems->fg[4] == ' ' && rems->fg[0] != '+' && num[0] != '-')
		rems->fi_wi--;
	if (rems->fg[1] == '-')
		num = ft_fw_right(rems, num);
	else
		num = ft_fw_left(rems, num, rems->pad);
	if (rems->fg[4] == ' ' && rems->fg[0] != '+' && sign != '-')
	{
		temp = num;
		num = ft_strjoin(" ", num);
		free(temp);
	}
	return (num);
}

static char	*ft_is_p(t_rem *re, char *num)
{
	char	*pre_zeros;
	char	*temp;
	char	*temp2;

	if (re->fg[2] == '.' && num[0] == '0')
		num[0] = '\0';
	if (num[0] == '-')
	{
		pre_zeros = ft_make_s(re->precision - ft_strlen(num) + 1, '0');
		temp2 = ft_strdup(num + 1);
		free(num);
		num = temp2;
		temp = pre_zeros;
		pre_zeros = ft_strjoin("-", temp);
		free(temp);
	}
	else
		pre_zeros = ft_make_s(re->precision - ft_strlen(num), '0');
	temp = num;
	num = ft_strjoin(pre_zeros, num);
	free(temp);
	free(pre_zeros);
	return (ft_is_p_fw(re, num));
}

void		ft_print_int(va_list arg, const char *format, t_rem *rems)
{
	char		type_spec;
	char		*p_r;

	type_spec = ft_scan_flag(format, rems->cursor);
	rems->fi_wi = ft_field_width(format, rems->cursor, arg);
	rems->precision = ft_precision(format, rems->cursor, arg);
	if (type_spec == 'l')
		p_r = ft_is_p(rems, ft_itoa_imp(va_arg(arg, long int)));
	else if (type_spec == 'L')
		p_r = ft_is_p(rems, ft_itoa_imp(va_arg(arg, long long int)));
	else if (type_spec == 'H')
		p_r = ft_is_p(rems, ft_itoa_imp((signed char)va_arg(arg, int)));
	else if (type_spec == 'h')
		p_r = ft_is_p(rems, ft_itoa_imp((short int)va_arg(arg, int)));
	else
		p_r = ft_is_p(rems, ft_itoa_imp((int)va_arg(arg, int)));
	ft_putstr_rem(p_r, rems);
	free(p_r);
}
