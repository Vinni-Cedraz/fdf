/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_isometry_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 00:57:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "printf_libft_structs.h"

static void	unrotate_z(t_point *point, double angle);
static void	unrotate_x(t_point *point, double angle);
static void	reset_x_rotation(t_map *map);
static void	reset_z_rotation(t_map *map);

void	reset_isometry(t_data *d)
{
	reset_zoom(d);
	reset_rotation_around_x(d);
	reset_rotation_around_y(d);
	d->reset_iso++;
	if ((d->apply_iso - d->reset_iso) == 1)
	{
		d->do_step_one = 0;
		d->do_step_two = 1;
	}
	else if ((d->apply_iso - d->reset_iso) == 0)
	{
		d->do_step_two = 0;
		d->do_step_one = 1;
	}
	else
		return ;
	if (d->do_step_two)
		reset_x_rotation(d->map);
	else if (d->do_step_one)
		reset_z_rotation(d->map);
	d->neutral_iso = 0;
}

static void	reset_x_rotation(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			unrotate_x(&map->arr[i][j], RAD_54_73);
			j++;
		}
		i++;
	}
}

static void	reset_z_rotation(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			unrotate_z(&map->arr[i][j], RAD_45);
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
