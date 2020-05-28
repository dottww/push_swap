/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:12:08 by weilin            #+#    #+#             */
/*   Updated: 2020/05/28 18:24:03 by weilin           ###   ########.fr       */
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
	if ((nbr > 2147483647 && sign == 1) || (nbr > 2147483648 && sign == -1)
		|| str[i] != '\0')
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
	init_tpp_stack(data);
	if (total == 1 && (total = ft_wd_num(av[1], ' ')))
		if ((av = ft_strsplit_wd(av[i--], ' ', total)) != NULL)
			control = 1;
	if (init_tpp(data, total))
	{
		while (total--)
		{
			if (!(ft_atoi_pw(av[i], &data[0].stack[total])))
				break ;
			data[1].stack[total] = data[0].stack[total];
			i++;
		}
	}
	(control) ? ft_strtab_free(av) : 0;
	if (total != -1 || ft_repeat(data[0].stack, data[0].len))
		return (0);
	else
		return (1);
}
