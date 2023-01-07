/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:27:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 00:15:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	get_max_altitude(t_map *map);
static void	get_min_altitude(t_map *map);
static int	is_colorized(t_map *map);

void	colorize(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	get_max_altitude(map);
	get_min_altitude(map);
	if (!is_colorized(map))
	{
		while (++i < map->height)
		{
			j = -1;
			while (++j < map->width)
			{
				if (map->arr[i][j].z == map->max_z)
					map->arr[i][j].color = MAGENTA;
				else if (map->arr[i][j].z > 0)
					map->arr[i][j].color = CYAN;
			}
		}
	}
}

static void	get_max_altitude(t_map *map)
{
	int	i;
	int	j;
	int	max_z;

	i = 0;
	max_z = -2147483648;
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
	int	i;
	int	j;
	int	min_z;

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

static int	is_colorized(t_map *map)
{
	int	i;
	int	j;

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
