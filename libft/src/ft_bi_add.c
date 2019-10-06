/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:06:59 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 05:48:32 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_opsa(char **a1, char **a2, t_op *as)
{
	as->carry = 0;
	as->len1 = ft_strlen(*a1) - 1;
	as->len2 = ft_strlen(*a2) - 1;
	as->clen2 = ft_cstrlen(*a2, '.') - 1;
	as->clen1 = ft_cstrlen(*a1, '.') - 1;
	as->lenc1 = ft_strlenc(*a1, '.');
	as->lenc2 = ft_strlenc(*a2, '.');
	if (as->clen1 > as->clen2)
	{
		as->temp = *a1;
		*a1 = *a2;
		*a2 = as->temp;
		as->tl = as->len1;
		as->len1 = as->len2;
		as->len2 = as->tl;
		as->tl = as->clen2;
		as->clen2 = as->clen1;
		as->clen1 = as->tl;
	}
	if (as->lenc1 > as->lenc2)
		as->alloc = as->lenc1 + as->clen2 + 1;
	else
		as->alloc = as->clen2 + as->lenc2 + 1;
	as->rescn = as->alloc;
}

static void	ft_check_point(char **res, t_op *as, char **a1, char **a2)
{
	res[0][as->rescn] = '.';
	as->rescn--;
	if (a2[0][as->len2] == '.' && as->len2 >= 0)
		as->len2--;
	if (a1[0][as->len1] == '.' && as->len1 >= 0)
		as->len1--;
}

static void	ft_one_calc(t_op *as, char **a, char **res, int len)
{
	as->ires = (a[0][len] - '0') + as->carry;
	as->carry = as->ires / 10;
	res[0][as->rescn] = (as->ires % 10) + '0';
}

static char	*ft_calc_add(t_op *a, char **res, char **b, char **c)
{
	while (a->len2 >= 0 || a->len1 >= 0)
	{
		if ((c[0][a->len2] == '.' && a->len2 >= 0) ||
				(b[0][a->len1] == '.' && a->len1 >= 0))
			ft_check_point(res, a, b, c);
		if (a->len1 >= 0 && a->len2 >= 0)
		{
			a->ires = (c[0][a->len2] - '0') + (b[0][a->len1] - '0') + a->carry;
			a->carry = a->ires / 10;
			res[0][a->rescn] = (a->ires % 10) + '0';
		}
		else if (a->len2 >= 0 && a->len1 < 0)
			ft_one_calc(a, c, res, a->len2);
		else
			ft_one_calc(a, b, res, a->len1);
		a->rescn--;
		a->len1--;
		a->len2--;
	}
	if (a->carry)
	{
		res[0][a->rescn] = '1';
		a->rescn--;
	}
	return (*res);
}

char		*ft_bi_add(char **a1, char **a2, int fre)
{
	t_op	as;
	char	*res;

	ft_init_opsa(a1, a2, &as);
	res = ft_make_s(as.alloc, '0');
	res[as.alloc + 1] = '\0';
	while (as.clen2 > as.clen1)
	{
		res[as.rescn] = a2[0][as.len2];
		as.rescn--;
		as.clen2--;
		as.len2--;
	}
	res = ft_calc_add(&as, &res, a1, a2);
	free(*a1);
	if (fre != 0)
		free(*a2);
	return (ft_zero_scp(&res));
}
