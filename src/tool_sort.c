/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 01:46:23 by weilin            #+#    #+#             */
/*   Updated: 2020/05/10 02:14:52 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		quick_sort_once(int *a, int low, int high, t_pp *data)
{
	int	pivot;
	int	i;
	int	j;

	pivot = a[low];
	i = low;
	j = high;
	if (!data[0].stack)
		return (0);
	while (i < j)
	{
		while (a[j] <= pivot && i < j)
			j--;
		a[i] = a[j];
		while (a[i] >= pivot && i < j)
			i++;
		a[j] = a[i];
	}
	a[i] = pivot;
	return (i);
}

void	quick_sort(int *a, int low, int high, t_pp *data)
{
	int	pivot;

	if (low >= high)
		return ;
	pivot = quick_sort_once(a, low, high, data);
	quick_sort(a, low, pivot - 1, data);
	quick_sort(a, pivot + 1, high, data);
}

int		median_rank(t_pp *data)
{
	t_pp	*rank;
	int		x1;
	int		x2;

	rank = &data[2];
	dup_tpp(data, rank, data[0].t_len);
	quick_sort(rank->stack, 0, rank->t_len - 1, rank);
	x1 = rank->stack[rank->t_len / 2];
	x2 = rank->stack[(rank->t_len / 2) - 1];
	if (rank->t_len % 2 == 0)
		return ((x1 + x2) / 2);
	else
		return (x1);
}

int		rank_dif_1(t_pp *a, int a_i, t_pp *b, int b_j)
{
	int	i;
	int	x[2];

	if (a->len == 0 || b->len == 0)
		return (0);
	i = 0;
	b_j = (b_j == -1) ? (b->len - 1) : b_j;
	while (i < a[2].len)
	{
		if (b->stack[b_j] == a[2].stack[i])
			x[1] = i;
		if (a->stack[a_i] == a[2].stack[i])
			x[0] = i;
		i++;
	}
	return (((x[0] - x[1]) == 1) ? 1 : 0);
}
