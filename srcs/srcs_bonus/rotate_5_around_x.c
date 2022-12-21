/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_5_around_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:28:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 12:32:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_rotate_5_around_x(t_data *d);
static void	aux_reverse_5_around_x(t_data *d);
static void	find_center(t_data *d);

void	rotate_5_around_x(t_data *d)
{
	aux_rotate_5_around_x(d);
}

void	reverse_5_around_x(t_data *d)
{
	aux_reverse_5_around_x(d);
}

static void	find_center(t_data *d)
{
	d->cx = (double)d->map->width / 2;
	d->cy = (double)d->map->height / 2;
	d->cz = (double)d->map->max_z / 2;
}

static void	aux_rotate_5_around_x(t_data *d)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			y = d->map->arr[i][j].y;
			z = d->map->arr[i][j].z;
			d->map->arr[i][j].y = (y - d->cy) * cos(ANGLE_5) + (z - d->cz) \
				* sin(ANGLE_5) + d->cy;
			d->map->arr[i][j].z = -(y - d->cy) * sin(ANGLE_5) + (z - d->cz) \
				* cos(ANGLE_5) + d->cz;
			j++;
		}
		i++;
	}
}

static void	aux_reverse_5_around_x(t_data *d)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = 0;
	find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			y = d->map->arr[i][j].y;
			z = d->map->arr[i][j].z;
			d->map->arr[i][j].y = (y - d->cy) * cos(-ANGLE_5) + (z - d->cz) \
				* sin(-ANGLE_5) + d->cy;
			d->map->arr[i][j].z = -(y - d->cy) * sin(-ANGLE_5) + (z - d->cz) \
				* cos(-ANGLE_5) + d->cz;
			j++;
		}
		i++;
	}
}
