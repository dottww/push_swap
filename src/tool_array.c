/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:48:37 by weilin            #+#    #+#             */
/*   Updated: 2020/05/10 02:07:24 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_average(t_pp *data)
{
	long long	avg;
	int			i;

	if (data[0].len == 0)
		return (0);
	i = 0;
	avg = 0;
	while (i < data[0].len)
		avg += data[0].stack[i++];
	avg /= data[0].len;
	return (avg);
}

int	i_max(t_pp *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < data->len)
	{
		j = (data->stack[j] > data->stack[i]) ? j : i;
		i++;
	}
	return (j);
}

int	i_min(t_pp *data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < data->len)
	{
		j = (data->stack[j] < data->stack[i]) ? j : i;
		i++;
	}
	return (j);
}

int	get_max_min(t_pp *data, int control)
{
	int	i;
	int	min;
	int	max;

	if (data->len == 0)
		return (0);
	i = 0;
	min = data[0].stack[0];
	max = data[0].stack[0];
	while (i < data->len)
	{
		if (data[0].stack[i] < min)
			min = data[0].stack[i];
		if (data[0].stack[i] > max)
			max = data[0].stack[i];
		i++;
	}
	return ((control) ? max : min);
}
