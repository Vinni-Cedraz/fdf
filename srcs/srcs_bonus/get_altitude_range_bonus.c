/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_altitude_range_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:43:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/11 20:03:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static inline short	get_max_z(t_n *map);
static inline short	get_min_z(t_n *map);

void	get_altitude_range_bonus(t_map *map)
{
	static size_t	first;

	first++;
	map->max_z = get_max_z(map->pts);
	map->min_z = get_min_z(map->pts);
	if (first == 1)
	{
		map->initial_max_z = map->max_z;
		map->is_plateau = (map->max_z == map->min_z);
	}
}

static inline short	get_max_z(t_n *map)
{
	short	max_z;

	max_z = map->point.z;
	while (map->next)
	{
		map = map->next;
		if (map->point.z > max_z)
			max_z = map->point.z;
	}
	return (max_z);
}

static inline short	get_min_z(t_n *map)
{
	short	min_z;

	min_z = map->point.z;
	while (map->next)
	{
		map = map->next;
		if (map->point.z < min_z)
			min_z = map->point.z;
	}
	return (min_z);
}
