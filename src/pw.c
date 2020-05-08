/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:05:26 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 07:33:50 by weilin           ###   ########.fr       */
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
	// int a_i_min;
	if (a->len == 0)
		return (0);
	i = 0;
	total = 0;
	// a_i_min = i_min(a);
	// ft_putstr("STK12\n");
	// ft_putstr("rank_min=");
	// ft_putnbr(get_max_min(&a[2], 0));
	// ft_putstr("\n");
	// ft_putstr("rank_max=");
	// ft_putnbr(get_max_min(&a[2], 1));
	// ft_putstr("\n");
	while ((a->stack[a->len - 1 - i] <= limit) && a->stack[a->len - 1 - i] != get_max_min(&a[2], 0))
	{
		total += a->stack[a->len - 1 - i];
		i++;
	}
	// ft_putstr("STK13\n");
	if(total == 0 && i == 0)
	{
	ft_putstr("total=");
	ft_putnbr(total);
	ft_putstr("\n");
	ft_putstr("i=");
	ft_putnbr(i);
	ft_putstr("\n");
	pp_print_2stack(a[0], a[1], a[2]);
	}
	// return (total / i);
	return ((int)(total / (i + 0.5)));
}

void pw_smart_rotate(t_pp *a, t_pp *b)
{
	int i;

	// if (b->len < 2)
	// 	return ;
	i = i_min(b);
	// ft_putstr("STK1\n");
	if (i < (int)(b->len / 2))
		ft_rrb(a);
	else
		ft_rb(a);
	// ft_putstr("STK2\n");
}

void pw_get_max_of_b_to_a(t_pp *a, t_pp *b)
{
	// ft_putstr("g_max to a\n");
	// if(b->stack[b->len - 1] == 8)
	// 	{
	// 		ft_putstr("SMARTSMARTSMARTSMARTSMART\n");
	// 		pp_print_2stack(*a, *b, a[2]);
	// 	}
		// ft_putstr("(b->len =");
		// ft_putnbr(b->len);
		// ft_putstr("\n");
	if (i_max(b) == (b->len - 1))
		ft_pa(a);
	else
	{
		// if (rank_dif_1(a, 0, b, -1) || i_min(b) == (b->len - 1))
		
		if (rank_dif_1(a, 0, b, -1) || b->stack[b->len - 1] == a[2].stack[a[2].len - 1])
		{
			ft_pa(a);
			ft_ra(a);
		}
		else
			// pp_print_2stack(*a, *b, a[2]);
			pw_smart_rotate(a, b);
	}
}
void pw_get_max_of_b_to_a_old(t_pp *a, t_pp *b)
{
	ft_putstr("STK\n");
	if (i_max(b) == (b->len - 1))
		ft_pa(a);
	else
	{
		// if (rank_dif_1(a, 0, b, -1) || i_min(b) == (b->len - 1))
		if(b->stack[b->len - 1] == 8)
		{
			ft_putstr("SMARTSMARTSMARTSMARTSMART\n");
			pp_print_2stack(*a, *b, a[2]);
		}
		if (rank_dif_1(a, 0, b, -1) || b->stack[b->len - 1] == a[2].stack[a[2].len - 1])
		{
			ft_pa(a);
			ft_ra(a);
		}
		else
			// pp_print_2stack(*a, *b, a[2]);
			pw_smart_rotate(a, b);
	}
}

void pw_split_to_a(t_pp *a, t_pp *b, int avg_b, int size)
{
	// static int x=0;
	// ft_putstr("size =");
	// 		ft_putnbr(size);
	// 		ft_putstr("\n");

	while (size-- > 0)
	// while (b->len > 0)
	{
			// ft_putstr("size =");
			// ft_putnbr(size);
			// ft_putstr(" ,b->len =");
			// ft_putnbr(b->len);
			// ft_putstr("\n");

		// ft_putstr("STK3\n");
		if (b->len < 13)
			pw_get_max_of_b_to_a(a, b);
		else
		{
			
			if (b->stack[b->len - 1] >= avg_b)
				ft_pa(a);
			else
			{
				if (rank_dif_1(a, 0, b, -1) || b->stack[b->len - 1] == a[2].stack[a[2].len - 1])
				{
					ft_pa(a);
					ft_ra(a);
				}
				else
					ft_rb(a);
			}
		// x++;ft_putnbr(x);ft_putstr("_sp_a\n");
		// pp_print_2stack(a[0], a[1], a[2]);
		}
		// ft_putstr("STK4\n");
	}
	// ft_putstr("STK5\n");
}
void pw_backtrack_split(t_pp *a, t_pp *b, int limit)
{
	int c;
	int i;
	int avg;

	c = 0;ft_putstr("STK11\n");
	ft_putstr("pw_backtrack_splitlimit=");
	ft_putnbr(limit);
	ft_putstr("\n");
	avg = pw_avg_limit(a, limit);
	ft_putstr("pw_backtrack_splitlimit=2");
	// avg = get_average(a);
	// ft_putstr("STK1X\n");
	while ((a->stack[a->len - 1] <= limit) && a->stack[a->len - 1] != get_max_min(&a[2], 0))
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
	// (void)b;
	while (++i < c)
		if ((b->len - 1) != i_max(b))
			ft_rr(a);
		else
			ft_ra(a);
	if (rank_dif_1(a, 0, b, i_min(b)) && c > 0)
		ft_push_swap(a, b);
}

// i = -1;
// 	while (++i < c)
// 		if ((b->len - 1) != i_max(b))
// 			ft_rrr(a);
// 		else
// 			ft_rra(a);
// 	if (rank_dif_1(a, 0, b, i_min(b)) && c > 0)
// 		ft_push_swap(a, b);