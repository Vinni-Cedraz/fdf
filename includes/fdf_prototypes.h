/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:47:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/15 19:33:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROTOTYPES_H
# define FDF_PROTOTYPES_H
# include "fdf_structs.h"

void	put_pixel_img(t_img *img, int x, int y, int color);

void	render_square(t_img *img, int color, t_square *square);

void	define_square(t_square *square, t_point p1, t_point p2);

void	linedraw(t_img *img, t_point *point1, t_point *point2);

int		deal_key(int key, t_data *data);

void	open_win_n_img(t_data *data);

void	get_map_dimensions(char *argv);

int		parse_map(char *argv, t_data *d);

void	render_map(t_data *data);

void	rotate_map(t_map *fdf);

void	colorize(t_map *map);

void	render_line(t_point p1, t_point p2, int color, t_data *d);

int		close_win(t_data *data);

void	open_img(t_data *data);
#endif
