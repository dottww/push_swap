/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:34:57 by weilin            #+#    #+#             */
/*   Updated: 2020/05/09 17:56:30 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_do_pw(int j, t_pp *data)
{
	(j == 0) ? ft_sa(data, 0) : 0;
	(j == 1) ? ft_sb(data, 0) : 0;
	(j == 2) ? ft_ss(data, 0) : 0;
	(j == 3) ? ft_pa(data, 0) : 0;
	(j == 4) ? ft_pb(data, 0) : 0;
	(j == 5) ? ft_ra(data, 0) : 0;
	(j == 6) ? ft_rb(data, 0) : 0;
	(j == 7) ? ft_rr(data, 0) : 0;
	(j == 8) ? ft_rra(data, 0) : 0;
	(j == 9) ? ft_rrb(data, 0) : 0;
	(j == 10) ? ft_rrr(data, 0) : 0;
}

int ft_do_actions(char *s, const char **all, t_pp *dt)
{
	size_t i;
	int j;
	size_t s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i != s_len)
	{
		j = 0;
		while (j < 11)
		{
			if (ft_strnequ(s + i, all[j], ft_strlen(all[j])))
			{
				ft_do_pw(j, dt);
				i += ft_strlen(all[j]);
				break;
			}
			j++;
		}
		if (j == 11)
			return (0);
	}
	return ((i == s_len) ? 1 : 0);
}

int ft_islegal(char *s, const char *all[11])
{
	size_t i;
	int j;
	size_t s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i != s_len)
	{
		j = 0;
		while (j < 11)
		{
			if (ft_strnequ(s + i, all[j], ft_strlen(all[j])))
			{
				i += ft_strlen(all[j]);
				break;
			}
			j++;
		}
		if (j == 11)
			return (0);
	}
	return ((i == s_len) ? 1 : 0);
}

char *ft_read(char *actions, const char **all)
{
	char *buff;
	int size_count;

	if (read(0, NULL, 0) < 0 || !(buff = ft_strnew(256)))
		return (NULL);
	while ((size_count = read(0, buff, 255)) >= 0)
	{
		buff[size_count] = '\0';
		actions = (actions ? ft_strreset(actions, ft_strjoin(actions, buff))
						   : ft_strdup(buff));
		ft_strclr(buff);
		if (!size_count)
			break;
	}
	buff ? free(buff) : 0;
	return (ft_islegal(actions, all) ? actions : NULL);
}

int main(int ac, char **av)
{
	int i;
	char *actions;
	const char *all[11];
	t_pp dt[2];

	actions = NULL;
	i = 1;
	if (!ft_check_args(ac - 1, av, dt, i) || dt[0].t_len == 0)
		return (0);
	ft_init_tab_all(all);
	if ((actions = ft_read(actions, all)))
	{
		ft_do_actions(actions, all, dt);
		(pw_is_sorted(dt[0].stack, dt[0].t_len)) ? ft_putstr("OK\n")
												 : ft_putstr("KO\n");
	}
	else
		ft_putstr("Error\n");
	(actions) ? free(actions) : 0;
	// system("leaks checker");
	return (0);
}
