/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_altitude_range_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:43:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/19 00:22:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static inline short	get_max_z(t_node_with_a_point *map);
static inline short	get_min_z(t_node_with_a_point *map);

void	get_altitude_range_bonus(t_map *map)
{
	map->max_z = get_max_z(map->pts);
	map->min_z = get_min_z(map->pts);
	map->initial_max_z = map->max_z;
}

static inline short	get_max_z(t_node_with_a_point *map)
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

static inline short	get_min_z(t_node_with_a_point *map)
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
