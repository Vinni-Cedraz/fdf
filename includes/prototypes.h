/** ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:52:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/03 14:04:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H
# include "structs.h"

void	put_pixel_img(t_img *img, int x, int y, int color);

void	render_square(t_data *data, t_img *img, int color, t_square *square);

void	render_line(t_point point_a, t_point point_b, int color, t_img *img);

void	linedraw(t_img *img, t_point *point1, t_point *point2);

int		deal_key(int key, t_data *data);

void	open_window(t_data *data, t_img *img);

#endif
