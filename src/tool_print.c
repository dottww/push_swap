/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:14:27 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 21:56:25 by weilin           ###   ########.fr       */
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

void	pp_print_addr(t_pp data)
{
	size_t i = data.start;
	size_t countdown = data.len;

	printf("total number of the list data.len=%zu\n", data.len);
	printf("start point on the stack[%d] -- ", data.start);
	printf("start point address: %p\n", &data.stack[i % data.len]);
	printf("head stack address : %p\n", &data.stack[0]);
	while (countdown > 0)
	{
		printf("  address &data.pp[%zu] = %p\n", i - data.start, &data.stack[i % data.len]);
		i++;
		countdown--;
	}
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

void	pp_print_2stack_full(t_pp data1, t_pp data2)
{
	size_t	j = 0;
    int	ori;
	int	dst;

    ori = data1.t_len - data1.len;
	dst = data2.t_len - data2.len;
	printf("\n-------------------------data1-------data2\n");
	printf("Number of int in .stack:  %zu           %zu\n", data1.t_len, data2.t_len);
	printf("Index of start in stack:  %d           %d\n", ori, dst);
	printf("--------------------------------------------------------data1--------------||---------------------data2-----------\n");
	while (j < data1.t_len)
	{
		// if (data1.stack[j] == NULL)
		// 	printf("[Cell adress]|[content][*content]: [%14p]|[%14p]|[%s] ||", &(data1.stack[j]), data1.stack[j], "null");
		// else
			printf("[Cell adress]|[content][*content]: [%14p]|[%14p]|[%4d] ||", &(data1.stack[j]), &data1.stack[j], data1.stack[j]);
		// if (data2.stack[j] == NULL)
		// 	printf(" [%14p]|[%14p]|[%s]\n", &(data2.stack[j]), &data2.stack[j], "null");
		// else
			printf(" [%14p]|[%14p]|[%4d]\n", &(data2.stack[j]), &data2.stack[j], data2.stack[j]);
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

void	pp_print_1stack_full(t_pp data)
{
	size_t	j = 0;

	printf("\n-------------------------data----\n");
	printf("Number of int in .stack:  %zu\n", data.len);
	printf("Start index in .stack  :  %d\n", data.start);
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

void	pp_print_stack(t_pp data)
{
	size_t i = data.start;
	size_t countdown = data.len;

	printf("total number of the list data.len=%zu\n", data.len);
	printf("stack point on the stack[%d]\n", data.start);
	while (countdown > 0)
	{
		printf("  data.pp[%zu]=%d\n", i - data.start, data.stack[i % data.len]);
		i++;
		countdown--;
	}
}