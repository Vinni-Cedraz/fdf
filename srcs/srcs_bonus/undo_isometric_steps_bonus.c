/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_isometric_steps_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:49:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 21:59:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "fdf_structs.h"

static void	undo_second_step(t_map *map);
static void	undo_first_step(t_map *map);

void	undo_isometric_steps_bonus(t_data *d)
{
	if (!d->state.neutral_x || !d->state.neutral_y || !d->state.neutral_zoom)
		return ;
	d->state.step_back++;
	if ((d->state.step_forward - d->state.step_back) == 1)
	{
		d->state.do_step_one = 0;
		d->state.do_step_two = 1;
	}
	else if ((d->state.step_forward - d->state.step_back) == 0)
	{
		d->state.do_step_two = 0;
		d->state.do_step_one = 1;
	}
	else
		return ;
	if (d->state.do_step_two)
		undo_second_step(d->map);
	else if (d->state.do_step_one)
		undo_first_step(d->map);
	d->state.isometric = 0;
}

static void	undo_second_step(t_map *map)
{
	t_short	i;
	t_short	j;
	double	z;
	double	y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			z = map->pts[i][j].z;
			y = map->pts[i][j].y;
			map->pts[i][j].z = z * cos(RAD_54_73) - y * sin(RAD_54_73);
			map->pts[i][j].y = z * sin(RAD_54_73) + y * cos(RAD_54_73);
			j++;
		}
		i++;
	}
}

static void	undo_first_step(t_map *map)
{
	t_short	i;
	t_short	j;
	double	x;
	double	y;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x = map->pts[i][j].x;
			y = map->pts[i][j].y;
			map->pts[i][j].x = x * cos(-RAD_45) - y * sin(-RAD_45);
			map->pts[i][j].y = x * sin(-RAD_45) + y * cos(-RAD_45);
			j++;
		}
		i++;
	}
}
