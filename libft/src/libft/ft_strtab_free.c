/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:58:31 by weilin            #+#    #+#             */
/*   Updated: 2020/05/20 18:13:51 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtab_free(char **av)
{
	// ft_printf("avtable\n");ft_print_words_tables(av);
	int i;

	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		av[i] = NULL;
		// ft_printf("i=%d\n",i);
		i++;
	}
	free(av);
	av = NULL;
}
