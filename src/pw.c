/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 00:05:26 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 19:31:07 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void cc()
// {
// 	int x = 0;
// 	x++;
// }

void pw_smart_rotate(t_pp *a, t_pp *b)
{
	int i;

	i = i_max(b);
	// if (b->g > 110)
	// 	cc();
	if (i <= (int)(b->len / 2))
		ft_rrb(a, 1);
	else
		ft_rb(a, 1);
}

void pw_get_max_of_b_to_a(t_pp *a, t_pp *b)
{
	if (i_max(b) == (b->len - 1))
		ft_pa(a, 1);
	else
	{
		if (rank_dif_1(a, 0, b, -1) || b->stack[b->len - 1] == a[2].stack[a[2].len - 1])
		{
			ft_pa(a, 1);
			ft_ra(a, 1);
			// if (a->g > 500)
			// 	ft_putstr("A5");
		}
		else
			pw_smart_rotate(a, b);
	}
}

void pw_split_to_a(t_pp *a, t_pp *b, int avg_b, int size)
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
				if (rank_dif_1(a, 0, b, -1) || b->stack[b->len - 1] == a[2].stack[a[2].len - 1])
				{
					ft_pa(a, 1);
					ft_ra(a, 1);
					// if (a->g > 500)
					// 	ft_putstr("A6");
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

int pw_avg_limit(t_pp *a, int limit)
{
	int i;
	int total;
	if (a->len == 0)
		return (0);
	i = 0;
	total = 0;
	while ((a->stack[a->len - 1 - i] <= limit) && a->stack[a->len - 1 - i] != get_max_min(&a[2], 0))
	{
		total += a->stack[a->len - 1 - i];
		i++;
	}
	// return ((int)(total / (i + 0.5)));
	return ((int)(total / i + 0.5));
}

void pw_backtrack_split(t_pp *a, t_pp *b, int limit, int ctl)
{
	ft_putstr("pw_backtrack_split & a->g=");
	ft_putnbr(a[0].g);
	ft_putstr("\n");
	ft_putstr("limit=");
	ft_putnbr(limit);
	ft_putstr("\n");
	ft_putstr("ctl=");
	ft_putnbr(ctl);
	ft_putstr("\n");
	// pp_print_3stack(a[0], a[1], a[2]);

	// static int cl = 0;
	// if (cl == 0 && a[0].g == 167)
	// {
	// 	ft_pb(a);
	// 	ft_ra(a);
	// 	ft_ra(a);
	// 	ft_ra(a);
	// 	ft_pb(a);
	// 	ft_pb(a);
	// 	ft_pb(a);
	// 	ft_ra(a);
	// 	cl = 1;
	// }

	// pp_print_3stack(a[0], a[1], a[2]);
	int c;
	int i;
	int avg;
	// int u = 0;
	c = 0;
	avg = pw_avg_limit(a, limit);
	// ft_putstr("avg=");
	// ft_putnbr(avg);
	// ft_putstr("\n");
	// if(a->g > 500)
	// 	cc();
	// static int cl = 0;
	// if (cl == 0)
	// {
	// 	ft_putstr("cl=");
	// 	ft_putnbr(cl);
	// 	pp_print_2stack(a[0], a[1], a[2]);
	// 	cl = 1;
	// }
	// int bdr=50;
	while ((a->stack[a->len - 1] <= limit) && a->stack[a->len - 1] != get_max_min(&a[2], 0))
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
	// (void)b;
	i = -1;
	while (++i < c)
	{
		// pp_print_3stack(a[0], a[1], a[2]);
		// ft_putstr("a->g rrr/rra=");
		// ft_putnbr(i);
		// ft_putnbr(a[0].g);
		// ft_putnbr(c);
		// ft_putstr("\n");
		// ft_putstr("b->stack[b->len - 1]=");
		// ft_putnbr(b->stack[b->len - 1]);
		// ft_putstr("\n");
		// ft_putstr("get_max_min(b, 1)=");
		// ft_putnbr(get_max_min(b, 1));
		// ft_putstr("\n");
		if (b->stack[b->len - 1] != get_max_min(b, 1))
			ft_rrr(a, 1);
		else
		{
			ft_rra(a, 1);
			// ft_putstr("Acc");
			// ft_putnbr(c);
			// ft_putstr("i");
			// ft_putnbr(i);
		}
	}
	// ft_putstr("A6");
	if (rank_dif_1(a, 0, b, i_min(b)) && c > 0)
		ft_push_swap(a, b);
}