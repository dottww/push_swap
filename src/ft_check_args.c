/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:12:08 by weilin            #+#    #+#             */
/*   Updated: 2020/05/17 23:19:41 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pw_sorted(int *stack, int total)
{
	int	i;
	int	isacend;

	i = 1;
	isacend = 1;
	while (i < total)
	{
		if ((stack[i] > stack[i - 1]))
		{
			isacend = 0;
			break ;
		}
		i++;
	}
	return (isacend);
}

int	ft_atoi_pw(const char *str, int *num)
{
	int		i;
	long	nbr;
	int		sign;

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

int	ft_repeat(int *stk, int total)
{
	int	i;
	int	j;

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

int	ft_check_args(int total, char **av, t_pp *data, int i)
{
	int	control;

	control = 0;
	if (total == 1)
	{
		total = ft_wd(av[1], ' ');
		av = ft_strsplit_wd(av[i--], ' ', total);
		control = 1;
	}
	if (total !=0 && !init_tpp(data, total))
		return (cleanall(data, av, control));
	while (total--)
	{
		if (!(ft_atoi_pw(av[i], &data[0].stack[total])))
			break ;
		data[1].stack[total] = data[0].stack[total];
		i++;
	}
	if (total != -1 || ft_repeat(data[0].stack, data[0].len))
	{
		ft_putstr("Error\n");
		return (cleanall(data, av, control));
	}
	(control) ? ft_strtab_free(av) : 0;
	return (pw_sorted(data[0].stack, data[0].t_len) ? 2 : 1);
}
