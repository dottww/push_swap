/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 03:09:24 by weilin            #+#    #+#             */
/*   Updated: 2020/05/10 02:13:41 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** find out the smallest index in stack A which locates upper than stack A min
** and with value smaller then given limit, which is the max of stack B
*/

int		pw_i_next_to_min(t_pp *a, int limit)
{
	int	i;

	if (a->len == 0)
		return (0);
	i = 0;
	while ((a->stack[a->len - 1 - i] <= limit)
			&& a->stack[a->len - 1 - i] != get_max_min(&a[2], 0))
		i++;
	return (i);
}

/*
** compare every argument with average, if smaller then pop to stack b,
** if bigger than rorate to end of stack a, which is stack[0] in memory
*/

void	pw_to_b(t_pp *data, int avg)
{
	int	i;

	i = 0;
	while (i < (int)data->t_len)
	{
		(avg >= data->stack[data->len - 1]) ? ft_pb(data, 1) : ft_ra(data, 1);
		i++;
	}
}

void	pw_backtrack_split(t_pp *a, t_pp *b, int limit, int ctl)
{
	int	c;
	int	i;
	int	avg;

	c = 0;
	avg = pw_avg_limit(a, limit);
	while ((a->stack[a->len - 1] <= limit)
			&& a->stack[a->len - 1] != get_max_min(&a[2], 0))
	{
		if (a->stack[a->len - 1] >= avg)
		{
			ft_ra(a, 1);
			c++;
			(void)(ctl);
		}
		else
			ft_pb(a, 1);
	}
	i = -1;
	while (++i < c)
		(b->stack[b->len - 1] != get_max_min(b, 1)) ? ft_rrr(a, 1)
													: ft_rra(a, 1);
	if (rank_dif_1(a, 0, b, i_min(b)) && c > 0)
		ft_push_swap(a, b);
}

void	pw_backtrack(t_pp *a, t_pp *b, int limit)
{
	while ((a->stack[a->len - 1] <= limit)
			&& (a->stack[a->len - 1] != get_max_min(&a[2], 0)))
	{
		if (rank_dif_1(a, 0, a, -1))
			ft_ra(a, 1);
		else
			ft_pb(a, 1);
	}
	if (rank_dif_1(a, 0, b, i_min(b)))
		ft_push_swap(a, b);
}
