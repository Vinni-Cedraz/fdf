/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map_bns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 19:46:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

////this function rotates a given point around the z axis:
static void	rotate_z(t_point *point, double angle);
// // this function rotates the a given point around the x axis:
static void	rotate_x(t_point *point, double angle);
//this function calls the two functions above on each point of a map:

void	rotate_map_bns(t_map *map)
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
