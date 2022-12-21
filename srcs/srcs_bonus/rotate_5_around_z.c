/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_5_around_z.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:00:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 12:30:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_rotate_5_around_z(t_data *d);
static void	aux_reverse_5_around_z(t_data *d);
static void	find_center(t_data *d);

void	rotate_5_around_z(t_data *d)
{
	aux_rotate_5_around_z(d);
}

void	reverse_5_around_z(t_data *d)
{
	aux_reverse_5_around_z(d);
}

static void	find_center(t_data *d)
{
	d->cx = (double)d->map->width / 2;
	d->cy = (double)d->map->height / 2;
	d->cz = (double)d->map->max_z / 2;
}

static void	aux_rotate_5_around_z(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x;
			y = d->map->arr[i][j].y;
			d->map->arr[i][j].x = (x - d->cx) * cos(ANGLE_5) + (y - d->cy) \
				* sin(ANGLE_5) + d->cx;
			d->map->arr[i][j].y = -(x - d->cx) * sin(ANGLE_5) + (y - d->cy) \
				* cos(ANGLE_5) + d->cy;
			j++;
		}
		i++;
	}
}

static void	aux_reverse_5_around_z(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x;
			y = d->map->arr[i][j].y;
			d->map->arr[i][j].x = (x - d->cx) * cos(-ANGLE_5) + (y - d->cy) \
				* sin(-ANGLE_5) + d->cx;
			d->map->arr[i][j].y = -(x - d->cx) * sin(-ANGLE_5) + (y - d->cy) \
				* cos(-ANGLE_5) + d->cy;
			j++;
		}
		i++;
	}
}
