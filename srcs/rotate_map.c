/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/13 17:50:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

////this function rotates a given point around the z axis:
static void	rotate_z(t_point *point, double angle);
// // this function rotates the a given point around the x axis:
static void	rotate_x(t_point *point, double angle);

//this function calls the two functions above on each point of a map:
void	rotate_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			rotate_z(&map->arr[i][j], ANGLE_Z);
			map->arr[i][j].x += map->width / 2;
			rotate_x(&map->arr[i][j], ANGLE_X);
			map->arr[i][j].y += map->height / 2;
			j++;
		}
		i++;
	}
}

static void	rotate_z(t_point *point, double angle)
{
	double	previous_x;
	double	previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = cos(angle) * previous_x - sin(angle) * previous_y;
	point->y = sin(angle) * previous_x + cos(angle) * previous_y;
}

static void	rotate_x(t_point *point, double angle)
{
	double	previous_y;
	double	previous_z;

	previous_y = point->y;
	previous_z = point->z;
	point->y = cos(angle) * previous_y - sin(angle) * previous_z;
	point->z = sin(angle) * previous_y + cos(angle) * previous_z;
}
