/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:31:28 by weilin            #+#    #+#             */
/*   Updated: 2020/05/17 22:43:33 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pw_5(t_pp *data, int mid)
{
	const int *a = data[0].stack;

	if (data[0].t_len >= 4)
	{
		while (data[0].len - 1 > ((int)(data[0].t_len) / 2))
			(data[0].stack[data[0].len - 1] < mid)
				? ft_pb(data, 1) : ft_ra(data, 1);
		if (pw_sorted(data[1].stack, data[1].len))
			ft_sb(data, 1);
	}
	if (!pw_sorted(data[0].stack, data[0].len))
	{
		if (!((a[2] > a[0] && a[0] > a[1]) || (a[1] > a[2] && a[2] > a[0])))
			ft_sa(data, 1);
		((a[2] > a[1]) && (a[2] > a[0])) ? ft_ra(data, 1) : 0;
		((a[0] < a[1]) && (a[0] < a[2])) ? ft_rra(data, 1) : 0;
	}
	while (data[1].len > 0)
		ft_pa(data, 1);
}

void	ft_push_swap(t_pp *a, t_pp *b)
{
	int b_v_max;

	if (b->len == 0)
		return ;
	b_v_max = get_max_min(b, 1);
	pw_split_to_a(a, b, get_average(b), b->len);
	while ((rank_dif_1(a, 0, a, -1)
			|| a->stack[a->len - 1] == get_max_min(&a[2], 0))
			&& !pw_sorted(a->stack, a->len))
		ft_ra(a, 1);
	ft_push_swap(a, b);
	if (pw_i_next_to_min(a, b_v_max) >= 20)
		pw_backtrack_split(a, b, b_v_max, 0);
	pw_backtrack(a, b, b_v_max);
}

void	ft_push_swap_main(t_pp *data)
{
	int mid;

	mid = median_rank(data);
	if (pw_sorted(data->stack, data->t_len))
		return ;
	else if (data[0].t_len <= 5)
		pw_5(data, mid);
	else
	{
		pw_to_b(data, get_average(data));
		ft_push_swap(data, &data[1]);
		if (pw_i_next_to_min(data, data->stack[i_max(data)]) >= 20)
		{
			pw_backtrack_split(data, &data[1], get_max_min(data, 1), 2);
			pw_backtrack_split(data, &data[1], get_max_min(data, 1), 4);
		}
		pw_backtrack(data, &data[1], data->stack[i_max(data)]);
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_pp	data[3];

	if (ac > 1)
	{
		i = 1;
		if (!ft_check_args(ac - 1, av, data, i))
			return (0);
		ft_push_swap_main(data);
		cleanall(data, av, 0);
		data[2].stack ? free(data[2].stack) : 0;
	}
	return (0);
}
