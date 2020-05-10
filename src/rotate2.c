/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 01:36:57 by weilin            #+#    #+#             */
/*   Updated: 2020/05/10 02:13:50 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rev_rotate(t_pp *data)
{
	int	tmp;
	int	top;
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

void	ft_rra(t_pp *data, char c)
{
	ft_rev_rotate(data);
	c ? write(1, "rra\n", 4) : 0;
	data->g++;
}

void	ft_rrb(t_pp *data, char c)
{
	ft_rev_rotate(&data[1]);
	c ? write(1, "rrb\n", 4) : 0;
	data->g++;
}

void	ft_rrr(t_pp *data, char c)
{
	ft_rev_rotate(data);
	ft_rev_rotate(&data[1]);
	c ? write(1, "rrr\n", 4) : 0;
	data->g++;
}
