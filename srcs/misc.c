/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:40:04 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/01 14:17:47 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		init_flr(t_filler *flr)
{
	flr->cpt = 0;
	flr->x_piece = 0;
	flr->y_piece = 0;
	flr->x_map = 0;
	flr->y_map = 0;
	flr->x_pos = -1;
	flr->y_pos = -1;
	flr->x_off = 0;
	flr->y_off = 0;
	flr->x_resize = 0;
	flr->y_resize = 0;
	flr->heatscore = 0;
	flr->tmp_score = 0;
	flr->player = flr->player == 1 ? 1 : -1;
	flr->map = NULL;
	flr->piece = NULL;
	flr->heat = NULL;
	return (0);
}

int		ft_size_piece(t_filler *flr)
{
	int		i;
	int		ret;
	char	*str;

	i = 0;
	ret = 1;
	ret = get_next_line(0, &str);
	while ((str[i] < '1' || str[i] > '9') && str[i] && str[i] != '-')
		i++;
	flr->y_piece = ft_atoi(&str[i]);
	i += ft_intlen(flr->y_piece, 10);
	while ((str[i] < '1' || str[i] > '9') && str[i] && str[i] != '-')
		i++;
	flr->x_piece = ft_atoi(&str[i]);
	ft_strdel(&str);
	if (flr->x_piece <= 0 || flr->y_piece <= 0)
		return (-1);
	return (0);
}

int		parse_piece(t_filler *flr)
{
	int i;
	int j;

	j = 0;
	while (j < flr->y_piece)
	{
		i = 0;
		while (i < flr->x_piece)
		{
			if (flr->piece[j][i] != '.' && flr->piece[j][i] != '*')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int		set_piece(t_filler *flr)
{
	int		i;
	int		ret;
	char	*str;

	ret = 1;
	i = 0;
	while (i < flr->y_piece && (ret = get_next_line(0, &str)) > 0)
	{
		if ((int)ft_strlen(str) != flr->x_piece)
			return (-1);
		flr->piece[i] = ft_strdup(str);
		ft_strdel(&str);
		i++;
	}
	if (ret == -1 || parse_piece(flr) == -1)
		return (-1);
	return (0);
}

int		is_placeable(t_filler *flr, int k, int i, int j)
{
	int l;

	l = flr->x_off;
	while (l < flr->x_resize + flr->x_off)
	{
		if ((flr->piece[k][l] == '*'
				&& flr->heat[i + k - flr->y_off][j + l - flr->x_off]
				== -flr->player) || flr->cpt > 1)
			return (-1);
		if (flr->piece[k][l] == '*'
			&& flr->heat[i + k - flr->y_off][j + l - flr->x_off] == flr->player)
			flr->cpt++;
		if (flr->piece[k][l] == '*'
			&& flr->heat[i + k - flr->y_off][j + l - flr->x_off] > 1)
			flr->tmp_score += flr->heat[i + k - flr->y_off][j + l - flr->x_off];
		l++;
	}
	return (0);
}
