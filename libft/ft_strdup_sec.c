/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:18:51 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 20:21:29 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_sec(char const *s, int j, int end)
{
	int		i;
	char	*dup;

	if (!s || !(dup = (char*)malloc(sizeof(char) * (end - j + 1))))
		return (NULL);
	i = 0;
	while (s[j] && j < end)
	{
		dup[i] = s[j];
		i++;
		j++;
	}
	dup[i] = 0;
	return (dup);
}
