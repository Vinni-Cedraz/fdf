/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_scale_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:32:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 11:22:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	calculate_target_scaled_map_size(t_map *map);
static void	get_values_to_centralize_img_on_window(t_data *d);

void	calculate_scale(t_data *d)
{
	calculate_target_scaled_map_size(d->map);
	d->scale_x = d->map->target_width / (d->map->width);
	d->scale_y = d->map->target_height / (d->map->height);
	get_values_to_centralize_img_on_window(d);
}

static void	calculate_target_scaled_map_size(t_map *map)
{
	map->ratio = (float)map->width / (float)map->height;
	if (map->ratio > 1)
	{
		map->target_width = 720;
		map->target_height = 720 / map->ratio;
	}
	else
	{
		map->target_width = 720 * map->ratio;
		map->target_height = 720;
	}
}

static void	get_values_to_centralize_img_on_window(t_data *d)
{
	if (d->map->ratio == 1 || (d->map->ratio >= 0.95 && d->map->ratio <= 1.05))
	{
		d->centralize_img_x = (WINDOW_WIDTH / 2) + MENU_WIDTH - 100;
		d->centralize_img_y = WINDOW_HEIGHT / 8;
	}
	else if (d->map->ratio != 1)
	{
		d->centralize_img_x = (WINDOW_WIDTH / 2.5) + MENU_WIDTH - 100;
		d->centralize_img_y = WINDOW_HEIGHT / 5;
	}
}
