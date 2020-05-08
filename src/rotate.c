/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:36:00 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 19:23:29 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotate(t_pp *data)
{
	int tmp;
	int top;
	int i;

	if (data[0].len <= 1)
		return (0);
	else
	{
		top = data[0].len - 1;
		tmp = data[0].stack[top];
		i = 0;
		while (i < data[0].len - 1)
		{
			data[0].stack[top - i] = data[0].stack[top - i - 1];
			i++;
		}
		data[0].stack[0] = tmp;
		return (1);
	}
}

void ft_ra(t_pp *data, char c)
{
	ft_rotate(data);c ? write(1, "ra\n", 3) : 0;
	data->g++;
}

void ft_rb(t_pp *data, char c)
{
	ft_rotate(&data[1]);c ? write(1, "rb\n", 3) : 0;
	data->g++;
}

void ft_rr(t_pp *data, char c)
{
	ft_ra(data,0);
	ft_rb(data,0);
	c?write(1, "rr\n", 3) : 0;
}

int ft_rev_rotate(t_pp *data)
{
	int tmp;
	int top;
	int i;

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

void ft_rra(t_pp *data, char c)
{
	ft_rev_rotate(data);
	c ? write(1, "rra\n", 4) : 0;
	data->g++;
}

void ft_rrb(t_pp *data, char c)
{
	ft_rev_rotate(&data[1]);
	c ? write(1, "rrb\n", 4) : 0;
	data->g++;
}

void ft_rrr(t_pp *data, char c)
{
	ft_rev_rotate(data);
	ft_rev_rotate(&data[1]);
	c ? write(1, "rrr\n", 4) : 0;
	data->g++;
}