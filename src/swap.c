/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:56:38 by weilin            #+#    #+#             */
/*   Updated: 2020/03/12 01:01:38 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_swap(t_pp *data)
{
	int		tmp;
	int		top;

	top = data->len - 1;
	if (data->len <= 1)
		return (0);
	else
	{
		tmp = data->stack[top];
		data->stack[top] = data->stack[top - 1];
		data->stack[top - 1] = tmp;
		return (1);
	}
}
void	ft_sa(t_pp *data)
{
	ft_swap(data) ? write(1,"sa\n", 3) : 0;
}

void	ft_sb(t_pp *data)
{
	ft_swap(&data[1]) ? write(1,"sb\n", 3) : 0;
}

void	ft_ss(t_pp *data)
{
	ft_sa(data);
	ft_sb(data);
}