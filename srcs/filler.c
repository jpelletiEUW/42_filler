/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:29:32 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/02 14:26:16 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		init_rush(t_filler *flr)
{
	int i;
	int j;

	i = 0;
	while (i < flr->y_map)
	{
		j = 0;
		while (j < flr->x_map)
		{
			if (flr->heat[i][j] == 1 || flr->heat[i][j] == -1)
			{
				if (flr->x_enn == -1 && flr->y_enn == -1)
				{
					flr->x_enn = j;
					flr->y_enn = i;
				}
				else
					return (rush(flr, i, j));
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int		rush(t_filler *flr, int i, int j)
{
	int x;

	if (flr->x_diag == -1)
		flr->x_diag = j;
	if (flr->y_diag == -1)
		flr->y_diag = i;
	x = 0;
	while (x < flr->x_diag)
	{
		if (flr->heat[4][x] % 2 == 0)
			flr->heat[4][x] = 99;
		x++;
	}
	x = 4;
	while (x < flr->y_diag)
	{
		if (flr->heat[x][flr->x_diag] % 2 == 0)
			flr->heat[x][flr->x_diag] = 99;
		x++;
	}
	return (0);
}

int		clear_piece(t_filler *flr)
{
	int i;

	i = 0;
	while (i < flr->y_piece && flr->piece)
	{
		ft_strdel(&flr->piece[i]);
		i++;
	}
	if (flr->piece)
		free(flr->piece);
	flr->piece = NULL;
	return (0);
}

int		clear_leaks(t_filler *flr)
{
	int i;

	i = 0;
	while (i < flr->y_map && flr->map)
	{
		ft_strdel(&flr->map[i]);
		if (flr->heat)
		{
			free(flr->heat[i]);
			flr->heat[i] = NULL;
		}
		i++;
	}
	if (flr->map)
		free(flr->map);
	if (flr->heat)
		free(flr->heat);
	flr->map = NULL;
	flr->heat = NULL;
	clear_piece(flr);
	return (0);
}

int		main(void)
{
	t_filler	flr;

	if ((flr.player = player_parse()) == -1)
		return (0);
	flr.x_diag = -1;
	flr.y_diag = -1;
	flr.x_enn = -1;
	flr.y_enn = -1;
	while (1)
	{
		init_flr(&flr);
		if (read_map_piece(&flr) == -1)
			break ;
		if (attack_player(&flr) == -1)
			break ;
		clear_leaks(&flr);
	}
	ft_printf("0 0\n");
	clear_leaks(&flr);
	return (0);
}
