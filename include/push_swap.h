/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:32:53 by weilin            #+#    #+#             */
/*   Updated: 2020/03/11 02:58:35 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// del
# include <stdio.h> // del
// del

# include "libft.h"
# include <limits.h>

typedef	struct	s_pp
{
	int			start;
	size_t		len;
	size_t		t_len;
	int			*stack;
}				t_pp;


int		ft_check_args(int total, char **av, t_pp *data, int i);

/*
** functions for swapping: sa, sb, ss, pa, pb
** Files(s): swap.c push.c
*/
void	ft_ss(t_pp *data);
int		ft_push(t_pp *d_orig, t_pp *d_dest);
void	ft_pa(t_pp *data);
void	ft_pb(t_pp *data);
int		ft_rotate(t_pp *data);
void	ft_rr(t_pp *data);
void	ft_ra(t_pp *data);
void	ft_rb(t_pp *data);
int		ft_rev_rotate(t_pp *data);
void 	ft_rra(t_pp *data);
void 	ft_rrb(t_pp *data);
void	ft_rrr(t_pp *data);
int		ft_swap(t_pp *data);
void	ft_sa(t_pp *data);
void	ft_sb(t_pp *data);
int		ft_do_actions(char *s,const char **all, t_pp *data);

int 	cleanall(t_pp *data, char **av, int control);
int		ft_atoi_pw(const char *str, int *num);
int		is_ascending(int *stack, int total);
void	ft_init_tab_all(const char *all[11]);
void	ft_strtab_free(char **av);
int		init_tpp(t_pp *data, int total);
int		get_average(t_pp *data);
int		get_max(t_pp *data);
int		get_min(t_pp *data);
int		get_max_min(t_pp *data, int control);

/*
** functions for printing table of *int
** File(s): tools_print.c
*/
void	pp_print_addr(t_pp data);
void	pp_print_2stack(t_pp data1, t_pp data2);
void	pp_print_2stack_full(t_pp data1, t_pp data2);
void	pp_print_1stack_full(t_pp data);
void	pp_print_stack(t_pp data);
# endif
