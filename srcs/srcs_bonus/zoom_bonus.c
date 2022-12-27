/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/26 21:56:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_zoom_in(t_data *d);
static void	aux_zoom_out(t_data *d);
static void	find_center(t_data *d);

static void	find_center(t_data *d)
{
	d->cx = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->cy = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->cz = d->map->arr[d->map->height / 2][d->map->width / 2].z;
}

void	zoom_in(t_data *d)
{
	if (d->clockwise - d->counter_clock != 2)
		return ;
	find_center(d);
	aux_zoom_in(d);
}

void	zoom_out(t_data *d)
{
	if (d->clockwise - d->counter_clock != 2)
		return ;
	aux_zoom_out(d);
}

static void	aux_zoom_in(t_data *d)
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
			x = d->map->arr[i][j].x - d->cx;
			y = d->map->arr[i][j].y - d->cy;
			d->map->arr[i][j].x = d->cx + x * 1.1;
			d->map->arr[i][j].y = d->cy + y * 1.1;
			j++;
		}
		i++;
	}
}

static void	aux_zoom_out(t_data *d)
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
			x = d->map->arr[i][j].x - d->cx;
			y = d->map->arr[i][j].y - d->cy;
			d->map->arr[i][j].x = d->cx + x * 0.9;
			d->map->arr[i][j].y = d->cy + y * 0.9;
			j++;
		}
		i++;
	}
}
