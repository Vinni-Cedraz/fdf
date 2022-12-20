/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_15_around_z.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:00:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/20 13:56:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	rotate_15_around_z_aux(t_data *d);
static void	reverse_15_around_z_aux(t_data *d);

void	rotate_15_around_z(t_data *d)
{
	rotate_15_around_z_aux(d);
}

void	reverse_15_around_z(t_data *d)
{
	reverse_15_around_z_aux(d);
}

static void	rotate_15_around_z_aux(t_data *d)
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
			d->map->arr[i][j].x = x * cos(ANGLE_15) - y * sin(ANGLE_15);
			d->map->arr[i][j].y = x * sin(ANGLE_15) + y * cos(ANGLE_15);
			j++;
		}
		i++;
	}
}

static void	reverse_15_around_z_aux(t_data *d)
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
			d->map->arr[i][j].x = x * cos(ANGLE_15) + y * sin(ANGLE_15);
			d->map->arr[i][j].y = -x * sin(ANGLE_15) + y * cos(ANGLE_15);
			j++;
		}
		i++;
	}
}
