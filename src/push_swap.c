/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:31:28 by weilin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/10 20:36:59 by weilin           ###   ########.fr       */
=======
/*   Updated: 2020/03/10 19:16:45 by weilin           ###   ########.fr       */
>>>>>>> 55c943122b8d2072c3fa2f414c7f3460416d09a6
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>



int QuickSortOnce(int *a, int low, int high, t_pp data[2])
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

void QuickSort(int *a, int low, int high, t_pp data[2])
{
	if (low >= high)
	{
		return;
	}
	// static int i;
	// i++;
	int pivot = QuickSortOnce(a, low, high, data);
	// printf("SortOnce runtime %d low=%d, high=%d pivot=%d\n", i, low, high, pivot);

	// 对枢轴的左端进行排序。
	// printf("QuickSortIN1 runtime %d low=%d, high=%d pivot=%d\n", i, low, pivot - 1, pivot);
	QuickSort(a, low, pivot - 1, data);

	// 对枢轴的右端进行排序。
	// printf("QuickSortIN2 runtime %d low=%d, high=%d pivot=%d\n", i, pivot + 1, high, pivot);
	QuickSort(a, pivot + 1, high, data);
}

int get_medium(t_pp data[2])
{

	int *a;
	int total;

	a = data[1].stack;
	total = data[1].t_len;

	QuickSort(a, 0, total - 1, data);

	int x1 = a[total / 2];
	int x2 = a[(total / 2) - 1];
	// printf("x1,x2=[%d][%d]\n", x1, x2);
	if (total % 2 != 0)
	{
		return x1;
	}
	else
	{
		return ((x1 + x2) / 2);
	}
}
void push_swap_3(int *a, t_pp data[2])
{
	// int *a;

	// a = data[0].stack;
	if (!((a[2] > a[0] && a[0] > a[1]) || (a[1] > a[2] && a[2] > a[0])))
		ft_sa(&data[0]);
	((a[2] > a[1]) && (a[2] > a[0])) ? ft_ra(&data[0]) : 0;
	((a[0] < a[1]) && (a[0] < a[2])) ? ft_rra(&data[0]) : 0;
}
void push_swap(t_pp data[2])
{
	// int pivot;
	// int average;
	// average = get_average(data);
	// int max;
	// int min;
	// max = get_max(data);
	// printf("get_max=%d\n", max);
	// min = get_min(data);
	// printf("get_min=%d\n", min);
	// int medium;
	// medium = get_medium(data);
	// printf("get_medium=%d\n", medium);

	// pp_print_2stack(data[0], data[1]);
	if (is_ascending(data[0].stack, data[0].t_len))
		return ;
		// printf("pre_OKOKOK\n");
	else if (data[0].t_len <= 5)
	{
		(data[0].t_len == 5) ? ft_pb(&data[0], &data[1]) : 0;
		(data[0].t_len == 5 || data[0].t_len == 4) ? ft_pb(&data[0], &data[1]) : 0;
		if (!is_ascending(data[0].stack, data[0].len))
			push_swap_3(data[0].stack, data);
		// printf("not_yet\n");
		// pp_print_2stack(data[0], data[1]);
	}
	else
		return ;
	// if (is_ascending(data[0].stack, data[0].t_len))
	// 	printf("now_OKOKOK\n");
	// else
	// 	printf("still_not_OK\n");
<<<<<<< HEAD
=======

>>>>>>> 55c943122b8d2072c3fa2f414c7f3460416d09a6
	
	// ft_ra(data);
	// ft_ra(&data[0]);
	// ft_pb(data, data + 1);
	// ft_ra(&data[0]);
	// ft_pb(&data[0], &data[1]);
	// ft_sa(&data[0]);
	// ft_ra(&data[0]);
	// ft_sa(&data[0]);
	// ft_rra(&data[0]);
	// ft_sa(&data[0]);
	// ft_pa(&data[0], &data[1]);
	// ft_pa(&data[0], &data[1]);
}
int main(int ac, char **av)
{
	int i;
	t_pp data[2];

	if (ac > 1)
	{
		i = 1;
		if (!ft_check_args(ac - 1, av, data, i))
			return (0);
	}
	// pp_print_2stack_full(data[0], data[1]);
	push_swap(data);
	// pp_print_2stack(data[0], data[1]);
	// pp_print_stack(data[0]);
	cleanall(data, av, 0);
	// system("leaks push_swap");
	return (0);
}