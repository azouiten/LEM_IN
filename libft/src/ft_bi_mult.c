/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:18:46 by ohachim           #+#    #+#             */
/*   Updated: 2019/05/26 06:06:45 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_opsm(t_op *ms)
{
	if (ms->clen1 > 0)
		ms->alloc = ms->len1 - 1;
	else
		ms->alloc = ms->len1;
	if (ms->clen2 > 0)
		ms->alloc = ms->alloc + ms->len2 - 1;
	else
		ms->alloc = ms->alloc + ms->len2;
	if (ms->clen2 > 0 || ms->clen1 > 0)
		ms->alloc++;
	ms->alloc++;
	if (ms->clen1 > 0 && ms->clen2 > 0)
		ms->pnt = ms->alloc - ms->clen1 - ms->clen2 - 2;
	else if (ms->clen1 <= 0 || ms->clen2 <= 0)
		ms->pnt = ms->alloc - ms->clen1 - ms->clen2 - 3;
}

static void	ft_swapem(char **m1, char **m2, t_op *ms)
{
	char	*temp;

	ms->len1 = ft_strlen(*m1);
	ms->len2 = ft_strlen(*m2);
	if (ms->len1 < ms->len2)
	{
		temp = *m1;
		*m1 = *m2;
		*m2 = temp;
		ms->tl = ms->len1;
		ms->len1 = ms->len2;
		ms->len2 = ms->tl;
	}
	ms->clen1 = ft_cstrlen(*m1, '.') - 1;
	ms->clen2 = ft_cstrlen(*m2, '.') - 1;
	ms->dlen1 = ms->len1;
}

static void	ft_divi_m(t_op *m, char **a, char **b, char **res)
{
	m->alloc = m->dupa;
	m->len1 = m->dlen1;
	m->carry = 0;
	while (m->len1 - 1 >= 0)
	{
		if (res[0][m->alloc] == '.')
			m->alloc--;
		if (a[0][m->len1 - 1] == '.')
			m->len1--;
		if (b[0][m->len2 - 1] == '.')
			m->len2--;
		m->ires = ((a[0][m->len1 - 1] - '0') * (b[0][m->len2 - 1] - '0')) + \
			(res[0][m->alloc] - '0') + m->carry;
		m->carry = m->ires / 10;
		res[0][m->alloc] = (m->ires % 10) + '0';
		m->alloc--;
		m->len1--;
	}
	if (res[0][m->alloc] == '.')
		m->alloc--;
	if (m->carry)
		res[0][m->alloc] = m->carry + '0';
	m->dupa--;
	m->len2--;
}

char		*ft_bi_mult(char **m1, char **m2)
{
	char	*res;
	t_op	ms;

	ft_swapem(m1, m2, &ms);
	ft_init_opsm(&ms);
	if (!(res = (char*)malloc(ms.alloc)))
		return (NULL);
	res[ms.alloc - 1] = '\0';
	ms.alloc = ms.alloc - 2;
	ms.dupa = ms.alloc;
	while (ms.dupa >= 0)
	{
		res[ms.dupa] = '0';
		ms.dupa--;
	}
	if (ms.clen1 > 0 || ms.clen2 > 0)
		res[ms.pnt] = '.';
	ms.dupa = ms.alloc;
	while (ms.len2 - 1 >= 0)
		ft_divi_m(&ms, m1, m2, &res);
	free(*m1);
	free(*m2);
	return (ft_zero_scp(&res));
}
