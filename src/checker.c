/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:34:57 by weilin            #+#    #+#             */
/*   Updated: 2020/03/10 20:37:10 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_pw(int j, t_pp dt[2])
{
	(j == 0) ? ft_sa(&dt[0]) : 0;
	(j == 1) ? ft_sb(&dt[1]) : 0;
	(j == 2) ? ft_ss(&dt[0], &dt[1]) : 0;
	(j == 3) ? ft_pa(&dt[0], &dt[1]) : 0;
	(j == 4) ? ft_pb(&dt[0], &dt[1]) : 0;
	(j == 5) ? ft_ra(&dt[0]) : 0;
	(j == 6) ? ft_rb(&dt[1]) : 0;
	(j == 7) ? ft_rr(&dt[0], &dt[1]) : 0;
	(j == 8) ? ft_rra(&dt[0]) : 0;
	(j == 9) ? ft_rrb(&dt[1]) : 0;
	(j == 10) ? ft_rrr(&dt[0], &dt[1]) : 0;
}

int		ft_do_actions(char *s, char **all, t_pp dt[2])
{
	size_t	i;
	int		j;
	size_t	s_len;

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
				break ;
			}
			j++;
		}
		if (j == 11)
			return (0);
	}
	return ((i == s_len) ? 1 : 0);
}

int		ft_islegal(char *s, char **all)
{
	size_t	i;
	int		j;
	size_t	s_len;

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
				break ;
			}
			j++;
		}
		if (j == 11)
			return (0);
	}
	return ((i == s_len) ? 1 : 0);
}

char	*ft_read(char *actions, char **all)
{
	char	buff[256];
	int		total_size;
	int		size_count;
	char	*tmp;

	total_size = 0;
	while ((size_count = read(0, buff, 255)) > 0)
	{
		total_size = total_size + size_count;
		tmp = actions;
		if (!ft_islegal(buff, all))
		{
			(actions) ? free(actions) : 0;
			return (NULL);
		}
		buff[size_count] = '\0';
		if (!(actions = (char *)malloc(sizeof(char) * (total_size + 1))))
			return (0);
		*actions = '\0';
		(tmp) ? ft_strcpy(actions, tmp) : 0;
		ft_strcat(actions, buff);
		(tmp) ? free(tmp) : 0;
	}
	return (actions);
}

int		main(int ac, char **av)
{
	char	*actions;
	char	**all;
	t_pp	dt[2];
	int		i;

	actions = NULL;
	i = 1;
	if (!ft_check_args(ac - 1, av, dt, i) || dt[0].t_len == 0)
		return (0);
	all = ft_init_tab_all();
	if ((actions = ft_read(actions, all)) && ft_do_actions(actions, all, dt))
	{
		(is_ascending(dt[0].stack, dt[0].t_len)) ?
			write(1, "OK\n", 3) : write(1, "KO\n", 3);
	}
	else
		write(1, "Error\n", 6);
	(actions) ? free(actions) : 0;
	(all) ? ft_strdel(all) : 0;
	// system("leaks checker");
	return (0);
}
