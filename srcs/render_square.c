/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:12:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/10 19:44:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

void	define_square(t_square *square, t_point p1, t_point p2)
{
	square->width_start = p1.x;
	square->height_start = p1.y;
	square->total_width = p2.x;
	square->total_height = p2.y;
}

void	render_square(t_img *img, int color, t_square *square)
{
	int	width_start_start;

	width_start_start = square->height_start;
	while (square->height_start < square->total_height)
	{
		square->width_start = width_start_start;
		while (square->width_start < square->total_width)
			put_pixel_img(img, square->width_start++, square->height_start, \
			color);
		++square->height_start;
	}
}
