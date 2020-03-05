/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:36:00 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 21:23:23 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotate(t_pp *data)
{
	int				tmp_addr;
	int				top;
	unsigned int	i;

	if (data->len <= 1)
		return (0);
	else
	{
		top = data->t_len - data->len;
		tmp_addr = data->stack[top];
		i = 0;
		while (i < data->len - 1)
		{
			data->stack[top + i] = data->stack[top + i + 1];
			i++;
		}
		data->stack[data->t_len - 1] = tmp_addr;
		return (1);
	}
}

void ft_ra(t_pp *a)
{
	ft_rotate(a) ? write(1, "ra\n", 3) : 0;
}

void ft_rb(t_pp *b)
{
	ft_rotate(b) ? write(1, "rb\n", 3) : 0;
}

void ft_rr(t_pp *data1, t_pp *data2)
{
	ft_ra(data1);
	ft_rb(data2);
}

int ft_rev_rotate(t_pp *data)
{
	int				tmp_addr;
	int				btm;
	unsigned int	i;

	if (data->len <= 1)
		return (0);
	else
	{
		btm = data->t_len - 1;
		tmp_addr = data->stack[btm];
		i = 0;
		while (i < data->len - 1)
		{
			data->stack[btm - i] = data->stack[btm - i - 1];
			i++;
		}
		data->stack[data->t_len - data->len] = tmp_addr;
		return (1);
	}
}

void ft_rra(t_pp *a)
{
	ft_rev_rotate(a) ? write(1, "rra\n", 4) : 0;
}

void ft_rrb(t_pp *b)
{
	ft_rev_rotate(b) ? write(1, "rrb\n", 4) : 0;
}