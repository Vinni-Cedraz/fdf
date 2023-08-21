/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xy_range_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:57:43 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:56:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include <limits.h>

static t_xy_range			get_xyz_range(t_point *point, t_xy range);

void	get_xyz_range_bonus(void)
{
	t_data				*d;
	t_map				*map;
	t_xy_range			range;
	static short		call_counter;

	d = get_data();
	range = ft_lstpoint_iter_and_get(d->map->pts, &get_xyz_range);
	d->map->max_x = range.max_x;
	d->map->min_x = range.min_x;
	d->map->max_y = range.max_y;
	d->map->min_y = range.min_y;
	d->map->max_z = (short)range.max_z;
	d->map->min_z = (short)range.min_z;
	map = d->map;
	if (++call_counter == 1)
	{
		map->initial_max_z = map->max_z;
		map->is_plateau = (map->max_z == map->min_z);
	}
	else
		call_counter = 2;
}

static inline t_xy_range	get_xyz_range(t_point *point, t_xy range)
{
	if (point->x > range.max_x)
		range.max_x = point->x;
	if (point->x < range.min_x)
		range.min_x = point->x;
	if (point->y > range.max_y)
		range.max_y = point->y;
	if (point->y < range.min_y)
		range.min_y = point->y;
	if (point->z > range.max_z)
		range.max_z = point->z;
	if (point->z < range.min_z)
		range.min_z = point->z;
	return (range);
}
