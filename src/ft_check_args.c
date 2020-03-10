/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:12:08 by weilin            #+#    #+#             */
/*   Updated: 2020/03/10 19:44:53 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi_pw(const char *str, int *num)
{
	int i;
	long nbr;
	int sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		i++;
	while (i <= 11 && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	*num = (int)(nbr * sign);
	return (1);
}

int init_tpp(t_pp data[2], int total)
{
	// data[0].start = 0;
	data[0].t_len = total;
	data[0].len = total;

	// data[1].start = 0;
	data[1].t_len = total;
	data[1].len = 0;

	if (!(data[0].stack = (int *)malloc(sizeof(int) * (total))))
		return (0);
	if (!(data[1].stack = (int *)malloc(sizeof(int) * (total))))
	{
		free(data[0].stack);
		return (0);
	}
	return (1);
}

int ft_repeat(int *stk, int total)
{
	int i;
	int j;

	j = 0;
	while (j < total)
	{
		i = 0;
		while (i < total)
		{
			if (i != j && (stk[i] == stk[j]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void ft_strtab_free(char **av)
{
	int i;

	i = 0;
	while (av[i] != NULL)
	{
		free(av[i++]);
	}
	free(av);
}

int cleanall(t_pp data[2], char **av, int control)
{
	(control) ? ft_strdel(av) : 0;
	data[0].stack ? free(data[0].stack) : 0;
	data[1].stack ? free(data[1].stack) : 0;
	return (0);
}

int ft_check_args(int total, char **av, t_pp data[2], int i)
{
	int control;

	control = 0;
	if (total == 1)
	{
		total = ft_wd(av[1], ' ');
		av = ft_strsplit_wd(av[i--], ' ', total);
		control = 1;
	}
	if (!init_tpp(data, total))
		return (cleanall(data, av, control));
	while (total--)
	{
		if (!(ft_atoi_pw(av[i], &data[0].stack[total])))
			break;
		data[1].stack[total] = data[0].stack[total];
		i++;
	}
	if (total != -1 || ft_repeat(data[0].stack, data[0].len))
	{
		write(1, "Error\n", 6);
		return (cleanall(data, av, control)); //standard error : not INT, out of INT range, letters, duplicates
	}
	(control) ? ft_strtab_free(av) : 0;
	return (is_ascending(data[0].stack, data[0].t_len) ? 0 : 1); 
}