/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 03:10:27 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 09:54:35 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int i;
	t_pp data[3];

	if (ac > 1)
	{
		i = 1;
		if (!ft_check_args(ac - 1, av, data, i))
			return (0);
	}
	//
data[0].g=1;
data[1].g=1;
data[2].g=1;
	//
	ft_push_swap_backtrack(data);
	cleanall(data, av, 0);
	// system("leaks push_swap");
	return (0);
}