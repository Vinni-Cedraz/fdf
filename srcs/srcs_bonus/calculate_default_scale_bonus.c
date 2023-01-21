/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:32:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 19:31:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void		calculate_target_scaled_map_size(t_map *map);
static void		calculate_x_y_initial_offset(t_data *d);
static double	get_magic_factor(t_data *d);

void	calculate_default_scale_bonus(t_data *d)
{
	calculate_target_scaled_map_size(d->map);
	d->offset.scale = d->map->target_width / d->map->width;
	calculate_x_y_initial_offset(d);
}

static inline void	calculate_target_scaled_map_size(t_map *map)
{
	map->ratio = (double)map->width / (double)map->height;
	if (map->ratio > 1)
	{
		map->target_width = WINDOW_HEIGHT;
		map->target_height = WINDOW_HEIGHT / map->ratio;
	}
	else
	{
		map->target_width = WINDOW_HEIGHT * map->ratio;
		map->target_height = WINDOW_HEIGHT;
	}
}

static inline void	calculate_x_y_initial_offset(t_data *d)
{
	double	magic_factor;

	d->offset.move_x += ((WINDOW_WIDTH - d->map->width * d->offset.scale) / 2);
	d->offset.move_x += (double)MENU_WIDTH / 2;
	magic_factor = get_magic_factor(d);
	d->offset.move_y += (WINDOW_HEIGHT - d->map->height * d->offset.scale) / 2;
	if (d->map->ratio != 1 && !(d->map->ratio >= 0.95 && d->map->ratio <= 1.05))
		d->offset.move_y -= d->map->ratio * magic_factor;
}

static inline double	get_magic_factor(t_data *d)
{
	double	magic_factor;

	magic_factor = d->offset.scale;
	if (magic_factor > 10)
	{
		magic_factor /= 10;
	}
	return (magic_factor);
}
