/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometry_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/26 18:32:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	rotate_around_z(t_point *point, double angle);
static void	rotate_around_x(t_point *point, double angle);
static void	z_rotation_caller_function(t_map *map);
static void	x_rotation_caller_function(t_map *map);

void	apply_isometry(t_data *d)
{
	d->clockwise++;
	if ((d->clockwise - d->counter_clock != 1) &&
		(d->clockwise - d->counter_clock != 2))
		return ;
	if ((d->clockwise - d->counter_clock) == 1)
		z_rotation_caller_function(d->map);
	else if ((d->clockwise - d->counter_clock) == 2)
		x_rotation_caller_function(d->map);
}

static void	z_rotation_caller_function(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			rotate_around_z(&map->arr[i][j], RAD_45);
			j++;
		}
		i++;
	}
}

static void	x_rotation_caller_function(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			rotate_around_x(&map->arr[i][j], RAD_54_73);
			j++;
		}
		i++;
	}
}

static void	rotate_around_z(t_point *point, double angle)
{
	double			x;
	double			y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
}

static void	rotate_around_x(t_point *point, double angle)
{
	double	y;
	double	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(angle) - z * sin(angle);
	point->z = y * sin(angle) + z * cos(angle);
}
