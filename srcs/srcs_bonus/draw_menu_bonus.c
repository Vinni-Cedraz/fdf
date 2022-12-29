/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 04:57:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 16:39:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	draw_menu_background(t_img *img)
{
	int	x;
	int	y;

	x = -1;
	while (++x < MENU_WIDTH)
	{
		y = -1;
		while (++y <= WINDOW_HEIGHT)
			put_pixel_img_bonus(img, x, y, DARKER_GRAY);
	}
}

void	draw_menu(t_data *d)
{
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 20, YELLOW, \
		"CONTROLS MENU");
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 100, YELLOW, \
		"CHANGE TO ISOMETRIC: 'i'");
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 180, YELLOW, \
		"CHANGE TO PARALLEL : 'r'");
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 260, YELLOW, \
		"MOVE: arrow keys");
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 300, YELLOW, \
		"but also:'h', 'j', 'k', 'l'");
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 420, YELLOW, \
		"ROTATE HORIZONTAL: 'a' / 'd'");
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 580, YELLOW, \
		"ROTATE VERTICAL: 'q' / 'e'");
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 700, YELLOW, \
		"ZOOM:  'w' / 's'");
	mlx_string_put(d->mlx->ptr, d->mlx->win, 10, 820, YELLOW, "EXIT: 'esc'");
}
