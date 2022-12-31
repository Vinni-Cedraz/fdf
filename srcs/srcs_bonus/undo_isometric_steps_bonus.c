/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_isometric_steps_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:49:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 10:04:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	undo_second_step(t_map *map);
static void	undo_first_step(t_map *map);

void	undo_isometric_steps_bonus(t_data *d)
{
	if (!d->neutral_x || !d->neutral_y || !d->neutral_zoom)
		return ;
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
		undo_second_step(d->map);
	else if (d->do_step_one)
		undo_first_step(d->map);
	d->neutral_iso = 0;
}

static void	undo_second_step(t_map *map)
{
	int		i;
	int		j;
	double	z;
	double	y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			z = map->arr[i][j].z;
			y = map->arr[i][j].y;
			map->arr[i][j].z = z * cos(RAD_54_73) - y * sin(RAD_54_73);
			map->arr[i][j].y = z * sin(RAD_54_73) + y * cos(RAD_54_73);
			j++;
		}
		i++;
	}
}

static void	undo_first_step(t_map *map)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x = map->arr[i][j].x;
			y = map->arr[i][j].y;
			map->arr[i][j].x = x * cos(-RAD_45) - y * sin(-RAD_45);
			map->arr[i][j].y = x * sin(-RAD_45) + y * cos(-RAD_45);
			j++;
		}
		i++;
	}
}
