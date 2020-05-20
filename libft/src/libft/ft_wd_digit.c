/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wd_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weilin <weilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:37:05 by weilin            #+#    #+#             */
/*   Updated: 2020/05/20 21:06:20 by weilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wd_digit(char const *s, char c)
{
	int		i;
	int		count;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	count = 0;
	while (len--)
		if (s[len] != c && s[len] != '-' && !ft_isdigit(s[len]))
			return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			count++;
	}
	return (count);
}
