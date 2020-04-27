/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:25:41 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/15 13:26:45 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *d, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if ((!d[0] && !s[0]) || s == d)
		return ((char*)(s));
	while (s[i] && i < len)
	{
		j = -1;
		while (((s[i + j] == d[j] || !d[j]) && (i + j) < len) || j + 1 == 0)
		{
			j++;
			if (!d[j])
				return ((char*)(s + i));
		}
		i++;
	}
	return (NULL);
}
