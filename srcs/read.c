/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:38:47 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/02 14:24:55 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		player_parse(void)
{
	int		ret;
	char	*str;

	if ((ret = get_next_line(0, &str)) <= 0)
		return (-1);
	ret = ft_atoi(str + 10);
	ft_strdel(&str);
	return (ret != 1 && ret != 2 ? -1 : ret);
}

int		parse_map(t_filler *flr)
{
	int i;
	int j;

	j = 0;
	while (j < flr->y_map)
	{
		i = 0;
		while (i < flr->x_map)
		{
			if (flr->map[j][i] != '.' && flr->map[j][i] != 'o'
				&& flr->map[j][i] != 'O' && flr->map[j][i] != 'x'
				&& flr->map[j][i] != 'X')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int		ft_size_map(t_filler *flr)
{
	int		i;
	int		ret;
	char	*str;

	i = 0;
	ret = 1;
	if ((ret = get_next_line(0, &str)) <= 0)
		return (-1);
	while ((str[i] < '1' || str[i] > '9') && str[i] && str[i] != '-')
		i++;
	flr->y_map = ft_atoi(&str[i]);
	i += ft_intlen(flr->y_map, 10);
	while ((str[i] < '1' || str[i] > '9') && str[i] && str[i] != '-')
		i++;
	flr->x_map = ft_atoi(&str[i]);
	ft_strdel(&str);
	if (flr->x_map <= 0 || flr->y_map <= 0)
		return (-1);
	return (0);
}

int		set_map(t_filler *flr)
{
	int		i;
	int		j;
	int		ret;
	char	*str;

	ret = 1;
	i = 0;
	while (i < flr->y_map && (ret = get_next_line(0, &str)) > 0)
	{
		j = 0;
		while ((str[j] >= '0' && str[j] <= '9') || str[j] == ' ')
			j++;
		if ((int)ft_strlen(str + j) != flr->x_map
			|| (!(flr->map[i] = ft_strsub(str, j, flr->x_map))))
		{
			ft_strdel(&str);
			return (-1);
		}
		ft_strdel(&str);
		i++;
	}
	if (ret == -1 || parse_map(flr) == -1)
		return (-1);
	return (0);
}

int		read_map_piece(t_filler *flr)
{
	int		ret;
	char	*str;

	ret = 1;
	if (ft_size_map(flr) == -1
		|| !(flr->map = malloc(sizeof(char *) * (flr->y_map + 1)))
			|| (ret = get_next_line(0, &str)) == -1)
		return (-1);
	ft_strdel(&str);
	if (set_map(flr) == -1)
		return (-1);
	if (ft_size_piece(flr) == -1
		|| !(flr->piece = malloc(sizeof(char *) * (flr->y_piece + 1))))
		return (-1);
	if (set_piece(flr) == -1)
		return (-1);
	return (0);
}
