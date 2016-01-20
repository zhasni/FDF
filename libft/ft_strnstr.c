/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:40:37 by zhasni            #+#    #+#             */
/*   Updated: 2014/11/23 14:16:45 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	while (s1[i] && i < n)
	{
		j = 0;
		while ((s1[i] == s2[j]) && i < n)
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return ((char *)s1 + (i - j));
		}
		if (s1[i] == s2[0])
			i--;
		i++;
	}
	return (NULL);
}
