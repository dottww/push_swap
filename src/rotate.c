/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:36:00 by weilin            #+#    #+#             */
/*   Updated: 2020/03/12 01:01:56 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotate(t_pp *data)
{
	int	tmp;
	int	top;
	int	i;

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

void ft_ra(t_pp *data)
{
	ft_rotate(data) ? write(1, "ra\n", 3) : 0;
}

void ft_rb(t_pp *data)
{
	ft_rotate(&data[1]) ? write(1, "rb\n", 3) : 0;
}

void ft_rr(t_pp *data)
{
	ft_ra(data);
	ft_rb(data);
}

int ft_rev_rotate(t_pp *data)
{
	int				tmp;
	int				top;
	 int	i;

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

void ft_rra(t_pp *data)
{
	ft_rev_rotate(data) ? write(1, "rra\n", 4) : 0;
}

void ft_rrb(t_pp *data)
{
	ft_rev_rotate(&data[1]) ? write(1, "rrb\n", 4) : 0;
}

void	ft_rrr(t_pp *data)
{
	ft_rra(data);
	ft_rrb(data);
}