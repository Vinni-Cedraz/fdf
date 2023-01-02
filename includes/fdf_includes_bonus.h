/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_includes_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:11:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 11:15:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INCLUDES_BONUS_H
# define FDF_INCLUDES_BONUS_H

#include "fdf_structs_bonus.h"
# include "fdf_includes.h"

# define MENU_WIDTH 183

// PART ONE//
void	data_initializer_bonus(t_data *d);

int		parse_map_bonus(char *argv, t_data *d);

void	calculate_default_scale_bonus(t_data *d);

void	define_rotation_matrices_bonus(t_rotation_matrices *matrix);

void	linear_transformations_bonus(t_point **point, t_matrix *rotation);

void	render_line_bonus(t_point p1, t_point p2, t_data *d);

void	render_map_bonus(t_data *d, t_short squre, t_short cross, t_short pent);

void	colorize_points_bonus(t_map *map);

int		draw_bonus(t_data *d);

// PART TWO//
int		deal_keys_bonus(int key, t_data *d);

void	two_steps_to_isometry_bonus(t_data *d, t_short not_from_parallel);

void	undo_isometric_steps_bonus(t_data *d);

void	zoom_bonus(t_data *d, t_short in, t_short out, t_short reset);

void	change_altitude_bonus(t_data *d, t_short up, t_short mirror);

int		close_win_bonus(t_data *data);
#endif
