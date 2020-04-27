/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_battle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:49:48 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/02 09:52:13 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		init_diag(t_filler *flr, int i, int j)
{
	int x;
	int val;

	flr->x_diag = flr->x_diag == -1 ? j : flr->x_diag;
	flr->y_diag = flr->y_diag == -1 ? i : flr->y_diag;
	x = 0;
	val = (flr->x_map + flr->y_map) / 2 - ft_abs(flr->y_diag - flr->y_map / 2);
	val = val >= 2 ? val : 2;
	while (x < flr->x_map)
	{
		if (flr->heat[flr->y_diag][x] % 2 == 0)
			flr->heat[flr->y_diag][x] = val;
		x++;
	}
	val = (flr->x_map + flr->y_map) / 2 - ft_abs(flr->x_diag - flr->x_map / 2);
	val = val >= 2 ? val : 2;
	x = 0;
	while (x < flr->y_map)
	{
		if (flr->heat[x][flr->x_diag] % 2 == 0)
			flr->heat[x][flr->x_diag] = val;
		x++;
	}
	return (0);
}

int		diag_heatmap(t_filler *flr)
{
	int i;
	int j;

	i = 0;
	while (i < flr->y_map)
	{
		j = 0;
		while (j < flr->x_map)
		{
			if (flr->heat[i][j] == flr->player)
			{
				init_diag(flr, i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int		valid_pos(t_filler *flr, int i, int j)
{
	int k;

	flr->cpt = 0;
	k = flr->y_off;
	while (k < flr->y_resize + flr->y_off)
	{
		if (is_placeable(flr, k, i, j) == -1)
			return (-1);
		k++;
	}
	if (flr->cpt != 1)
		return (-1);
	return (0);
}

int		place_piece(t_filler *flr, int i, int j)
{
	i = 0;
	while (i <= flr->y_map - flr->y_resize)
	{
		j = 0;
		while (j <= flr->x_map - flr->x_resize)
		{
			flr->tmp_score = 1;
			if (valid_pos(flr, i, j) == 0 && flr->tmp_score > flr->heatscore)
			{
				flr->x_pos = j;
				flr->y_pos = i;
				flr->heatscore = flr->tmp_score;
			}
			j++;
		}
		i++;
	}
	if (flr->x_pos == -1 && flr->y_pos == -1)
		return (-1);
	ft_printf("%d %d\n", flr->y_pos - flr->y_off,
				flr->x_pos - flr->x_off);
	return (0);
}

int		check_attack(t_filler *flr)
{
	if ((flr->x_off = x_offset_piece(flr)) == -1
		|| (flr->y_off = y_offset_piece(flr)) == -1
		|| (flr->y_resize = y_resize_piece(flr)) == -1
		|| (flr->x_resize = x_resize_piece(flr)) == -1)
		return (-1);
	if (flr->x_map < 20 && flr->y_map < 20 && flr->player == -1)
	{
		if (flr->x_diag == -1 && flr->y_diag == -1)
			init_rush(flr);
		else
			rush(flr, flr->y_diag, flr->x_diag);
	}
	else
	{
		if (flr->x_diag == -1 && flr->y_diag == -1)
			diag_heatmap(flr);
		else
			init_diag(flr, flr->y_diag, flr->x_diag);
	}
	if (place_piece(flr, 0, 0) == -1)
		return (-1);
	return (0);
}
