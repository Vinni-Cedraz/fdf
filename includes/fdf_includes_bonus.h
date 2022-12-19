/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_includes_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:11:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/19 15:44:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INCLUDES_BONUS_H
# define FDF_INCLUDES_BONUS_H

# include "fdf_includes.h"

void	put_pixel_img_bns(t_img *img, int x, int y, int color);

void	open_win_n_img_bns(t_data *data);

int		parse_map_bns(char *argv, t_data *d);

void	render_map_bns(t_data *data);

void	colorize_bns(t_map *map);

void	render_line_bns(t_point p1, t_point p2, int color, t_data *d);

int		close_win_bns(t_data *data);

void	blackout_bns(t_data *fdf);

int		deal_keys(int key, t_data *data);

int		translation_movements(t_data *data);

int		apply_isometry(t_data *d);

int		reset_isometry(t_data *map);

void	move_down(t_data *d);

void	move_up(t_data *d);

void	move_left(t_data *d);

void	move_right(t_data *d);

void	rotate_15_around_z(t_data *d);

void	reverse_15_around_z(t_data *d);

void	scale_z_up(t_data *d);

void	scale_z_down(t_data *d);

void	mirror_z(t_data *d);

void	zoom_in(t_data *d);

void	zoom_out(t_data *d);

#endif
