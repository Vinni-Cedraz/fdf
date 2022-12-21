/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_15_around_y.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:32:28 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 03:35:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static	void	aux_rotate_15_around_y(t_data *d);
static	void	aux_reverse_15_around_y(t_data *d);

void	rotate_15_around_y(t_data *d)
{
	aux_rotate_15_around_y(d);
}

void	reverse_15_around_y(t_data *d)
{
	aux_reverse_15_around_y(d);
}

static	void	aux_rotate_15_around_y(t_data *d)
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

static	void	aux_reverse_15_around_y(t_data *d)
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
