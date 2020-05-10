/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:14:27 by weilin            #+#    #+#             */
/*   Updated: 2020/05/10 02:23:42 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_int_tables(int *tab, int size)
{
	int i;

	i = 0;
	ft_putstr("tab[");
	while (i < size)
	{
		ft_putnbr(i);
		ft_putstr("=");
		ft_putnbr(tab[i]);
		i++;
		(i != size) ? ft_putstr(", ") : 0;
	}
}

void	pp_print_3stack(t_pp data1, t_pp data2, t_pp data3)
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