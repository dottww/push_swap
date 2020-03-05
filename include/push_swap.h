/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:32:53 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 22:29:27 by weilin           ###   ########.fr       */
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

int		ft_check_args(int ac, char **av, t_pp data[2], int i);
/*
** functions for swapping: sa, sb, ss, pa, pb
** Files(s): swap.c push.c
*/
void	special_swap(t_pp *data1, t_pp *data2, int i, int j);
void	ft_swap_ss(t_pp *data1, t_pp *data2);
int		ft_push(t_pp *d_orig, t_pp *d_dest);
void	ft_pa(t_pp *a, t_pp *b);
void	ft_pb(t_pp *a, t_pp *b);
int		ft_rotate(t_pp *data);
void	ft_ra(t_pp *a);
void	ft_rb(t_pp *b);
int		ft_rev_rotate(t_pp *data);
void 	ft_rra(t_pp *a);
void 	ft_rrb(t_pp *b);
int		ft_swap(t_pp *data);
void	ft_sa(t_pp *a);
void	ft_sb(t_pp *b);
int 	cleanall(t_pp data[2], char **av, int control);
int		ft_atoi_pw(const char *str, int *num);
/*
** functions for printing table of *int
** File(s): tools_print.c
*/
void	pp_print_addr(t_pp data);
void	pp_print_2stack_full(t_pp data1, t_pp data2);
void	pp_print_1stack_full(t_pp data);
void	pp_print_stack(t_pp data);
# endif
