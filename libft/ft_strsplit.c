/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:36:45 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/01 10:39:17 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		wor;
	char	**res;

	if (!s)
		return (NULL);
	wor = 0;
	if (!(res = malloc(sizeof(char*) * (ft_mesure_wor(s, c) + 1))))
		return (NULL);
	while (wor < ft_mesure_wor(s, c))
	{
		if (!(res[wor] = malloc(sizeof(char) * ft_mesure_let(s, c, wor) + 1)))
			return (NULL);
		wor++;
	}
	return (ft_cut_words(s, c, res));
}
