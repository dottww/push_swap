/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:14:27 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 14:04:28 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** FUNCTION:	pp_print_addr
** ARGUMENTS:	t_pp data:
** DESCRIPTION:
** 		Print generic information about the data: len, start point.
** 		Then it print the address the start and head and all addresses of
** 		the cell of data.
** RETURN:
** 	None.
*/

// void pp_print_addr(t_pp data)
// {
// 	size_t i = data.start;
// 	size_t countdown = data.len;

// 	printf("total number of the list data.len=%d\n", data.len);
// 	printf("start point on the stack[%d] -- ", data.start);
// 	printf("start point address: %p\n", &data.stack[i % data.len]);
// 	printf("head stack address : %p\n", &data.stack[0]);
// 	while (countdown > 0)
// 	{
// 		printf("  address &data.pp[%zu] = %p\n", i - data.start, &data.stack[i % data.len]);
// 		i++;
// 		countdown--;
// 	}
// }

/*
** FUNCTION:	pp_print_2stack_full
** ARGUMENTS:	t_pp data1:
** 				t_pp data2:
** DESCRIPTION:
** 		Print generic information about the data: len, start point.
** 		Print the adresses and contents of data1 and data2
** RETURN:
** 	None.
*/

void pp_print_2stack_full(t_pp data1, t_pp data2)
{
	int j = 0;
	int ori;
	int dst;

	ori = data1.t_len;
	dst = data2.t_len;
	printf("\n-------------------------data1-------data2\n");
	printf("Number of int in .stack:  %zu           %zu\n", data1.t_len, data2.t_len);
	// printf("Index of start in stack:  %d           %d\n", ori, dst);
	printf("--------------------------------------------------------data1--------------||---------------------data2-----------\n");
	while (j < (int)data1.t_len)
	{
		if (j < data1.len)
			printf("[Cell adress]|[content][*content]: [%14p]|[%14p]|[%4d] ||", &(data1.stack[j]), &data1.stack[j], data1.stack[j]);
		else
			printf("[Cell adress]|[content][*content]: [%14p]|[%14p]|[%s] ||", &(data1.stack[j]), &data1.stack[j], "null");
		if (j < (int)data2.t_len)
			printf(" [%14p]|[%14p]|[%4d]\n", &(data2.stack[j]), &data2.stack[j], data2.stack[j]);
		else
			printf(" [%14p]|[%14p]|[%s]\n", &(data2.stack[j]), &data2.stack[j], "null");
		j++;
	}
	printf("-------------------------------------------------------------------------||-------------------------------------\n\n");
}

/*
** FUNCTION:	pp_print_2stack_full
** ARGUMENTS:	t_pp data1:
** 				t_pp data2:
** DESCRIPTION:
** 		Print generic information about the data: len, start point.
** 		Print the adresses and contents of data1 and data2
** RETURN:
** 	None.
*/

void pp_print_1stack_full(t_pp data)
{
	int j = 0;

	printf("\n-------------------------data----\n");
	printf("Number of int in .stack:  %d\n", data.len);
	// printf("Start index in .stack  :  %d\n", data.start);
	printf("--------------------------------------------------------data1---------------\n");
	while (j < data.len)
	{
		// if (data.stack[j])
		// 	printf("[Cell adress]|[content][*content]: [%p]|[%p]|[%s]\n", &(data.stack[j]), &data.stack[j], "null");
		// else
		printf("[Cell adress]|[content][*content]: [%p]|[%p]|[%d]\n", &(data.stack[j]), &data.stack[j], data.stack[j]);
		j++;
	}
	printf("---------------------------------------------------------------------------\n\n");
}

/*
** FUNCTION:	pp_print_stack
** ARGUMENTS:	t_pp data:
** DESCRIPTION:
** 		Print generic information about the data: len, start point.
** 		Print the content of data
** RETURN:
** 	None.
*/

void pp_print_stack(t_pp data)
{
	size_t i = 0;
	// size_t countdown = data.len;

	printf("total number of the list data.len=%d\n", data.len);
	// printf("stack point on the stack[%d]\n", data.start);
	while (i < data.t_len)
	{
		printf("  data.pp[%zu]=%d\n", i, data.stack[i]);
		i++;
	}
}

void pp_print_2stack(t_pp data1, t_pp data2, t_pp data3)
{
	int j = 0;
	int ori;
	int dst;

	ori = data1.t_len;
	dst = data2.t_len;
	printf("\n-------------------------data1-------data2\n");
	printf("Number of int in .stack:  %d           %d\n", data1.len, data2.len);
	// printf("Index of start in stack:  %d           %d\n", ori, dst);
	printf("--------------------------------------------------------data1--------------||---------------------data2-----------\n");
	while (j < (int)data1.t_len)
	{
		if (j < data1.len)
			printf("dataA[%d] = |[%4d] || ", j, data1.stack[j]);
		else
			printf("dataA[%d] = |[%s] || ", j, "null");
		if (j < data2.len)
			printf("dataB[%d] = |[%4d] || ", j, data2.stack[j]);
		else
			printf("dataB[%d] = |[%s] || ", j, "null");
		if (j < data3.len)
			printf("dataC[%d] = |[%4d]\n", j, data3.stack[j]);
		else
			printf("dataC[%d] = |[%s]\n", j, "null");
		j++;
	}
	printf("-------------------------------------------------------------------------||-------------------------------------\n\n");
}

void pp_print_3stack(t_pp data1, t_pp data2, t_pp data3)
{
	int j = 0;
	int ori;
	int dst;

	ori = data1.t_len;
	dst = data2.t_len;
	ft_putstr("\n-------------------------data1-------data2\n");
	ft_putstr("Number of int in .stack:  ");
	ft_putnbr(data1.len);
	ft_putstr("           ");
	ft_putnbr(data2.len);
	ft_putstr("\n");
	ft_putstr("--------------------------------------------------------data1--------------||---------------------data2-----------\n");
	while (j < (int)data1.t_len)
	{
		if (j < data1.len)
		{
			ft_putstr("dataA[");
			ft_putnbr(j);
			ft_putstr("] = |[");
			ft_putnbr(data1.stack[j]);
			ft_putstr("] || ");
		}
		else
		{
			ft_putstr("dataA[");
			ft_putnbr(j);
			ft_putstr("] = |[");
			ft_putstr("null");
			ft_putstr("] || ");
		}
		if (j < data2.len)
		{
			ft_putstr("dataB[");
			ft_putnbr(j);
			ft_putstr("] = |[");
			ft_putnbr(data2.stack[j]);
			ft_putstr("] || ");
		}
		else
		{
			ft_putstr("dataB[");
			ft_putnbr(j);
			ft_putstr("] = |[");
			ft_putstr("null");
			ft_putstr("] || ");
		}
		if (j < data3.len)
			{
			ft_putstr("dataC[");
			ft_putnbr(j);
			ft_putstr("] = |[");
			ft_putnbr(data3.stack[j]);
			ft_putstr("] || \n");
		}
		else
		{
			ft_putstr("dataC[");
			ft_putnbr(j);
			ft_putstr("] = |[");
			ft_putstr("null");
			ft_putstr("] || \n");
		}
		j++;
	}
	ft_putstr("-------------------------------------------------------------------------||-------------------------------------\n\n");
}