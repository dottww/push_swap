/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:25:59 by weilin            #+#    #+#             */
/*   Updated: 2020/05/20 19:02:07 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	**ft_init_tab_all(char **all)
{
	all = (char **)malloc(sizeof(char*) * 12);
	all[0] = ft_strdup("sa\n");
	all[1] = ft_strdup("sb\n");
	all[2] = ft_strdup("ss\n");
	all[3] = ft_strdup("pa\n");
	all[4] = ft_strdup("pb\n");
	all[5] = ft_strdup("ra\n");
	all[6] = ft_strdup("rb\n");
	all[7] = ft_strdup("rr\n");
	all[8] = ft_strdup("rra\n");
	all[9] = ft_strdup("rrb\n");
	all[10] = ft_strdup("rrr\n");
	all[11] = 0;
	return (all);
}

int		dup_tpp(t_pp *ori, t_pp *dst, size_t total)
{
	if (total == 0)
		return (0);
	dst->t_len = total;
	dst->len = total;
	if (!(dst->stack = (int *)malloc(sizeof(int) * (total + 1))))
		return (0);
	dst->m = 1;
	while (total--)
		dst->stack[total] = ori->stack[total];
	return (1);
}

int		init_tpp(t_pp *data, int total)
{
	data[0].m = 0;
	data[1].m = 0;
	data[2].m = 0;
	if (total == 0)
		return (0);
	data[0].t_len = total;
	data[0].len = total;
	data[1].t_len = total;
	data[1].len = 0;
	if (!(data[0].stack = (int *)malloc(sizeof(int) * (total))))
		return (0);
	data[0].m = 1;
	if (!(data[1].stack = (int *)malloc(sizeof(int) * (total))))
	{
		free(data[0].stack);
		return (0);
	}
	data[1].m = 1;
	return (1);
}

int		cleanall(t_pp *data, char **av, int control)
{
	(control) ? ft_strtab_free(av) : 0;
	data[0].m ? free(data[0].stack) : 0;
	data[1].m ? free(data[1].stack) : 0;
	data[2].m ? free(data[2].stack) : 0;
	return (0);
}
