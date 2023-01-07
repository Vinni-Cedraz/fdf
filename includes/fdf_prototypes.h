/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_prototypes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:47:13 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/06 22:23:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROTOTYPES_H
# define FDF_PROTOTYPES_H
# include "fdf_structs.h"

void	put_pixel_img(t_img *img, int x, int y, int color);

int		deal_key(int key, t_data *data);

void	open_win_n_img(t_data *data);

int		parse_map(char *argv, t_data *d);

void	render_map(t_data *data);

void	linear_transformations(t_data *d, t_matrix *rotation_matrix);

void	standard_scale(t_data *d, short size);

int		draw(t_data *d);

void	rotate_map(t_data *d);

void	colorize(t_map *map);

int		close_win(t_data *data);

void	define_rotation_matrices(t_rotation_matrices *matrix);

void	data_initializer(t_data *d);

#endif
