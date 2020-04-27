/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:41:58 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/01 10:29:12 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcrev(char *str)
{
	int		len;
	int		j;
	char	swpstr;
	char	*chaine;

	len = 0;
	j = 0;
	if (!str)
		return (NULL);
	chaine = str;
	while (chaine[len] != '\0')
	{
		len++;
	}
	while (len > j)
	{
		len--;
		swpstr = chaine[len];
		chaine[len] = str[j];
		str[j] = swpstr;
		j++;
	}
	return (str);
}
