/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 08:47:36 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 19:34:54 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// static void dd()
// {
// 	int x = 0;
// 	x++;
// }
void ft_push_swap(t_pp *a, t_pp *b)
{
	// ft_putstr("ft_push_swap & a->g=");
	// ft_putnbr(a[0].g);
	// ft_putstr("\n");
	
	int b_v_max;
	// if (a->g > 500)
	// 	dd();
	if (b->len == 0)
		return;
	// static int k = 0;
	// ft_putstr("k=");
	// ft_putnbr(k);
	// ft_putstr("\n");
	// k++;
	// pp_print_3stack(a[0], a[1], a[2]);
	// int ww=b->stack[i_max(b)];
	// (void)ww;
	b_v_max = get_max_min(b, 1);
	// ft_putstr("max1=");
	// ft_putnbr(b_v_max);
	// ft_putstr("\n");
	pw_split_to_a(a, b, get_average(b), b->len);
	while (
		(
			rank_dif_1(a, 0, a, -1) ||
			a->stack[a->len - 1] == get_max_min(&a[2], 0)) &&
		!pw_is_sorted(a->stack, a->len))
		ft_ra(a,1);
	ft_push_swap(a, b);
	// ft_putstr("pw_get_size(a, max)=");
	// ft_putnbr(pw_i_next_to_min(a, b_v_max));
	// ft_putstr("\n");
	if (pw_i_next_to_min(a, b_v_max) >= 20)
		pw_backtrack_split(a, b, b_v_max, 0);
	// ft_putstr("max2=");
	// ft_putnbr(b_v_max);
	// ft_putstr("\n");
	// static int k = 0;
	// if (a->g == 114 && k == 0)
	// {
	// 	get_max_min(b, 1);
		// pp_print_2stack(a[0], a[1], a[2]);
	// 	k = 1;
	// }
	pw_backtrack(a, b, b_v_max);
	// }
}
