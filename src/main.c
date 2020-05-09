/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 03:10:27 by weilin            #+#    #+#             */
/*   Updated: 2020/05/10 01:11:44 by weilin           ###   ########.fr       */
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
	ft_push_swap_main(data);
	cleanall(data, av, 0);
	return (0);
}