/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_15_around_y.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:50:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/20 12:55:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static	void	rotate_15_around_y(t_data *d);
static	void	reverse_15_around_y(t_data *d);

void	call_rotate_15_y(t_data *d)
{
	rotate_15_around_y(d);
	draw(d);
}

void	call_reverse_15_y(t_data *d)
{
	reverse_15_around_y(d);
	draw(d);
}

static	void	rotate_15_around_y(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x;
			z = d->map->arr[i][j].z;
			d->map->arr[i][j].x = x * cos(15 * M_PI / 180)
				+ z * sin(15 * M_PI / 180);
			d->map->arr[i][j].z = -x * sin(15 * M_PI / 180)
				+ z * cos(15 * M_PI / 180);
			j++;
		}
		i++;
	}
}

static	void	reverse_15_around_y(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x;
			z = d->map->arr[i][j].z;
			d->map->arr[i][j].x = x * cos(-15 * M_PI / 180)
				+ z * sin(-15 * M_PI / 180);
			d->map->arr[i][j].z = -x * sin(-15 * M_PI / 180)
				+ z * cos(-15 * M_PI / 180);
			j++;
		}
		i++;
	}
}
