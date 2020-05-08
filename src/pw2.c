/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 03:09:24 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 14:16:46 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** find out the smallest index in stack A which locates upper than stack A min
** and with value smaller then given limit, which is the max of stack B
*/

int pw_i_next_to_min(t_pp *a, int limit)
{
	int i;

	if (a->len == 0)
		return (0);
	i = 0;
	while ((a->stack[a->len - 1 - i] <= limit) && a->stack[a->len - 1 - i] != get_max_min(&a[2], 0))
		i++;
	// ft_putstr("i=");
	// ft_putnbr(i);
	// ft_putstr("\n");
	// ft_putstr("w_i_n_limit=");
	// ft_putnbr(limit);
	// ft_putstr("\n");
	// pp_print_2stack(a[0], a[1], a[2]);
	// ft_putstr("STK9\n");
	return (i);
}

/*
** compare every argument with average, if smaller then pop to stack b,
** if bigger than rorate to end of stack a, which is stack[0] in memory
*/

void pw_to_b(t_pp *data, int avg)
{
	int i;

	i = 0;
	while (i < (int)data->t_len)
	{
		(avg >= data->stack[data->len - 1]) ? ft_pb(data) : ft_ra(data);
		i++;
	}
}
// static void d()
// {
// 	int x = 0;
// 	x++;
// }
void pw_backtrack(t_pp *a, t_pp *b, int limit)
{
	ft_putstr("pw_backtrack & a->g=");
	ft_putnbr(a[0].g);
	ft_putstr("\n");
	ft_putstr("limit=");
	ft_putnbr(limit);
	ft_putstr("\n");
	// int u = 0;
	// if (a->g > 110)
	// 	d();
	// pp_print_2stack(a[0], a[1], a[2]);
	while ((a->stack[a->len - 1] <= limit) && (a->stack[a->len - 1] != get_max_min(&a[2],0)))
	{
		// ft_putnbr(a[0].g);
		// ft_putstr("get_min=");
		// ft_putnbr(get_max_min(&a[2], 0));
		
		if (rank_dif_1(a, 0, a, -1))
			ft_ra(a);
		else
		// pw_is_sorted(a->stack, a->len) ? 0 : ft_pb(a);
		{
			ft_pb(a);
			// u++;
			// ft_putstr("A77u");
			// ft_putnbr(u);
		}
	}
	// pp_print_2stack(a[0], a[1], a[2]);
	// printf("b_min=%d\n",i_max_min(b,0));
	// if (rank_dif_1(a, 0, b, get_max_min(b, 0)))
	// {printf("HERERERERE------------------------------------\n");
	if (rank_dif_1(a, 0, b, i_min(b)))
		ft_push_swap(a, b);
}
