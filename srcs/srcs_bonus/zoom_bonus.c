/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 12:10:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	find_center(t_data *d);
static void	aux_zoom_out(t_data *d);
static void	aux_zoom_in(t_data *d);

void	zoom(t_data *d, short int in, short int out)
{
	if (in)
	{
		if ((d->zoom_in - d->zoom_out) >= 36)
			return ;
		find_center(d);
		aux_zoom_in(d);
	}
	else if (out)
	{
		if ((d->zoom_out - d->zoom_in) >= 36)
			return ;
		find_center(d);
		aux_zoom_out(d);
	}
}

static void	aux_zoom_in(t_data *d)
{
	short int	i;
	short int	j;
	double		x;
	double		y;

	i = 0;
	d->zoom_in++;
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
	else
		d->neutral_zoom = 0;
}

static void	aux_zoom_out(t_data *d)
{
	short int	i;
	short int	j;
	double		x;
	double		y;

	i = 0;
	d->zoom_out++;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x - d->cx;
			y = d->map->arr[i][j].y - d->cy;
			d->map->arr[i][j].x = d->cx + x / 1.1;
			d->map->arr[i][j].y = d->cy + y / 1.1;
			j++;
		}
		i++;
	}
	if ((d->zoom_in - d->zoom_out) == 0)
		d->neutral_zoom = 1;
	else
		d->neutral_zoom = 0;
}

static void	find_center(t_data *d)
{
	d->cx = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->cy = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->cz = d->map->arr[d->map->height / 2][d->map->width / 2].z;
}
