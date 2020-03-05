/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:30:23 by weilin            #+#    #+#             */
/*   Updated: 2020/03/05 20:22:30 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**mx;
	int		count;
	int		i;
	int		j;
	int		end;

	if (!s || !c || !(mx = (char**)malloc(sizeof(char*) * (ft_wd(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	count = -1;
	while (s[i] && count++ < ft_wd(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
			j = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (end != j)
			mx[count] = ft_strdup_sec(s, j, end);
	}
	mx[ft_wd(s, c)] = 0;
	return (mx);
}
