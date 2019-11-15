/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 23:55:26 by ohachim           #+#    #+#             */
/*   Updated: 2019/04/02 16:31:49 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_getblen(char *base)
{
	int		blen;
	int		blen_dup;

	blen = 0;
	while (base[blen] != '\0')
	{
		if (base[blen] == '+' || base[blen] == '-')
			return (0);
		blen_dup = blen + 1;
		while (base[blen_dup])
		{
			if (base[blen_dup] == base[blen])
				return (0);
			blen_dup++;
		}
		blen++;
	}
	if (blen == 1)
		return (0);
	return (blen);
}

static int	ft_error(char *str, char *base)
{
	int	cn;
	int	cnb;

	cn = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (str[cn] == '+' || str[cn] == '-')
		cn++;
	while (str[cn] != '\0')
	{
		if (str[cn] == '+' || str[cn] == '-')
			return (0);
		cnb = 0;
		while (base[cnb] != str[cn] && base[cnb] != '\0')
			cnb++;
		if (base[cnb] == '\0')
			return (0);
		cn++;
	}
	if (cn < 1)
		return (0);
	return (1);
}

static int	ft_getfbase(char c, char *base)
{
	int cn;

	cn = 0;
	while (base[cn] != c)
		cn++;
	return (cn);
}

int			ft_atoi_base(char *str, char *base)
{
	int		b_len;
	int		cn;
	int		sign;
	int		ret;

	sign = 1;
	cn = 0;
	ret = 0;
	if (!str || !base || !(b_len = ft_getblen(base)) || !ft_error(str, base))
		return (0);
	if (str[cn] == '-')
		sign = -1;
	while (*str == ' ' || *str == '\t' || *str == '+' || *str == '-')
		str++;
	while (str[cn] != '\0')
	{
		ret = (ret * b_len) + ft_getfbase(str[cn], base);
		cn++;
	}
	return (ret * sign);
}
