/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:13:05 by weilin            #+#    #+#             */
/*   Updated: 2020/03/12 01:01:18 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_pp *d_orig, t_pp *d_dest)
{
	int	ori;
	int	dst;

	if (d_orig->len == 0)
		return (0);
	else
	{
		ori = d_orig->len - 1;
		dst = (d_dest->len) ? d_dest->len : 0;
		d_dest->stack[dst] = d_orig->stack[ori];
		d_orig->len -= 1;
		d_dest->len += 1;
		return (1);
	}
}

void	ft_pa(t_pp *data)
{
	ft_push(&data[1], data) ? ft_putstr("pa\n") : 0;
}

void	ft_pb(t_pp *data)
{
	ft_push(data, &data[1]) ? write(1,"pb\n", 3) : 0;
}