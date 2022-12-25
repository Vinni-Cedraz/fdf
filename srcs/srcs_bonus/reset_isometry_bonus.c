/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_isometry_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/25 20:02:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	unrotate_z(t_point *point, double angle);
static void	unrotate_x(t_point *point, double angle);
static void	reset_x_rotation_caller(t_data *d);
static void	reset_z_rotation_caller(t_data *d);

void	reset_isometry(t_data *d)
{
	d->counter_clock++;
	if ((d->clockwise - d->counter_clock) != 0 && \
		(d->clockwise - d->counter_clock) != 1)
	  return ;
	else if ((d->clockwise - d->counter_clock) == 1)
		reset_x_rotation_caller(d);
	else if ((d->clockwise - d->counter_clock) == 0)
		reset_z_rotation_caller(d);
}

static void	reset_x_rotation_caller(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			unrotate_x(&d->map->arr[i][j], ANGLE_X);
			j++;
		}
		i++;
	}
}

static void	reset_z_rotation_caller(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			unrotate_z(&d->map->arr[i][j], ANGLE_Z);
			j++;
		}
		i++;
	}
}

static void	unrotate_z(t_point *point, double angle)
{
	double	x;
	double	y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) + y * sin(angle);
	point->y = -x * sin(angle) + y * cos(angle);
}

static void	unrotate_x(t_point *point, double angle)
{
	double	y;
	double	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(angle) + z * sin(angle);
	point->z = -y * sin(angle) + z * cos(angle);
}
