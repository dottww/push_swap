/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:05:26 by weilin            #+#    #+#             */
/*   Updated: 2020/05/10 02:15:44 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pw_smart_rotate(t_pp *a, t_pp *b)
{
	int i;

	i = i_max(b);
	if (i <= (int)(b->len / 2))
		ft_rrb(a, 1);
	else
		ft_rb(a, 1);
}

void	pw_get_max_of_b_to_a(t_pp *a, t_pp *b)
{
	if (i_max(b) == (b->len - 1))
		ft_pa(a, 1);
	else
	{
		if (rank_dif_1(a, 0, b, -1)
			|| b->stack[b->len - 1] == a[2].stack[a[2].len - 1])
		{
			ft_pa(a, 1);
			ft_ra(a, 1);
		}
		else
			pw_smart_rotate(a, b);
	}
}

void	pw_split_to_a(t_pp *a, t_pp *b, int avg_b, int size)
{
	while (size-- > 0)
	{
		if (b->len < 13)
			pw_get_max_of_b_to_a(a, b);
		else
		{
			if (b->stack[b->len - 1] >= avg_b)
				ft_pa(a, 1);
			else
			{
				if (rank_dif_1(a, 0, b, -1)
					|| b->stack[b->len - 1] == a[2].stack[a[2].len - 1])
				{
					ft_pa(a, 1);
					ft_ra(a, 1);
				}
				else
					ft_rb(a, 1);
			}
		}
	}
}

/*
** get average of all the arguments smaller than the given limit and locates
** upper than the stack A min
*/

int		pw_avg_limit(t_pp *a, int limit)
{
	int i;
	int total;

	if (a->len == 0)
		return (0);
	i = 0;
	total = 0;
	while ((a->stack[a->len - 1 - i] <= limit)
			&& a->stack[a->len - 1 - i] != get_max_min(&a[2], 0))
	{
		total += a->stack[a->len - 1 - i];
		i++;
	}
	return ((int)(total / i + 0.5));
}
