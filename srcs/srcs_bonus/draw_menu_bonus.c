/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:19:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 17:20:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	draw_menu_background(t_data *d);
static void	put_pixel_img_bonus(t_img *img, int x, int y, int color);

void	draw_menu(t_data *d)
{
	draw_menu_background(d);
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 20, MAGENTA, \
		"CONTROLS MENU");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 60, CYAN, \
		"FIRST, GO ISO: 'SPACE TWICE'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 100, WHITE, \
		"ROTATE 1: 'a' / 'd'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 140, WHITE, \
		"ROTATE 2: 'q' / 'e'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 180, WHITE, \
		"ROTATE 3: 'x' / 'v'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 220, WHITE, \
		"CHANGE ALTITUDE: 'z' / 'c'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 260, WHITE, \
		"TURN IT INTO A BALL: 'ab'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 300, WHITE, \
		"ZOOM IN: 'w' / 's'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 340, WHITE, \
		"BALL ALTITUDE: 'j' / 'k'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 380, WHITE, \
		"RESET TO ISOMETRIC: ';'");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 420, WHITE, \
		"MOVE: arrow keys");
	mlx_string_put(d->mlx->display_ptr, d->mlx->win_ptr, 10, 460, CYAN, \
		"EXIT: 'esc'");
}

static inline void	draw_menu_background(t_data *d)
{
	int	counter;
	int	menu_size;
	int	height;
	int	i;
	int	j;

	counter = 0;
	menu_size = d->scale->menu_width * d->img->height;
	height = d->img->height;
	while (counter < menu_size)
	{
		i = counter / height;
		j = counter % height;
		put_pixel_img_bonus(d->img, i, j, DARKER_GRAY);
		counter++;
	}
}

static inline void	put_pixel_img_bonus(t_img *img, int x, int y, int color)
{
	char	*ptr_to_color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	ptr_to_color = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)ptr_to_color = color;
}
