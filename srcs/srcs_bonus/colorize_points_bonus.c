/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 23:15:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "t_point_bonus.h"

static void		get_max_altitude(t_map *map);
static void		get_min_altitude(t_map *map);
static t_short	is_colorized(t_map *map);

void	colorize_points_bonus(t_map *map)
{
	t_node_with_a_point	*tmp;

	if (is_colorized(map))
		return ;
	tmp = map->pts;
	get_max_altitude(map);
	get_min_altitude(map);
	while (tmp)
	{
		if (tmp->point.z < 0)
			tmp->point.color = RED;
		if (tmp->point.z == map->min_z)
			tmp->point.color = BLUE;
		else if (tmp->point.z == map->max_z)
			map->pts->point.color = MAGENTA;
		else if (tmp->point.z > 0)
			tmp->point.color = CYAN;
		else if (tmp->point.z == 0)
			tmp->point.color = LIGHT_GRAY;
		tmp = tmp->next;
	}
}

static void	get_max_altitude(t_map *map)
{
	short				max_z;
	t_node_with_a_point	*tmp;

	max_z = -32768;
	tmp = map->pts;
	while (tmp)
	{
		if (tmp->point.z > max_z)
			max_z = tmp->point.z;
		tmp = tmp->next;
	}
	map->max_z = max_z;
}

static void	get_min_altitude(t_map *map)
{
	short				min_z;
	t_node_with_a_point	*tmp;

	min_z = map->max_z;
	tmp = map->pts;
	while (tmp)
	{
		if (tmp->point.z < min_z)
			min_z = tmp->point.z;
	}
	map->min_z = min_z;
}

static t_short	is_colorized(t_map *map)
{
	t_node_with_a_point	*tmp;

	tmp = map->pts;
	while (tmp)
	{
		if (tmp->point.color != CYAN)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
