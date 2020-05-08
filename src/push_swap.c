/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:31:28 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 07:27:20 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

void pw_5(t_pp *data, int mid)
{
	const int *a = data[0].stack;

	while (data[0].len - 1 > ((int)(data[0].t_len) / 2))
		(data[0].stack[data[0].len - 1] < mid) ? ft_pb(data) : ft_ra(data);
	if (pw_is_sorted(data[1].stack, data[1].len))
		ft_sb(data);
	if (!pw_is_sorted(data[0].stack, data[0].len))
	{
		if (!((a[2] > a[0] && a[0] > a[1]) || (a[1] > a[2] && a[2] > a[0])))
			ft_sa(data);
		((a[2] > a[1]) && (a[2] > a[0])) ? ft_ra(data) : 0;
		((a[0] < a[1]) && (a[0] < a[2])) ? ft_rra(data) : 0;
	}
	while (data[1].len > 0)
		ft_pa(data);
} //3 2 5 4 1, 5 4 3 2 1

void ft_push_swap(t_pp *a, t_pp *b)
{
	// if (!pw_is_sorted(a->stack, 5))
	// {
static int x=0;

x++;ft_putnbr(x);ft_putstr("_pw_to_b\n");
	pp_print_2stack(a[0], a[1], a[2]);
	int b_v_max;

	if (b->len == 0)
		return;
	b_v_max = get_max_min(b, 1);
	// ft_putstr("b_v_max=");
	// ft_putnbr(b_v_max);
	// ft_putstr("\n");
	// ft_putstr("before pw_split_to_a\n");
	// pp_print_2stack(a[0], a[1], a[2]);

	pw_split_to_a(a, b, get_average(b), b->len);
	
	// ft_putstr("after pw_split_to_a\n");
	// ft_putstr("STK6\n");
	// printf("now to while\n");
	// while (
	// 		(
	// 		rank_dif_1(a, 0, a, -1)
	// 		||
	// 		a->stack[a->len - 1] == a[2].stack[a[2].len - 1]
	// 		)
	// 		&& !pw_is_sorted(a->stack, a->len)
	// 	)
	// 	ft_ra(a);
	pp_print_2stack(a[0], a[1], a[2]);
	// ft_putstr("STK7\n");
	// ft_push_swap(a, b);
	// ft_putstr("b_v_max2=");
	// ft_putnbr(b_v_max);
	// ft_putstr("\n");
	// if (pw_i_next_to_min(a, b_v_max) < 20)
	// 	pw_backtrack_split(a, b, b_v_max);
	// pw_backtrack(a, b, get_max_min(b, 1));
	// }
}
	// {ft_putstr("YESYESYESYESYESYES\n");
	// {ft_putstr("STK10\n");

// void push_swap__main(t_pp *data)
void ft_push_swap_backtrack(t_pp *data)
{
	int mid = median_rank(data);

	// if (is__ascending(data->stack, data->t_len))
	// pp_print_2stack(data[0], data[1], data[2]);
	if (pw_is_sorted(data->stack, data->t_len))
		return;
	else if (data[0].t_len <= 5)
	{
		pw_5(data, mid);
		// pp_print_2stack(data[0], data[1], data[2]);
	}
	else
	{
		// static int x=0;

		// ft_putnbr(x);ft_putstr("_START\n");
		pp_print_2stack(data[0], data[1], data[2]);
		
		
		pw_to_b(data, get_average(data));
		// x++;ft_putnbr(x);ft_putstr("_pw_to_b\n");
		// pp_print_2stack(data[0], data[1], data[2]);

		ft_push_swap(data, &data[1]);
		// x++;ft_putnbr(x);ft_putstr("_ft_push_swap\n");
		// pp_print_2stack(data[0], data[1], data[2]);
		
		// static int y=0;
		// if (get_max_min(data,1) < 20)
		// {
		// 	y++;ft_putnbr(y);ft_putstr("{i_min<=20}\n");
		// 	pw_backtrack_split(data, &data[1], data->stack[i_max(data)]);
		// 	pw_backtrack_split(data, &data[1], data->stack[i_max(data)]);
		// }
		// x++;ft_putnbr(x);ft_putstr("_after_pw_backtrack_split\n");
		// pp_print_2stack(data[0], data[1], data[2]);
		
		// pw_backtrack(data, &data[1], data->stack[i_max(data)]);
		// x++;ft_putnbr(x);ft_putstr("_after_pw_backtrack\n");
		
	}
}

// pp_print_2stack_full(data[0], data[1]);
// pp_print_2stack(data[0], data[1]);
// pp_print_stack(data[0]);