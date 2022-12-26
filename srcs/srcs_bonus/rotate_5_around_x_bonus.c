/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_5_around_x_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:28:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/25 22:05:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_rotate_5_around_x(t_data *d);
static void	aux_reverse_5_around_x(t_data *d);
// static void	find_center(t_data *d);

void	rotate_5_around_x(t_data *d)
{
	d->clockwise += 2;
	aux_rotate_5_around_x(d);
}

void	reverse_5_around_x(t_data *d)
{
	d->clockwise -= 2;
	aux_reverse_5_around_x(d);
}

// static void	find_center(t_data *d)
// {
// 	d->cy = (double)d->map->height / 2;
// 	d->cz = (double)d->map->max_z / 2;
// }

static void	aux_rotate_5_around_x(t_data *d)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = 0;
	// find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			y = d->map->arr[i][j].y;
			z = d->map->arr[i][j].z;
			d->map->arr[i][j].y = y * cos(RAD_5) + z * sin(RAD_5);
			d->map->arr[i][j].z = -y * sin(RAD_5) + z * cos(RAD_5);
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
	// find_center(d);
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			y = d->map->arr[i][j].y;
			z = d->map->arr[i][j].z;
			d->map->arr[i][j].y = y * cos(RAD_5) - z * sin(RAD_5);
			d->map->arr[i][j].z = y * sin(RAD_5) + z * cos(RAD_5);
			j++;
		}
		i++;
	}
}
