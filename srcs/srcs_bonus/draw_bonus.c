/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:47:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 23:50:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	draw_menu(t_data *d);
static void	draw_menu_background(t_img *img);
static void	put_pixel_img_bonus(t_img *img, int x, int y, int color);
static void	paint_it_black(t_data *data);

int	draw_bonus(t_data *d)
{
	paint_it_black(d);
	colorize_points_bonus(d->map);
	if (d->state.grid_style_nb == 1)
		render_map_bonus(d, 1, 0, 0);
	else if (d->state.grid_style_nb == 2)
		render_map_bonus(d, 0, 1, 0);
	else if (d->state.grid_style_nb == 3)
		render_map_bonus(d, 0, 0, 1);
	draw_menu_background(d->img);
	mlx_put_image_to_window(d->mlx->mlx_ptr, d->mlx->win_ptr, d->img->mlx_img, \
		0, 0);
	draw_menu(d);
	return (0);
}

static void	draw_menu_background(t_img *img)
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

static void	paint_it_black(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->img->height)
	{
		j = 0;
		while (j < data->img->width)
		{
			put_pixel_img_bonus(data->img, j, i, BLACK);
			j++;
		}
		i++;
	}
}

static void	draw_menu(t_data *d)
{
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 20, YELLOW, \
		"CONTROLS MENU");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 100, YELLOW, \
		"CHANGE TO ISOMETRIC: 'i'");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 180, YELLOW, \
		"CHANGE TO PARALLEL : 'r'");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 260, YELLOW, \
		"MOVE: ptsow keys");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 300, YELLOW, \
		"but also:'h', 'j', 'k', 'l'");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 420, YELLOW, \
		"ROTATE HORIZONTAL: 'a' / 'd'");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 580, YELLOW, \
		"ROTATE VERTICAL: 'q' / 'e'");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 700, YELLOW, \
		"ZOOM:  'w' / 's'");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 820, YELLOW, \
		"RESTORE ISOMETRIC STATE: ';'");
	mlx_string_put(d->mlx->mlx_ptr, d->mlx->win_ptr, 10, 860, YELLOW, \
		"EXIT: 'esc'");
}

static void	put_pixel_img_bonus(t_img *img, int x, int y, int color)
{
	char	*ptr_to_color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	ptr_to_color = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)ptr_to_color = color;
}
