/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:48:37 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 04:31:37 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_average(t_pp *data)
{
	long long avg;
	int i;

	if (data[0].len == 0)
		return (0);
	i = 0;
	avg = 0;
	while (i < data[0].len)
		avg += data[0].stack[i++];
	avg /= data[0].len;
	// printf("get_average=%lld\n", sum);
	return (avg);
}

int i_max(t_pp *data)
{
	// int max;
	// max = data[0].stack[0];
	// max = (max > data[0].stack[i]) ? max : data[0].stack[i];
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < data->len)
	{
		j = (data->stack[j] > data->stack[i]) ? j : i;
		i++;
	}
	return (j);
}

int i_min(t_pp *data)
{
	// int min;
	// min = data[0].stack[0];
	// min = (min < data[0].stack[i]) ? min : data[0].stack[i];
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < data->len)
	{
		// printf("i,j=%d,%d\n",i,j);
		j = (data->stack[j] < data->stack[i]) ? j : i;
		i++;
	}
	return (j);
}

int get_max_min(t_pp *data, int control)
{
	// int min;
	// min = data[0].stack[0];
	// min = (min < data[0].stack[i]) ? min : data[0].stack[i];
	int i;
	int min;
	int max;

	i = 1;
	min = 0;
	max = 0;
	while (i < data->len)
	{
		if (data[0].stack[i] < min)
			min = data[0].stack[i];
		if (data[0].stack[i] > max)
			max = data[0].stack[i];
		i++;
	}
	// ft_putstr("CALrank_min=");
	// ft_putnbr(min);
	// ft_putstr("\n");
	// ft_putstr("CALrank_max=");
	// ft_putnbr(max);
	// ft_putstr("\n");
	return ((control) ? max : min);
}

int rank_dif_1(t_pp *a, int a_i, t_pp *b, int b_j)
{
	int i;
	int x[2];
	
	if (a->len == 0 || b->len == 0)
		return (0);
	i = 0;
	b_j = (b_j == -1) ? (b->len - 1) : b_j;
// printf("A: ai,bj=%d,%d\n",a_i,b_j);
	while (i < a[2].len)
	{
		// printf("W(%d): set(%d,%d)\n",i,a->stack[a_i],b->stack[b_j]);
		// printf("rank[%d]=%d\n",i,a[2].stack[i]);
		if (b->stack[b_j] == a[2].stack[i])
			x[1] = i;
		if (a->stack[a_i] == a[2].stack[i])
			x[0] = i;
		i++;
	}
	// printf("B: ai,bj=%d,%d\n",a_i,b_j);
	return (((x[0] - x[1]) == 1) ? 1 : 0);
}

int quick_sort_once(int *a, int low, int high, t_pp *data)
{
	// 将首元素作为枢轴。
	int pivot = a[low];
	int i = low, j = high;
	// printf("I,pivot=%d,i=%d,j=%d\n", pivot, i, j);
	if (!data[0].stack)
		return (0);
	while (i < j)
	{
		// 从右到左，寻找首个小于pivot的元素。
		while (a[j] >= pivot && i < j)
		{
			j--;
		}
		// 执行到此，j已指向从右端起首个小于或等于pivot的元素。
		// 执行替换。
		a[i] = a[j];
		// printf("II,i=%d,j=%d\n", i, j);
		// pp_print_2stack_full(data[0], data[1]);
		// 从左到右，寻找首个大于pivot的元素。
		while (a[i] <= pivot && i < j)
		{
			i++;
		}

		// 执行到此，i已指向从左端起首个大于或等于pivot的元素。
		// 执行替换。
		a[j] = a[i];
		// printf("III,i=%d,j=%d\n", i, j);
		// pp_print_2stack_full(data[0], data[1]);
	}

	// 退出while循环，执行至此，必定是i=j的情况。
	// i（或j）指向的即是枢轴的位置，定位该趟排序的枢轴并将该位置返回。
	a[i] = pivot;
	// printf("IV,i=%d,j=%d\n", i, j);
	// pp_print_2stack_full(data[0], data[1]);

	return i;
}
int qq2(int *a, int low, int high, t_pp *data)
{
	// 将首元素作为枢轴。
	int pivot = a[low];
	int i = low, j = high;
	// printf("I,pivot=%d,i=%d,j=%d\n", pivot, i, j);
	if (!data[0].stack)
		return (0);
	while (i < j)
	{
		// 从右到左，寻找首个小于pivot的元素。
		while (a[j] <= pivot && i < j)
		{
			j--;
		}
		// 执行到此，j已指向从右端起大于pivot的元素。
		// 执行替换。
		a[i] = a[j];
		// printf("II,i=%d,j=%d\n", i, j);
		// pp_print_2stack_full(data[0], data[1]);
		// 从左到右，寻找首个大于pivot的元素。
		while (a[i] >= pivot && i < j)
		{
			i++;
		}

		// 执行到此，i已指向从左端起首个大于或等于pivot的元素。
		// 执行替换。
		a[j] = a[i];
		// printf("III,i=%d,j=%d\n", i, j);
		// pp_print_2stack_full(data[0], data[1]);
	}

	// 退出while循环，执行至此，必定是i=j的情况。
	// i（或j）指向的即是枢轴的位置，定位该趟排序的枢轴并将该位置返回。
	a[i] = pivot;
	// printf("IV,i=%d,j=%d\n", i, j);
	// pp_print_2stack_full(data[0], data[1]);

	return i;
}
void quick_sort(int *a, int low, int high, t_pp *data) //t_pp *data 最後要刪掉
{
	if (low >= high)
	{
		return;
	}
	// static int i;
	// i++;
	int pivot = qq2(a, low, high, data);
	// printf("SortOnce runtime %d low=%d, high=%d pivot=%d\n", i, low, high, pivot);

	// 对枢轴的左端进行排序。
	// printf("quick_sortIN1 runtime %d low=%d, high=%d pivot=%d\n", i, low, pivot - 1, pivot);
	quick_sort(a, low, pivot - 1, data);

	// 对枢轴的右端进行排序。
	// printf("quick_sortIN2 runtime %d low=%d, high=%d pivot=%d\n", i, pivot + 1, high, pivot);
	quick_sort(a, pivot + 1, high, data);
}

int median_rank(t_pp *data)
{
	t_pp *rank;
	int x1;
	int x2;

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

void ft_print_int_tables(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("=");
		ft_putnbr(tab[i]);
		i++;
		(i != size) ? ft_putstr(", ") : 0;
	}
}