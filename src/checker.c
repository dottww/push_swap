/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:34:57 by weilin            #+#    #+#             */
/*   Updated: 2020/03/09 14:48:04 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_actions(char *buf, const char **actions)
{
	int i;

	i = 0;
	while (actions[i])
	{
		if (ft_strcmp(buf, actions[i]) == 0)
			break;
		i++;
	}
	return ((i == 11) ? 0 : 1);
}
char *ft_strstr(const char *haystack, const char *needle)
{
	int i;
	// int j = 0;

	if (*needle == '\0')
		return ((char *)haystack);
	// while (*s)
	// {
	// 	if (*s == '\n')
	// 		break;
	// 	s++;
	// }
	while (*haystack)
	{
		if (*haystack != *needle)
			haystack++;
		else
		{
			i = 1;
			while (haystack[i] && needle[i] && haystack[i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
			else
				haystack++;
		}
	}
	return (NULL);
}

int ft_read_actions(const char *actions)
{
	char *buf;
	int stat_arg;
	long i;

	i = 0;
	// while (actions)
	// {
	// 	if(ft_strstr(actions,"sa\n") || strstr(actions,"sa\n")
	// 		ft_strncmp(actions[i++],"sa\n", 3);
	// 	else if(actions[i] == 'r')
	// 	else if(actions[i] == 'p')
	// }
	stat_arg = 1;
	if (!(buf = ft_memalloc(4)))
		return (0);
	while (stat_arg == 1)
	{
		read(0, buf, 4);
		stat_arg = ft_check_actions(buf, &actions);
		ft_bzero(buf, 4);
	}
	return (stat_arg);
}
void ft_tab_alloc(const char ***str)
{
	int i;

	i = -1;
	if (!((*str) = (const char **)malloc(sizeof(const char *) * 12)))
		return;
	while (++i <= 7)
	{
		if (!((*str)[i] = (const char *)malloc(sizeof(const char *) * 4)))
		{
			while (--i >= 0)
				free((void *)(*str)[i]);
			free(*str);
			return;
		}
	}
	while (++i <= 10)
	{
		if (!((*str)[i] = (const char *)malloc(sizeof(const char *) * 5)))
		{
			while (--i >= 0)
				free((void *)(*str)[i]);
			free(*str);
			return;
		}
	}
	(*str)[11] = NULL;
}

const char **ft_init_tab_actions(void)
{
	const char **actions;

	ft_tab_alloc(&actions);
	actions[0] = "sa\n";
	actions[1] = "sb\n";
	actions[2] = "ss\n";
	actions[3] = "pa\n";
	actions[4] = "pb\n";
	actions[5] = "ra\n";
	actions[6] = "rb\n";
	actions[7] = "rr\n";
	actions[8] = "rra\n";
	actions[9] = "rrb\n";
	actions[10] = "rrr\n";
	return (actions);
}

int ft_islegal(char *s)
{
	while (*s)
	{
		if (*s == 's' || *s == 'p' || *s == 'r' ||
			*s == 'a' || *s == 'b' || *s == '\n')
			s++;
		else
			return (0);
	}
	return (1);
}

char *ft_read(void)
{
	char buff[256];
	int total_size;
	int size_count;
	char *tmp;
	char *result;

	result = NULL;
	total_size = 0;
	while ((size_count = read(0, buff, 255)) > 0)
	{
		total_size = total_size + size_count;
		tmp = result;
		if (!ft_islegal(buff))
		{
			ft_putstr("READ ERROR\n");
			(tmp) ? free(tmp) : 0;
			break;
		}
		buff[size_count] = '\0';
		if (!(result = (char *)malloc(sizeof(char) * (total_size + 1))))
			return (0);
		*result = '\0';
		(tmp) ? ft_strcpy(result, tmp) : 0;
		ft_strcat(result, buff);
		(tmp) ? free(tmp) : 0;
	}
	return ((result) ? result : NULL);
}

int main(int ac, char **av)
{
	char *actions;
	t_pp data[2];
	int i;

	i = 1;
	if (!ft_check_args(ac - 1, av, data, i))
		return (0);
	if ((actions = ft_read()) != NULL)
	{
		ft_putstr("CHECKER READ IS LEGAL=\n|\n");
		ft_putstr(actions);
		ft_putstr("|\n");
		if ((actions = ft_read()) && ft_read_actions(actions))
		{
			(is_ascending(data[0].stack, data[0].t_len))
				? write(1, "OK\n", 3)
				: write(1, "KO\n", 3);
		}
		else
			write(1, "Error\n", 6);
	}
	(actions) ? free(actions) : 0;
	return (0);
}