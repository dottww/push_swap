/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:31:28 by weilin            #+#    #+#             */
/*   Updated: 2020/03/08 01:07:50 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

int is_ascending(int *stack, int total)
{
	int i;
	int isacend;

	i = 1;
	isacend = 1;
	while (i < total)
	{
		if ((stack[i] > stack[i - 1]))
		{
			isacend = 0;
			break;
		}
		i++;
	}
	return (isacend);
}
int QuickSortOnce(int *a, int low, int high, t_pp data[2])
{
	// 将首元素作为枢轴。
	int pivot = a[low];
	int i = low, j = high;
	printf("I,pivot=%d,i=%d,j=%d\n", pivot, i, j);

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
		printf("II,i=%d,j=%d\n", i, j);
		pp_print_2stack_full(data[0], data[1]);
		// 从左到右，寻找首个大于pivot的元素。
		while (a[i] <= pivot && i < j)
		{
			i++;
		}

		// 执行到此，i已指向从左端起首个大于或等于pivot的元素。
		// 执行替换。
		a[j] = a[i];
		printf("III,i=%d,j=%d\n", i, j);
		pp_print_2stack_full(data[0], data[1]);
	}

	// 退出while循环，执行至此，必定是i=j的情况。
	// i（或j）指向的即是枢轴的位置，定位该趟排序的枢轴并将该位置返回。
	a[i] = pivot;
	printf("IV,i=%d,j=%d\n", i, j);
	pp_print_2stack_full(data[0], data[1]);

	return i;
}

void QuickSort(int *a, int low, int high, t_pp data[2])
{
	if (low >= high)
	{
		return;
	}
	static int i;
	i++;
	int pivot = QuickSortOnce(a, low, high, data);
	printf("SortOnce runtime %d low=%d, high=%d pivot=%d\n", i, low, high, pivot);

	// 对枢轴的左端进行排序。
	printf("QuickSortIN1 runtime %d low=%d, high=%d pivot=%d\n", i, low, pivot - 1, pivot);
	QuickSort(a, low, pivot - 1, data);

	// 对枢轴的右端进行排序。
	printf("QuickSortIN2 runtime %d low=%d, high=%d pivot=%d\n", i, pivot + 1, high, pivot);
	QuickSort(a, pivot + 1, high, data);
}

int get_medium(int *a, int total, t_pp data[2])
{
	QuickSort(a, 0, total - 1, data);

	if (total % 2 != 0)
	{
		return a[total / 2];
	}
	else
	{
		return (a[total / 2] + a[total / 2 - 1]) / 2;
	}
}

void ft_sort_integer_small(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
void ft_sort_integer_big(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] < tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
void addNumber2(int num, t_pp *temp)
{
	int *big_queue = temp[0].stack;
	int *small_queue = temp[1].stack;

	if (temp[0].len == 0)
	{
		big_queue[temp[0].len] = num;
		temp[0].len++;
	}
	else if (temp[0].len == temp[1].len)
	{
		if (num < big_queue[temp[0].len - 1])
		{
			big_queue[temp[0].len] = num;
			temp[0].len++;
		}
		else
		{
			small_queue[temp[1].len] = num;
			temp[1].len++;
		}
	}
	else if (temp[0].len > temp[1].len)
	{
		if (num > big_queue[temp[0].len - 1])
		{
			small_queue[temp[1].len] = num;
			temp[1].len++;
		}
		else
		{
			small_queue[temp[1].len] = big_queue[temp[0].len - 1];
			temp[1].len++;
			big_queue[temp[0].len - 1] = num;
		}
	}
	else if (temp[0].len < temp[1].len)
	{
		if (num < small_queue[temp[1].len - 1])
		{
			big_queue[temp[0].len] = num;
			temp[0].len++;
		}
		else
		{
			big_queue[temp[1].len] = small_queue[temp[0].len - 1];
			temp[0].len++;

			small_queue[temp[0].len - 1] = num;
		}
	}
}
void addNumber(int n, t_pp *temp)
{

	// int *max_heap = temp[0].stack;
	// int *min_heap = temp[1].stack;

	if (temp[0].len == 0)
	{
		// maxHeap.add(n);
		temp[0].stack[temp[0].len] = n;
		temp[0].len++;
		// ft_sort_integer_big(temp[0].stack,temp[0].len);
	}
	// else if (maxHeap.size() == minHeap.size())
	else if (temp[0].len == temp[1].len)
	{
		// if (n < minHeap.peek())
		if (n < temp[1].stack[temp[1].len - 1])
		{
			// maxHeap.add(n);
			temp[0].stack[temp[0].len] = n;
			temp[0].len++;
			// ft_sort_integer_big(temp[0].stack,temp[0].len);
		}
		else
		{
			// minHeap.add(n);
			temp[1].stack[temp[1].len] = n;
			temp[1].len++;
			// ft_sort_integer_small(temp[1].stack,temp[1].len);
			// maxHeap.add(minHeap.remove());
			temp[0].stack[temp[0].len] = n;
			temp[0].len++;
			// ft_sort_integer_big(temp[0].stack,temp[0].len);
			temp[1].len--;
		}
	}
	// else if (maxHeap.size() > minHeap.size())
	else if (temp[0].len > temp[1].len)
	{
		// if (n > maxHeap.peek())
		if (n > temp[0].stack[temp[0].len - 1])
		{
			// minHeap.add(n);
			temp[1].stack[temp[1].len] = n;
			temp[1].len++;
			// ft_sort_integer_small(temp[1].stack,temp[1].len);
		}
		else
		{
			// maxHeap.add(n);
			temp[0].stack[temp[0].len] = n;
			temp[0].len++;
			// ft_sort_integer_big(temp[0].stack,temp[0].len);

			// minHeap.add(maxHeap.remove());
			temp[1].stack[temp[1].len] = n;
			temp[1].len++;
			// ft_sort_integer_small(temp[1].stack,temp[1].len);
			temp[0].len--;
		}
	}

	// maxHeap will never have fewer elements than minHeap
}

// int get_medium2(int *a, int total, t_pp data[2])
// {

// 	if (temp[0].len == 0)
// 	{
// 		return 0;
// 	}
// 	else if (temp[0].len == temp[1].len)
// 	{
// 		return (maxHeap.peek() + minHeap.peek()) / 2.0;
// 	}
// 	else
// 	{ // maxHeap must have more elements than minHeap
// 		return maxHeap.peek();
// 	}
// }
void medianTracker(t_pp data[2], int total)
{
	int i = 0;
	t_pp temp[2];

	temp[0].stack = (int *)malloc(sizeof(int) * (total));
	temp[1].stack = (int *)malloc(sizeof(int) * (total));
	// temp[0].t_len = total;
	temp[0].len = 0;
	// temp[1].t_len = total;
	temp[1].len = 0;

	while (i < total)
	{
		addNumber(data[0].stack[i], temp);

		printf("maxheap=");
		for (int j = 0; j < (int)temp[0].len; j++)
		{
			printf("%d, ", temp[0].stack[j]);
		}
		printf("\n");
		printf("minheap=");
		for (int k = 0; k < (int)temp[1].len; k++)
		{
			printf("%d, ", temp[1].stack[k]);
		}
		printf("\n");

		i++;
	}
}
int get_average(t_pp data[2])
{
	unsigned long long sum;
	size_t i;

	i = 0;
	sum = 0;
	while (i < data[0].t_len)
	{
		sum += data[0].stack[i++];
	}
	sum /= data[0].t_len;
	printf("get_average=%lld\n", sum);
	return (sum);
}

int get_max(t_pp data[2])
{
	int max;
	size_t i;

	i = 1;
	max = data[0].stack[0];
	while (i < data[0].t_len)
	{
		max = (max > data[0].stack[i]) ? max : data[0].stack[i];
		i++;
	}
	return (max);
}

int get_min(t_pp data[2])
{
	int min;
	size_t i;

	i = 1;
	min = data[0].stack[0];
	while (i < data[0].t_len)
	{
		min = (min < data[0].stack[i]) ? min : data[0].stack[i];
		i++;
	}
	return (min);
}

void push_swap(t_pp data[2])
{
	// int pivot;
	int average;
	int max;
	int min;
	// int medium;

	average = get_average(data);
	max = get_max(data);
	min = get_min(data);
	printf("get_max=%d\n", max);
	printf("get_min=%d\n", min);
	// medium = get_medium(data[0].stack, data[0].t_len, data);
	// printf("get_medium=%d\n", medium);
	medianTracker(data, data[0].t_len);
	// if (data[0].t_len == 4 || data[0].t_len == 5)
	// {
	// 	ft_pb(&data[0], &data[1]);
	// 	ft_pb(&data[0], &data[1]);
	// 	push_swap_3(data);
	// }
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
	// pp_print_2stack_full(data[0], data[1]);
	// if (is_ascending(data[0].stack, data[0].t_len))
	// printf("yes ascending\n");
	// cleanall(data, av, 0);
	// free(data[0].stack);
	// free(data[1].stack);
	// system("leaks push_swap");
	return (0);
}