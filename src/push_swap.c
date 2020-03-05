/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:31:28 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 22:50:40 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

// void ft_tpp_sa(t_pp *tpp, char *s)
// {
// 	printf("sa -%s-\n", s);
// 	// size_t i = tpp->start;

// 	int tmp;
// 	printf("print len -%zu- :\n", tpp->len);
// 	tmp = *tpp->stack[tpp->len - 1];
// 	*tpp->stack[tpp->len - 1] = *tpp->stack[tpp->len - 2];
// 	*tpp->stack[tpp->len - 2] = tmp;
// }
// void ft_tpp_print(t_pp *tpp, char *s)
// {
// 	printf("print stack -%s- :\n", s);

// 	size_t i = tpp->start;
// 	size_t lentmp = tpp->len;

// 	// printf("total stack_pp len=%zu\n", tpp->len);
// 	// printf("stack_pp starts at stack[%d]\n", tpp->start);

// 	while (lentmp)
// 	{
// 		if (tpp->len - i < 1)
// 			i -= tpp->len;
// 		printf("stack_pp[%zu]=%d\n", tpp->len - lentmp, *tpp->stack[i]);
// 		lentmp--;
// 		i++;
// 	}
// }
int isascending(int *stk0, int total)
{
	int i;
	int isacend;

	i = 0;
	isacend = 1;
	while (i < total)
	{
		if (isacend == 1 && i != 0 && (stk0[i] < stk0[i - 1]))
		{
			isacend = 0;
			break;
		}
		i++;
	}
	return (isacend);
}
int main(int ac, char **av)
{
	int i;
	t_pp data[2];
	// typedef struct s_ctr
	// {
	// 	int isacend;
	// 	size_t len;
	// 	size_t t_len;
	// 	int **stack;
	// } t_ctr;
	// system("leaks push_swap");

	if (ac > 1)
	{
		i = 1;
		if (!ft_check_args(ac - 1, av, data, i))
			return (0);
	}
	pp_print_2stack_full(data[0], data[1]);
	// if (isascending(data[0].stack, data[0].t_len))
	// {
	// 	printf("already ascending\n");
	// 	return (0);
	// }

	//ac < 2 -> write(1, "Empty list of arguments.\n", 25); If no argument is given checker stops and displays nothing.

	// ft_ra(&data[0]);
	// ft_ra(&data[0]);
	pp_print_2stack_full(data[0], data[1]);
	ft_pb(&data[0], &data[1]);
	// ft_ra(&data[0]);
	// ft_pb(&data[0], &data[1]);
	// ft_sa(&data[0]);
	// ft_ra(&data[0]);
	// ft_sa(&data[0]);
	// ft_rra(&data[0]);
	// ft_sa(&data[0]);
	// ft_pa(&data[0], &data[1]);
	// ft_pa(&data[0], &data[1]);
	// ft_pa(&data[0], &data[1]);
	// ft_pa(&data[0], &data[1]);
	// ft_pa(&data[0], &data[1]);
	pp_print_2stack_full(data[0], data[1]);

	// t_pp a;

	// while (total > 0)
	// {
	// 	stack0[total - 1] = ft_atoi(av[total]);
	// 	// a.pp[total - 1] = &stack[total - 1];
	// 	total--;
	// }
	// init_tpp(&a, ac - 1, stack0);
	// t_pp b;
	// init_tpp(&b, 0, NULL);

	// // printf("total num=%d\n", ac - 1);
	// while (total < ac - 1)
	// {
	// 	printf("stack[%d]=%d\n", total, stack[total]);
	// 	total++;
	// }
	// a.start = (total > 1) ? 1 : 0;

	// ft_tpp_print(&a,"A");
	// ft_tpp_print(&b,"B");

	// ft_tpp_sa(&a,"A");
	// ft_tpp_print(&a,"A");

	// printf("sizeof(int)=%lu\n",sizeof(int));=4
	// printf("sizeof(int*)=%lu\n",sizeof(int*));=8
	// printf("sizeof(size_t)=%lu\n",sizeof(size_t));=8
}

/*
sa: top a 2
sb: top b 2
ss=sa+sb
pa
pb
ra
rb
rr
rra
rrb
rrr
*/