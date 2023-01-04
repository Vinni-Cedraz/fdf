/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/03 15:00:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	rotate_z(t_point *point, double angle);
static void	rotate_x(t_point *point, double angle);
static void	calculate_z_scale(t_data *d);

void	rotate_map(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	calculate_z_scale(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			if (d->map->arr[i][j].z != 0)
				d->map->arr[i][j].z *= d->scale_z;
			rotate_z(&d->map->arr[i][j], RAD_45);
			rotate_x(&d->map->arr[i][j], RAD_54_73);
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

static void	calculate_z_scale(t_data *d)
{
	double	z_range;

	z_range = d->map->max_z - d->map->min_z;
	d->scale_z = 5 / (z_range / 10);
}
