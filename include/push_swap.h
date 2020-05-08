/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:32:53 by weilin            #+#    #+#             */
/*   Updated: 2020/05/08 14:03:04 by weilin           ###   ########.fr       */
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
	int			g;
	// int			start;
	int			len;
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
int		pw_is_sorted(int *stack, int total);
void	ft_init_tab_all(const char *all[11]);
void	ft_strtab_free(char **av);
int		init_tpp(t_pp *data, int total);
int		dup_tpp(t_pp *ori, t_pp *dst, size_t total);
int		get_average(t_pp *data);
int		rank_dif_1(t_pp *a, int a_i, t_pp *b, int b_j);
int		i_max(t_pp *data);
int		i_min(t_pp *data);
int		get_max_min(t_pp *data, int control);
void	ft_print_int_tables(int *tab, int size);
int		median_rank(t_pp *data);
int		quick_sort_once(int *a, int low, int high, t_pp *data);
int qq2(int *a, int low, int high, t_pp *data);
void	quick_sort(int *a, int low, int high, t_pp *data);
int	pw_avg_limit(t_pp *a, int limit);
void ft_push_swap(t_pp *a, t_pp *b);
void pw_5(t_pp *data, int mid);
void pw_get_max_of_b_to_a(t_pp *a, t_pp *b);
void pw_smart_rotate(t_pp *a, t_pp *b);
void ft_push_swap_backtrack(t_pp *data);
void pw_backtrack(t_pp *a, t_pp *b, int limit);
int pw_i_next_to_min(t_pp *a, int limit);
void pw_split_to_a(t_pp *a, t_pp *b, int avg, int size);
void pw_to_b(t_pp *data, int avg);
void pw_backtrack_split(t_pp *a, t_pp *b, int limit, int ctl);
// int quick_sort_once(int *a, int low, int high);
// void quick_sort(int *a, int low, int high);
/*
** functions for printing table of *int
** File(s): tools_print.c
*/
void	pp_print_addr(t_pp data);
void	pp_print_2stack(t_pp data1, t_pp data2, t_pp data3);
void pp_print_3stack(t_pp data1, t_pp data2, t_pp data3);
void	pp_print_2stack_full(t_pp data1, t_pp data2);
void	pp_print_1stack_full(t_pp data);
void	pp_print_stack(t_pp data);



# endif
