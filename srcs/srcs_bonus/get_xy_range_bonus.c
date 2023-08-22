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

static t_xy_range			get_xy_range(t_point *point);

void	get_xy_range_bonus(void)
{
	t_n			*lst;
	t_data		*d;
	t_xy_range	range;

	d = get_data();
	lst = d->map->pts;
	range = ft_lstpoint_iter_and_get(lst, &get_xy_range);
	d->map->max_x = range.max_x;
	d->map->min_x = range.min_x;
	d->map->max_y = range.max_y;
	d->map->min_y = range.min_y;
}

static inline t_xy_range	get_xy_range(t_point *point)
{
	static t_xy_range	range = (t_xy){
		.max_x = SHRT_MIN,
		.min_x = SHRT_MAX,
		.max_y = SHRT_MIN,
		.min_y = SHRT_MAX
	};

	range.max_x = point->x;
	if (point->x > range.max_x)
		range.max_x = point->x;
	if (point->x < range.min_x)
		range.min_x = point->x;
	if (point->y > range.max_y)
		range.max_y = point->y;
	if (point->y < range.min_y)
		range.min_y = point->y;
	return (range);
}
