/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2_around_x_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:28:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 18:25:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	find_points_to_rotate(t_data *d);
static void	find_points_to_reverse(t_data *d);
static void	rotate_two_degrees(t_point *p, t_data *d);
static void	reverse_two_degrees(t_point *p, t_data *d);

void	rotate_2_around_x(t_data *d, short int rotate, short int reverse)
{
	if (rotate)
	{
		if (!d->state->isometric)
			return ;
		d->offset->rotate_2_around_x++;
		if ((d->offset->rotate_2_around_x - d->offset->reverse_2_around_x) == 0)
			d->state->neutral_x = 1;
		else
			d->state->neutral_x = 0;
		reset_zoom(d);
		find_points_to_rotate(d);
	}
	else if (reverse)
	{
		if (!d->state->isometric)
			return ;
		d->offset->reverse_2_around_x++;
		if ((d->offset->rotate_2_around_x - d->offset->reverse_2_around_x) == 0)
			d->state->neutral_x = 1;
		else
			d->state->neutral_x = 0;
		reset_zoom(d);
		find_points_to_reverse(d);
	}
}

static void	find_points_to_rotate(t_data *d)
{
	int	i;
	int	j;

	d->offset->center_y = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->offset->center_x = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	i = 0;
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

	d->offset->center_y = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->offset->center_x = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	i = 0;
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
	double	y;
	double	z;

	y = p->y - d->offset->center_y;
	z = p->z - d->offset->center_z;
	p->y = y * cos(RAD_2) + z * sin(RAD_2) + d->offset->center_y;
	p->z = -y * sin(RAD_2) + z * cos(RAD_2) + d->offset->center_z;
}

static void	reverse_two_degrees(t_point *p, t_data *d)
{
	double	y;
	double	z;

	y = p->y - d->offset->center_y;
	z = p->z - d->offset->center_z;
	p->y = y * cos(RAD_2) - z * sin(RAD_2) + d->offset->center_y;
	p->z = y * sin(RAD_2) + z * cos(RAD_2) + d->offset->center_z;
}
