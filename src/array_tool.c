/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:48:37 by weilin            #+#    #+#             */
/*   Updated: 2020/03/09 14:48:45 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_ascending(int *stack, int total)
{
	int i;
	int isacend;

	i = 1;
	isacend = 1;
	while (i < total)
	{
		if ((stack[i] > stack[i - 1]))
		{
			isacend = 0;
			break;
		}
		i++;
	}
	return (isacend);
}