/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometry_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 16:22:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	fifty_three_around_x(t_point *point, double angle);
static void	fourty_five_around_z(t_point *point, double angle);
static void	take_first_step(t_map *map);
static void	take_second_step(t_map *map);

void	two_steps_to_isometry(t_data *d)
{
	if (d->neutral_iso)
		return ;
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
		take_first_step(d->map);
	else if (d->do_step_two)
		take_second_step(d->map);
	if (d->apply_iso - d->reset_iso == 2)
		d->neutral_iso = 1;
}

static void	take_first_step(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			fourty_five_around_z(&map->arr[i][j], RAD_45);
			j++;
		}
		i++;
	}
}

static void	take_second_step(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			fifty_three_around_x(&map->arr[i][j], RAD_54_73);
			j++;
		}
		i++;
	}
}

static void	fourty_five_around_z(t_point *point, double angle)
{
	double	x;
	double	y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) - y * sin(angle);
	point->y = x * sin(angle) + y * cos(angle);
}

static void	fifty_three_around_x(t_point *point, double angle)
{
	double	y;
	double	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(angle) - z * sin(angle);
	point->z = y * sin(angle) + z * cos(angle);
}
