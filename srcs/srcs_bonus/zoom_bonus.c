/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/27 13:38:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	find_center(t_data *d);

void	zoom_in(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	d->zoom_in++;
	find_center(d);
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
	if ((d->zoom_in - d->zoom_out) == 0)
		d->neutral_zoom = 1;
}

void	zoom_out(t_data *d)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	d->zoom_out++;
	find_center(d);
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
	if ((d->zoom_in - d->zoom_out) == 0)
		d->neutral_zoom = 1;
}

static void	find_center(t_data *d)
{
	d->cx = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->cy = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->cz = d->map->arr[d->map->height / 2][d->map->width / 2].z;
}
