/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:32:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/03 15:25:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	calculate_target_scaled_map_size(t_map *map, t_short size);
static void	get_values_to_centralize_img_on_window(t_data *d);

void	calculate_default_scale_bonus(t_data *d, t_short size)
{
	calculate_target_scaled_map_size(d->map, size);
	d->offset.scale = d->map->target_width / d->map->width;
	get_values_to_centralize_img_on_window(d);
}

static void	calculate_target_scaled_map_size(t_map *map, t_short size)
{
	map->ratio = (float)map->width / (float)map->height;
	if (map->ratio > 1)
	{
		map->target_width = size;
		map->target_height = size / map->ratio;
	}
	else
	{
		map->target_width = size * map->ratio;
		map->target_height = size;
	}
}

static void	get_values_to_centralize_img_on_window(t_data *d)
{
	double	map_w;
	double	map_h;
	double	win_w;
	double	win_h;
	double	magic_factor;

	map_w = d->map->width;
	map_h = d->map->height;
	win_w = WINDOW_WIDTH;
	win_h = WINDOW_HEIGHT;
	magic_factor = d->offset.scale;
	if (magic_factor > 10)
		magic_factor /= 10;
	if (map_h > map_w)
		ft_swap(&map_h, &map_w, sizeof(double));
	d->offset.move_x += ((win_w - map_w * d->offset.scale) / 2);
	d->offset.move_x += (double)MENU_WIDTH / 2;
	if (d->map->ratio == 1 || (d->map->ratio >= 0.95 && d->map->ratio <= 1.05))
		d->offset.move_y += (win_h - map_h * d->offset.scale) / 2;
	else
	{
		d->offset.move_y += (win_h - map_h * d->offset.scale) / 2;
		d->offset.move_y -= d->map->ratio * magic_factor;
	}
}
