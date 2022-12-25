/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:32:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/25 12:32:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	calculate_target_size(t_map *map)
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

static void	calculate_center(t_map *map)
{
	if (map->ratio == 1 || (map->ratio >= 0.95 && map->ratio <= 1.05))
	{
		map->center_x = (double)WINDOW_WIDTH / 2;
		map->center_y = (double)WINDOW_HEIGHT / 8;
	}
	else if (map->ratio != 1)
	{
		map->center_x = (double)WINDOW_WIDTH / 2.5;
		map->center_y = (double)WINDOW_HEIGHT / 5;
	}
}

void	calculate_scale(t_data *d)
{
	calculate_target_size(d->map);
	calculate_center(d->map);
	d->scale_x = d->map->target_width / (d->map->width);
	d->scale_y = d->map->target_height / (d->map->height);
}
