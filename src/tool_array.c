/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:48:37 by weilin            #+#    #+#             */
/*   Updated: 2020/03/10 20:34:17 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_average(t_pp data[2])
{
	unsigned long long sum;
	size_t i;

	i = 0;
	sum = 0;
	while (i < data[0].t_len)
		sum += data[0].stack[i++];
	sum /= data[0].t_len;
	// printf("get_average=%lld\n", sum);
	return (sum);
}

int get_max(t_pp data[2])
{
	// int max;
	// max = data[0].stack[0];
	// max = (max > data[0].stack[i]) ? max : data[0].stack[i];
	size_t	i;
	int		j;

	i = 1;
	j = 0;
	while (i < data[0].t_len)
	{
		j = (data[0].stack[j] > data[0].stack[i]) ? j : i;
		i++;
	}
	return (j);
}

int get_min(t_pp data[2])
{
	// int min;
	// min = data[0].stack[0];
	// min = (min < data[0].stack[i]) ? min : data[0].stack[i];
	size_t	i;
	int		j;

	i = 1;
	j = 0;
	while (i < data[0].t_len)
	{
		j = (data[0].stack[j] < data[0].stack[i]) ? j : i;
		i++;
	}
	return (j);
}

int get_max_min(t_pp data[2], int control)
{
	// int min;
	// min = data[0].stack[0];
	// min = (min < data[0].stack[i]) ? min : data[0].stack[i];
	size_t	i;
	int		min;
	int		max;

	i = 1;
	min = 0;
	max = 0;
	while (i < data[0].t_len)
	{
		min = (data[0].stack[min] < data[0].stack[i]) ? min : i;
		max = (data[0].stack[max] > data[0].stack[i]) ? max : i;
		i++;
	}
	return ((control) ? max : min);
}