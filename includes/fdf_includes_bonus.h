/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_includes_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:11:59 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 13:23:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INCLUDES_BONUS_H
# define FDF_INCLUDES_BONUS_H

# include "fdf_includes.h"

void	put_pixel_img_bns(t_img *img, int x, int y, int color);

void	open_win_n_img_bns(t_data *data);

int		parse_map_bns(char *argv, t_data *d);

void	render_map_bns(t_data *data);

void	rotate_map_bns(t_map *fdf);

void	colorize_bns(t_map *map);

void	render_line_bns(t_point p1, t_point p2, int color, t_data *d);

int		close_win_bns(t_data *data);

void	blackout_bns(t_data *fdf);

int		translation_movements_and_esc(int key, t_data *data);

int		rotation_movements(t_data *d, int key);
#endif
