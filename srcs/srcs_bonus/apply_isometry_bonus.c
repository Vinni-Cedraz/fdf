/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometry_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/27 20:28:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	rotate_around_z(t_point *point, double angle);
static void	rotate_around_x(t_point *point, double angle);
static void	apply_z_rotation(t_map *map);
static void	apply_x_rotation(t_map *map);

void	apply_isometry(t_data *d)
{
	d->apply_iso++;
	if ((d->apply_iso - d->reset_iso) == 1)
	{
		d->do_step_one = 1;
		d->do_step_two = 0;
	}
	else if ((d->apply_iso - d->reset_iso) == 2)
	{
		d->do_step_two = 1;
		d->do_step_one = 0;
	}
	else
		return ;
	if (d->do_step_one)
		apply_z_rotation(d->map);
	else if (d->do_step_two)
		apply_x_rotation(d->map);
	if (d->do_step_two)
		d->neutral_iso = 1;
	else if (d->do_step_one)
		d->neutral_iso = 0;
}

static void	apply_z_rotation(t_map *map)
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

static void	apply_x_rotation(t_map *map)
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
	double	x;
	double	y;

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
