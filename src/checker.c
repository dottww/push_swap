/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:34:57 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 17:57:44 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_actions(char *buf, const char **actions)
{
	int		i;

	i = 0;
	while (actions[i])
	{
		if (ft_strcmp(buf, actions[i]) == 0)
			break ;
		i++;
	}	
	return ((i == 11) ? 0 : 1);
}

int		ft_read_actions(const char **actions)
{
	char	*buf;
	int		stat_arg;

	stat_arg = 1;
	if (!(buf = ft_memalloc(4)))
		return (0);
	while (stat_arg == 1)
	{
		read(0, buf, 4);
		stat_arg = ft_check_actions(buf, actions);
		ft_bzero(buf, 4);
	}
	return (stat_arg);
}

int			main(int ac, char **av)
{
	const char	**actions;
	int		*stack0;
	t_pp	data[2];
	int control;

	if (!ft_check_args(ac - 1, av, stack0, &data))
		return (0);
	actions = ft_init_tab_actions();
	ft_read_actions(actions) ? write(1, "OK\n", 3) : write(1, "KO\n", 3);
	// call_ft_pw;
	// if(ft_isacend)
	// 	return(OK);
	return (0);
}