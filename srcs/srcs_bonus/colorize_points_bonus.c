/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 22:04:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void		get_max_altitude(t_map *map);
static void		get_min_altitude(t_map *map);
static void		get_altitude_range(t_map *map);
static t_short	is_colorized(t_map *map);

void	colorize_points_bonus(t_map *map)
{
	t_short	i;
	t_short	j;

	i = -1;
	get_altitude_range(map);
	if (!is_colorized(map))
	{
		while (++i < map->height)
		{
			j = -1;
			while (++j < map->width)
			{
				if (map->arr[i][j].z < 0)
					map->arr[i][j].color = RED;
				if (map->arr[i][j].z == map->min_z)
					map->arr[i][j].color = BLUE;
				else if (map->arr[i][j].z == map->max_z)
					map->arr[i][j].color = MAGENTA;
				else if (map->arr[i][j].z > 0)
					map->arr[i][j].color = CYAN;
				else if (map->arr[i][j].z == 0)
					map->arr[i][j].color = LIGHT_GRAY;
			}
		}
	}
}

static void	get_altitude_range(t_map *map)
{
	get_max_altitude(map);
	get_min_altitude(map);
}

static void	get_max_altitude(t_map *map)
{
	t_short	i;
	t_short	j;
	t_short	max_z;

	i = 0;
	max_z = _SC_INT_MIN / 2;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->arr[i][j].z > max_z)
				max_z = map->arr[i][j].z;
			j++;
		}
		i++;
	}
	map->max_z = max_z;
}

static void	get_min_altitude(t_map *map)
{
	t_short	i;
	t_short	j;
	t_short	min_z;

	i = 0;
	min_z = map->max_z;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->arr[i][j].z < min_z)
				min_z = map->arr[i][j].z;
			j++;
		}
		i++;
	}
	map->min_z = min_z;
}

static t_short	is_colorized(t_map *map)
{
	t_short	i;
	t_short	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->arr[i][j].color != CYAN)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
