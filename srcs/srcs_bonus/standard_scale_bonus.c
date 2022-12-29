/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_scale_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:32:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 20:54:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

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

static void	calculate_center(t_data *d)
{
	if (d->map->ratio == 1 || (d->map->ratio >= 0.95 && d->map->ratio <= 1.05))
	{
		d->offset->center_img_x = ((double)WINDOW_WIDTH / 2) + MENU_WIDTH - 100;
		d->offset->center_img_y = (double)WINDOW_HEIGHT / 8;
	}
	else if (d->map->ratio != 1)
	{
		d->offset->center_img_x = (WINDOW_WIDTH / 2.5) + MENU_WIDTH - 100;
		d->offset->center_img_y = (double)WINDOW_HEIGHT / 5;
	}
}

void	calculate_scale(t_data *d)
{
	calculate_target_size(d->map);
	calculate_center(d);
	d->offset->scale_x = d->map->target_width / (d->map->width);
	d->offset->scale_y = d->map->target_height / (d->map->height);
}
