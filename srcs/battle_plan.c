/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:10:33 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/01 10:06:00 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		assign_territory(t_filler *flr, int i, int j)
{
	if (flr->map[i][j] == '.')
		flr->heat[i][j] = 0;
	else if (flr->map[i][j] == 'O' || flr->map[i][j] == 'o')
		flr->heat[i][j] = 1;
	else if (flr->map[i][j] == 'X' || flr->map[i][j] == 'x')
		flr->heat[i][j] = -1;
	return (0);
}

int		check_pos(t_filler *flr)
{
	int i;
	int j;

	i = 0;
	if (!(flr->heat = malloc(sizeof(int*) * (flr->y_map))))
		return (-1);
	while (i < flr->y_map)
	{
		if (!(flr->heat[i] = malloc(sizeof(int) * (flr->x_map))))
			return (-1);
		ft_bzero(flr->heat[i], flr->x_map);
		j = 0;
		while (j < flr->x_map)
		{
			assign_territory(flr, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int		create_heatmap(t_filler *flr)
{
	int	i;
	int	j;
	int use;

	use = 0;
	while (use < 3)
	{
		i = 0;
		while (i < flr->y_map)
		{
			j = 0;
			while (j < flr->x_map)
			{
				if (((flr->heat[i][j] == use * 5
							|| flr->heat[i][j] == use * 25) && use != 0)
							|| (use == 0 && flr->heat[i][j] == -flr->player))
					set_heatmap(flr, i, j, use);
				j++;
			}
			i++;
		}
		use++;
	}
	return (0);
}

int		attack_player(t_filler *flr)
{
	if (check_pos(flr) == -1
		|| create_heatmap(flr) == -1
		|| check_attack(flr) == -1)
		return (-1);
	return (0);
}
