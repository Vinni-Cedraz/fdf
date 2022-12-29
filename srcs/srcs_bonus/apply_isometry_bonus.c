/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometry_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 18:31:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	isometry_step_one(t_point *point, double angle);
static void	isometry_step_two(t_point *point, double angle);
static void	apply_step_one(t_map *map);
static void	apply_step_two(t_map *map);

void	do_isometric_steps(t_data *d)
{
	reset_zoom(d);
	reset_rotation_around_x(d);
	reset_rotation_around_y(d);
	d->offset->apply_iso++;
	if ((d->offset->apply_iso - d->offset->reset_iso) == 1)
	{
		d->offset->do_step_one = 1;
		d->offset->do_step_two = 0;
	}
	else if ((d->offset->apply_iso - d->offset->reset_iso) == 2)
	{
		d->offset->do_step_two = 1;
		d->offset->do_step_one = 0;
	}
	else
		return ;
	if (d->offset->do_step_one)
		apply_step_one(d->map);
	else if (d->offset->do_step_two)
		apply_step_two(d->map);
	if (d->offset->apply_iso - d->offset->reset_iso == 2)
		d->state->isometric = 1;
}

static void	apply_step_one(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			isometry_step_one(&map->arr[i][j], RAD_45);
			j++;
		}
		i++;
	}
}

static void	apply_step_two(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			isometry_step_two(&map->arr[i][j], RAD_54_73);
			j++;
		}
		i++;
	}
}

static void	isometry_step_one(t_point *point, double angle)
{
	double	x;
	double	y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
}

static void	isometry_step_two(t_point *point, double angle)
{
	double	y;
	double	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(angle) - z * sin(angle);
	point->z = y * sin(angle) + z * cos(angle);
}
