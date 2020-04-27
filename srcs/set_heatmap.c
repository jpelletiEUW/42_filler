/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heatmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:12:28 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/01 10:05:56 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		first_use(t_filler *flr, int i, int j)
{
	if (i + 1 < flr->y_map && flr->heat[i + 1][j] == 0)
		flr->heat[i + 1][j] = (i + 2 == flr->y_map || j + 1 == flr->x_map
		|| j - 1 == -1) ? 25 : 5;
	if (i - 1 >= 0 && flr->heat[i - 1][j] == 0)
		flr->heat[i - 1][j] = (i - 2 == -1 || j + 1 == flr->x_map
		|| j - 1 == -1) ? 25 : 5;
	if (j + 1 < flr->x_map && flr->heat[i][j + 1] == 0)
		flr->heat[i][j + 1] = (j + 2 == flr->x_map || i + 1 == flr->y_map
		|| i - 1 == -1) ? 25 : 5;
	if (j - 1 >= 0 && flr->heat[i][j - 1] == 0)
		flr->heat[i][j - 1] = (j - 2 == -1 || i + 1 == flr->y_map
		|| i - 1 == -1) ? 25 : 5;
	return (0);
}

int		second_use(t_filler *flr, int i, int j)
{
	if (i + 1 < flr->y_map && flr->heat[i + 1][j] == 0)
		flr->heat[i + 1][j] = (i + 2 == flr->y_map || j + 1 == flr->x_map
		|| j - 1 == -1) ? 50 : 10;
	if (i - 1 >= 0 && flr->heat[i - 1][j] == 0)
		flr->heat[i - 1][j] = (i - 2 == -1 || j + 1 == flr->x_map
		|| j - 1 == -1) ? 50 : 10;
	if (j + 1 < flr->x_map && flr->heat[i][j + 1] == 0)
		flr->heat[i][j + 1] = (j + 2 == flr->x_map || i + 1 == flr->y_map
		|| i - 1 == -1) ? 50 : 10;
	if (j - 1 >= 0 && flr->heat[i][j - 1] == 0)
		flr->heat[i][j - 1] = (j - 2 == -1 || i + 1 == flr->y_map
		|| i - 1 == -1) ? 50 : 10;
	return (0);
}

int		third_use(t_filler *flr, int i, int j)
{
	if (i + 1 < flr->y_map && flr->heat[i + 1][j] == 0)
		flr->heat[i + 1][j] = (i + 2 == flr->y_map || j + 1 == flr->x_map
		|| j - 1 == -1) ? 75 : 15;
	if (i - 1 >= 0 && flr->heat[i - 1][j] == 0)
		flr->heat[i - 1][j] = (i - 2 == -1 || j + 1 == flr->x_map
		|| j - 1 == -1) ? 75 : 15;
	if (j + 1 < flr->x_map && flr->heat[i][j + 1] == 0)
		flr->heat[i][j + 1] = (j + 2 == flr->x_map || i + 1 == flr->y_map
		|| i - 1 == -1) ? 75 : 15;
	if (j - 1 >= 0 && flr->heat[i][j - 1] == 0)
		flr->heat[i][j - 1] = (j - 2 == -1 || i + 1 == flr->y_map
		|| i - 1 == -1) ? 75 : 15;
	return (0);
}

int		set_heatmap(t_filler *flr, int i, int j, int use)
{
	if (use == 0)
		first_use(flr, i, j);
	else if (use == 1)
		second_use(flr, i, j);
	else if (use == 2)
		third_use(flr, i, j);
	return (0);
}
