/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:47:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 22:49:46 by vcedraz-         ###   ########.fr       */
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
	ft_lstpoint_toarr(d->map->pts, d->map->width, d->map->arr);
	if (d->offset->neutral_zoom)
		take_zoom_snapshot(d);
	render_map_bonus(d);
	draw_menu_background(d->img);
	mlx_put_image_to_window(d->mlx->ptr, d->mlx->win_ptr, d->img->ptr, 0, 0);
	draw_menu(d);
	return (0);
}

static void	draw_menu_background(t_img *img)
{
	int	counter;
	int	menu_size;
	int	i;
	int	j;

	counter = 0;
	menu_size = MENU_WIDTH * img->height;
	while (counter < menu_size)
	{
		i = counter / img->height;
		j = counter % img->height;
		put_pixel_img_bonus(img, i, j, DARKER_GRAY);
		counter++;
	}
}

static void	paint_it_black(t_data *data)
{
	int	counter;
	int	img_size;
	int	i;
	int	j;

	counter = 0;
	img_size = data->img->width * data->img->height;
	while (counter < img_size)
	{
		i = counter / data->img->height;
		j = counter % data->img->height;
		put_pixel_img_bonus(data->img, i, j, BLACK);
		counter++;
	}
}

static void	draw_menu(t_data *d)
{
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 20, YELLOW, \
		"CONTROLS MENU");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 100, YELLOW, \
		"CHANGE TO ISOMETRIC: 'i'");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 180, YELLOW, \
		"CHANGE TO PARALLEL : 'r'");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 260, YELLOW, \
		"MOVE: ptsow keys");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 300, YELLOW, \
		"but also:'h', 'j', 'k', 'l'");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 420, YELLOW, \
		"ROTATE HORIZONTAL: 'a' / 'd'");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 580, YELLOW, \
		"ROTATE VERTICAL: 'q' / 'e'");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 700, YELLOW, \
		"ZOOM:  'w' / 's'");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 820, YELLOW, \
		"RESTORE ISOMETRIC STATE: ';'");
	mlx_string_put(d->mlx->ptr, d->mlx->win_ptr, 10, 860, YELLOW, \
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
