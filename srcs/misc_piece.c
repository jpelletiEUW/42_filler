/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:29:25 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/01 10:05:53 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		y_offset_piece(t_filler *flr)
{
	int i;
	int j;

	i = 0;
	while (i < flr->y_piece)
	{
		j = 0;
		while (j < flr->x_piece)
		{
			if (flr->piece[i][j] == '*')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int		x_offset_piece(t_filler *flr)
{
	int i;
	int j;

	j = 0;
	while (j < flr->x_piece)
	{
		i = 0;
		while (i < flr->y_piece)
		{
			if (flr->piece[i][j] == '*')
				return (j);
			i++;
		}
		j++;
	}
	return (-1);
}

int		y_resize_piece(t_filler *flr)
{
	int i;
	int j;

	i = flr->y_piece - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < flr->x_piece)
		{
			if (flr->piece[i][j] == '*')
				return (i + 1 - flr->y_off);
			j++;
		}
		i--;
	}
	return (-1);
}

int		x_resize_piece(t_filler *flr)
{
	int i;
	int j;

	j = flr->x_piece - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < flr->y_piece)
		{
			if (flr->piece[i][j] == '*')
				return (j + 1 - flr->x_off);
			i++;
		}
		j--;
	}
	return (-1);
}
