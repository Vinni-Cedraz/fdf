/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/26 16:41:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	get_max_altitude(t_map *map);
static void	get_min_altitude(t_map *map);
static void	get_altitude_range(t_map *map);
static int	is_colorized_bonus(t_map *map);

void	colorize_bonus(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	get_altitude_range(map);
	if (!is_colorized_bonus(map))
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

static void	get_max_altitude(t_map *map)
{
	int	i;
	int	j;
	int	max_z;

	i = 0;
	max_z = -2147483648;
	while (i < (*map).height)
	{
		j = 0;
		while (j < (*map).width)
		{
			if ((*map).arr[i][j].z > max_z)
				max_z = (*map).arr[i][j].z;
			j++;
		}
		i++;
	}
	(*map).max_z = max_z;
}

static void	get_min_altitude(t_map *map)
{
	int	i;
	int	j;
	int	min_z;

	i = 0;
	min_z = (*map).max_z;
	while (i < (*map).height)
	{
		j = 0;
		while (j < (*map).width)
		{
			if ((*map).arr[i][j].z < min_z)
				min_z = (*map).arr[i][j].z;
			j++;
		}
		i++;
	}
	(*map).min_z = min_z;
}

static int	is_colorized_bonus(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*map).height)
	{
		j = 0;
		while (j < (*map).width)
		{
			if ((*map).arr[i][j].color != CYAN)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	get_altitude_range(t_map *map)
{
	get_max_altitude(map);
	get_min_altitude(map);
	map->isometric_max_z = map->max_z * pow(cos(RAD_45), -1);
	map->isometric_max_z *= map->scale_z;
}
