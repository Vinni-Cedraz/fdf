/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_5_around_y.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:50:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 15:50:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_rotate_5_around_y(t_data *d);
static void	aux_reverse_5_around_y(t_data *d);
static void	find_center(t_data *d);

void	rotate_5_around_y(t_data *d)
{
	d->clockwise += 5;
	aux_rotate_5_around_y(d);
}

void	reverse_5_around_y(t_data *d)
{
	d->clockwise -= 5;
	aux_reverse_5_around_y(d);
}

static void	find_center(t_data *d)
{
	d->cx = (double)d->map->width / 2;
	d->cz = (double)d->map->max_z / 2;
}

static void	aux_rotate_5_around_y(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x;
			z = d->map->arr[i][j].z;
			d->map->arr[i][j].x = (x - d->cx) * cos(ANGLE_5) + (z - d->cz)
				* sin(ANGLE_5) + d->cx;
			d->map->arr[i][j].z = -(x - d->cx) * sin(ANGLE_5) + (z - d->cz)
				* cos(ANGLE_5) + d->cz;
			j++;
		}
		i++;
	}
}

static void	aux_reverse_5_around_y(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x;
			z = d->map->arr[i][j].z;
			d->map->arr[i][j].x = (x - d->cx) * cos(-ANGLE_5) + (z - d->cz)
				* sin(-ANGLE_5) + d->cx;
			d->map->arr[i][j].z = -(x - d->cx) * sin(-ANGLE_5) + (z - d->cz)
				* cos(-ANGLE_5) + d->cz;
			j++;
		}
		i++;
	}
}
