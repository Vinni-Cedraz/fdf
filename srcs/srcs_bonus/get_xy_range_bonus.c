/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xy_range_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:01:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/04 14:04:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	get_max_x(t_data *d)
{
	t_n		*map;
	t_point	p;

	map = d->map->pts;
	d->map->max_x = map->point.x;
	while (map)
	{
		p = map->point;
		if (p.x > d->map->max_x)
			d->map->max_x = p.x;
		map = map->next;
	}
}

inline void	get_max_y(t_data *d)
{
	t_n		*map;
	t_point	p;

	map = d->map->pts;
	d->map->max_y = map->point.y;
	while (map)
	{
		p = map->point;
		if (p.y > d->map->max_y)
			d->map->max_y = p.y;
		map = map->next;
	}
}

inline void	get_min_y(t_data *d)
{
	t_n		*map;
	t_point	p;

	map = d->map->pts;
	d->map->min_y = map->point.y;
	while (map)
	{
		p = map->point;
		if (p.y < d->map->min_y)
			d->map->min_y = p.y;
		map = map->next;
	}
}

inline void	get_min_x(t_data *d)
{
	t_n		*map;
	t_point	p;

	map = d->map->pts;
	d->map->min_x = map->point.x;
	while (map)
	{
		p = map->point;
		if (p.x < d->map->min_x)
			d->map->min_x = p.x;
		map = map->next;
	}
}
