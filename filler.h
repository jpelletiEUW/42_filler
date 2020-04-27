/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:57:30 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/01 14:18:26 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft/libft.h"

typedef struct	s_filler
{
	int			cpt;
	int			x_enn;
	int			y_enn;
	int			x_piece;
	int			y_piece;
	int			x_map;
	int			y_map;
	int			x_pos;
	int			y_pos;
	int			x_off;
	int			y_off;
	int			x_resize;
	int			y_resize;
	int			x_diag;
	int			y_diag;
	int			heatscore;
	int			tmp_score;
	int			player;
	int			**heat;
	char		**map;
	char		**piece;
}				t_filler;

int				read_map_piece(t_filler *flr);
int				player_parse();
int				init_flr(t_filler *flr);
int				ft_size_piece(t_filler *flr);
int				set_piece(t_filler *flr);
int				attack_player(t_filler *flr);
int				check_attack(t_filler *flr);
int				y_offset_piece(t_filler *flr);
int				x_offset_piece(t_filler *flr);
int				y_resize_piece(t_filler *flr);
int				x_resize_piece(t_filler *flr);
int				set_heatmap(t_filler *flr, int i, int j, int use);
int				is_placeable(t_filler *flr, int k, int i, int j);
int				init_rush(t_filler *flr);
int				rush(t_filler *flr, int i, int j);

#endif
