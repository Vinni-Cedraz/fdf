/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2_around_y_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:50:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 18:26:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	find_points_to_rotate(t_data *d);
static void	find_points_to_reverse(t_data *d);
static void	rotate_two_degrees(t_point *p, t_data *d);
static void	reverse_two_degrees(t_point *p, t_data *d);

void	rotate_2_around_y(t_data *d, short int rotate, short int reverse)
{
	if (rotate)
	{
		if (!d->state->isometric)
			return ;
		d->offset->rotate_2_around_y++;
		reset_zoom(d);
		find_points_to_rotate(d);
	}
	else if (reverse)
	{
		if (!d->state->isometric)
			return ;
		d->offset->reverse_2_around_y++;
		reset_zoom(d);
		find_points_to_reverse(d);
	}
	if ((d->offset->rotate_2_around_y - d->offset->reverse_2_around_y) == 0)
		d->state->neutral_y = 1;
	else
		d->state->neutral_y = 0;
}

static void	find_points_to_rotate(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	d->offset->center_x = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->offset->center_z = d->map->arr[d->map->height / 2][d->map->width / 2].z;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			rotate_two_degrees(&d->map->arr[i][j], d);
			j++;
		}
		i++;
	}
}

static void	find_points_to_reverse(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	d->offset->center_x = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->offset->center_z = d->map->arr[d->map->height / 2][d->map->width / 2].z;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			reverse_two_degrees(&d->map->arr[i][j], d);
			j++;
		}
		i++;
	}
}

static void	rotate_two_degrees(t_point *p, t_data *d)
{
	double	x;
	double	z;

	x = p->x - d->offset->center_x;
	z = p->z - d->offset->center_z;
	p->x = x * cos(RAD_2) + z * sin(RAD_2) + d->offset->center_x;
	p->z = -x * sin(RAD_2) + z * cos(RAD_2) + d->offset->center_z;
}

static void	reverse_two_degrees(t_point *p, t_data *d)
{
	double	x;
	double	z;

	x = p->x - d->offset->center_x;
	z = p->z - d->offset->center_z;
	p->x = x * cos(-RAD_2) + z * sin(-RAD_2) + d->offset->center_x;
	p->z = -x * sin(-RAD_2) + z * cos(-RAD_2) + d->offset->center_z;
}
