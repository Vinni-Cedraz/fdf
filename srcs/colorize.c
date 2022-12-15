/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:27:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/14 23:50:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	get_max_altitude(t_map *map);
static void	get_min_altitude(t_map *map);

void	colorize(t_map *map)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	get_max_altitude(map);
	get_min_altitude(map);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!map->arr[i][j].color)
			{
				color = (map->arr[i][j].z - map->min_z) * 255 / (map->max_z
						- map->min_z);
				map->arr[i][j].color = color;
			}
			j++;
		}
		i++;
	}
}

static void	get_max_altitude(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	(*map).max_z = 0;
	while (i < (*map).height)
	{
		j = 0;
		while (j < (*map).width)
		{
			if ((*map).arr[i][j].z > (*map).max_z)
				(*map).max_z = (*map).arr[i][j].z;
			j++;
		}
		i++;
	}
}

static void	get_min_altitude(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	(*map).min_z = (*map).max_z;
	while (i < (*map).height)
	{
		j = 0;
		while (j < (*map).width)
		{
			if ((*map).arr[i][j].z < (*map).min_z)
				(*map).min_z = (*map).arr[i][j].z;
			j++;
		}
		i++;
	}
}
