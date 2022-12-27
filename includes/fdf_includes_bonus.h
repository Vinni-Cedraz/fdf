/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_includes_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:11:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/26 23:34:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INCLUDES_BONUS_H
# define FDF_INCLUDES_BONUS_H

# include "fdf_includes.h"
# define MENU_WIDTH 183

void	put_pixel_img_bonus(t_img *img, int x, int y, int color);

void	open_win_n_img_bonus(t_data *data);

int		parse_map_bonus(char *argv, t_data *d);

void	render_map_bonus(t_data *data);

void	colorize_bonus(t_map *map);

void	render_line_bonus(t_point p1, t_point p2, int color, t_data *d);

int		close_win_bonus(t_data *data);

void	blackout_bonus(t_data *fdf);

int		deal_keys(int key, t_data *data);

int		translation_movements(t_data *data);

void	apply_isometry(t_data *d);

void	reset_isometry(t_data *map);

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

int		draw(t_data *d);

void	rotate_2_around_y(t_data *d);

void	reverse_2_around_y(t_data *d);

void	rotate_2_around_x(t_data *d);

void	reverse_2_around_x(t_data *d);

void	data_initializer(t_data *d);

void	draw_menu(t_data *d);

void	draw_menu_background(t_img *img);

#endif
