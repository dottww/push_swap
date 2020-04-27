/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:05:26 by weilin            #+#    #+#             */
/*   Updated: 2020/03/12 15:40:49 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** get average of all the arguments smaller than the given limit and locates
** upper than the stack A min
*/

int pw_avg_limit(t_pp *a, int limit)
{
	int i;
	int total;
	int a_i_min;
	if (a->len == 0)
		return (0);
	i = 0;
	total = 0;
	a_i_min = i_min(a);
	while ((a->stack[a->len - 1 - i] <= limit) && (a->len - 1 - i) != a_i_min)
	{
		total += a->stack[a->len - 1 - i];
		i++;
	}
	return (total / i);
	// return ((int)(total / i + 0.5));
}

void pw_smart_rotate(t_pp *a, t_pp *b)
{
	int i;

	i = -1;
	while (++i < (int)b->len)
		if (i == i_max(b))
			break;
	if (i <= (int)b->len / 2)
		ft_rrb(a);
	else
		ft_rb(a);
}

void pw_get_max_of_b_to_a(t_pp *a, t_pp *b)
{
	if (i_max(b) == (b->len - 1))
		ft_pa(a);
	else
	{
		// if (rank_dif_1(a, 0, b, -1) || i_min(b) == (b->len - 1))
		if (rank_dif_1(a, 0, b, -1) || b->stack[b->len - 1] == 1)
		{
			ft_pa(a);
			ft_ra(a);
		}
		else
			pw_smart_rotate(a, b);
	}
}

void pw_split_to_a(t_pp *a, t_pp *b, int avg, int size)
{
	while (size-- > 0)
	{
		if (b->len < 15)
			pw_get_max_of_b_to_a(a, b);
		else
		{
			if (b->stack[b->len - 1] >= avg)
				ft_pa(a);
			else
			{
				if (rank_dif_1(a, 0, b, -1) || i_min(b) == (b->len - 1))
				{
					ft_pa(a);
					ft_ra(a);
				}
				else
					ft_rb(a);
			}
		}
	}

}
void pw_backtrack_split(t_pp *a, t_pp *b, int limit)
{
	int c;
	int i;
	int avg;

	c = 0;
	avg = pw_avg_limit(a, limit);
	while ((a->stack[a->len - 1] <= limit) && (a->len - 1) != i_min(a))
	{
		if (a->stack[a->len - 1] >= avg)
		{
			ft_ra(a);
			c++;
		}
		else
			ft_pb(a);
	}
	i = -1;
	while (++i < c)
		if ((b->len - 1) != i_max(b))
			ft_rrr(a);
		else
			ft_rra(a);
	if (rank_dif_1(a, 0, b, i_min(b)) && c > 0)
		ft_push_swap(a, b);
}
