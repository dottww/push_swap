/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:36:00 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 23:36:00 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotate(t_pp *data)
{
	int				tmp;
	int				top;
	unsigned int	i;

	if (data->len <= 1)
		return (0);
	else
	{
		top = data->len - 1;
		tmp = data->stack[top];
		i = 0;
		while (i < data->len - 1)
		{
			data->stack[top - i] = data->stack[top - i - 1];
			i++;
		}
		data->stack[0] = tmp;
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
	int				tmp;
	int				top;
	unsigned int	i;

	if (data->len <= 1)
		return (0);
	else
	{
		top = data->len - 1;
		tmp = data->stack[0];
		i = 0;
		while (i < data->len - 1)
		{
			data->stack[i] = data->stack[i + 1];
			i++;
		}
		data->stack[top] = tmp;
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