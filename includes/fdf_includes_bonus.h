/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_includes_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:11:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 19:28:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INCLUDES_BONUS_H
# define FDF_INCLUDES_BONUS_H

# include "fdf_includes.h"
# define MENU_WIDTH 183

int		parse_map_bonus(char *argv, t_data *d);

void	render_map_bonus(t_data *data);

void	colorize_bonus(t_map *map);

void	render_line_bonus(t_point p1, t_point p2, int color, t_data *d);

int		close_win_bonus(t_data *data);

void	blackout_bonus(t_data *fdf);

int		deal_keys_bonus(int key, t_data *data);

void	zoom_bonus(t_data *d, short int in, short int out, short int reset);

void	undo_isometric_steps_bonus(t_data *d);

void	change_altitude(t_data *d, short int up, short int mirror);

int		draw_bonus(t_data *d);

void	rotate_around_y(t_data *d, short int rot, short int rev);

void	rotate_around_x(t_data *d, short int rot, short int rev);

void	data_initializer_bonus(t_data *d);

void	reset_rotations(t_data *d, double angle);

void	two_steps_to_isometry_bonus(t_data *d, short int not_from_parallel);

#endif
