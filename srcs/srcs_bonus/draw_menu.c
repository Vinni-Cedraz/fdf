/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:30:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 03:54:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	draw_menu_background(t_img *img)
{
	int	x;
	int	y;

	x = -1;
	while (++x < X_MENU)
	{
		y = -1;
		while (++y <= WINDOW_HEIGHT)
			put_pixel_img_bns(img, x, y, LIGHT_GRAY);
	}
}

void	draw_menu(t_data *d)
{
	int		y;

	y = 0;
	mlx_string_put(d->mlx_ptr, d->win_ptr, 55, y += 20,
		CYAN, "How to use");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 15, y += 35,
		CYAN, "Zoom: +/- or M/N");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 15, y += 30,
		CYAN, "Move: Arrows");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 15, y += 30,
		CYAN, "Flatten: 'z/'x'");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 15, y += 30,
		CYAN, "Rotate:");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 35, y += 25,
		CYAN, "Y-Axis: W/S");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 35, y += 25,
		CYAN, "X-Axis: A/D");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 35, y += 25,
		CYAN, "Z-Axis: Q/E");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 15, y += 30,
		CYAN, "Projection:");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 35, y += 25,
		CYAN, "ISO/PARALLEL: SPACE");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 35, y += 25,
		CYAN, "RESET: ENTER");
}
