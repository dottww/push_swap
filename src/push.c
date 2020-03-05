/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:13:05 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 20:50:18 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_pp *d_orig, t_pp *d_dest)
{
	int	ori;
	int	dst;

	if (d_orig->len == 0)
		return 0;
	else
	{
		ori = d_orig->t_len - d_orig->len;
		dst = d_dest->t_len - d_dest->len - 1;
		d_dest->stack[dst] = d_orig->stack[ori];
		// d_orig->stack[ori] = NULL;
		d_orig->len -= 1;
		d_dest->len += 1;
		return 1;
	}
}
// int	ft_push(t_pp *d_orig, t_pp *d_dest)
// {
// 	int	ori;
// 	int	dst;

// 	if (d_orig->len == 0)
// 		return 0;
// 	else
// 	{
// 		ori = d_orig->start;
// 		dst = d_dest->start;
// 		d_dest->stack[dst] = d_orig->stack[ori];
// 		d_orig->stack[ori] = NULL;
// 		d_orig->len -= 1;
// 		d_dest->len += 1;
// 		d_dest->start++;
// 		d_dest->start -= (d_dest->start >= d_dest->t_len) ? d_dest->t_len : 0;
// 		return 1;
// 	}
// }


void	ft_pa(t_pp *a, t_pp *b)
{
	ft_push(b, a) ? write(1,"pa\n", 3) : 0;
}

void	ft_pb(t_pp *a, t_pp *b)
{
	ft_push(a, b) ? write(1,"pb\n", 3) : 0;
}