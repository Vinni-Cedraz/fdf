/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:12:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/12 18:34:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

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
