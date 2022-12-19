/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/19 14:43:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	rotate_z(t_point *point, double angle);
static void	rotate_x(t_point *point, double angle);
static void	calculate_z_scale(t_map *map);

void	rotate_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	calculate_z_scale(map);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->arr[i][j].z != 0)
				map->arr[i][j].z *= map->scale_z;
			rotate_z(&map->arr[i][j], ANGLE_Z);
			rotate_x(&map->arr[i][j], ANGLE_X);
			j++;
		}
		i++;
	}
}

static void	rotate_z(t_point *point, double angle)
{
	double	x;
	double	y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
}

static void	rotate_x(t_point *point, double angle)
{
	double	y;
	double	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(angle) - z * sin(angle);
	point->z = y * sin(angle) + z * cos(angle);
}

static void	calculate_z_scale(t_map *map)
{
	double	z_range;

	z_range = map->max_z - map->min_z;
	map->scale_z = 5 / (z_range / 10);
}
