/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 22:00:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	zoom_in(t_data *d);
static void	zoom_out(t_data *d);
static void	reset_zoom(t_data *d);
static void	find_center(t_data *d);

void	zoom_bonus(t_data *d, t_short in, t_short out, t_short reset)
{
	if (in)
	{
		if ((d->state.zoom_in - d->state.zoom_out) >= 36)
			return ;
		find_center(d);
		zoom_in(d);
	}
	else if (out)
	{
		if ((d->state.zoom_out - d->state.zoom_in) >= 36)
			return ;
		find_center(d);
		zoom_out(d);
	}
	else if (reset)
	{
		find_center(d);
		reset_zoom(d);
	}
}

static void	find_center(t_data *d)
{
	d->offset.cx = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->offset.cy = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->offset.cz = d->map->arr[d->map->height / 2][d->map->width / 2].z;
}

static void	zoom_in(t_data *d)
{
	t_short	i;
	t_short	j;
	double	x;
	double	y;

	i = 0;
	d->state.zoom_in++;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x - d->offset.cx;
			y = d->map->arr[i][j].y - d->offset.cy;
			d->map->arr[i][j].x = d->offset.cx + x * 1.1;
			d->map->arr[i][j].y = d->offset.cy + y * 1.1;
			j++;
		}
		i++;
	}
	if ((d->state.zoom_in - d->state.zoom_out) == 0)
		d->state.neutral_zoom = 1;
	else
		d->state.neutral_zoom = 0;
}

static void	zoom_out(t_data *d)
{
	t_short	i;
	t_short	j;
	double	x;
	double	y;

	i = 0;
	d->state.zoom_out++;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			x = d->map->arr[i][j].x - d->offset.cx;
			y = d->map->arr[i][j].y - d->offset.cy;
			d->map->arr[i][j].x = d->offset.cx + x / 1.1;
			d->map->arr[i][j].y = d->offset.cy + y / 1.1;
			j++;
		}
		i++;
	}
	if ((d->state.zoom_in - d->state.zoom_out) == 0)
		d->state.neutral_zoom = 1;
	else
		d->state.neutral_zoom = 0;
}

static void	reset_zoom(t_data *d)
{
	t_short	i;
	t_short	successive_operations;

	i = -1;
	if (d->state.neutral_zoom)
		return ;
	zoom_bonus(d, 1, 0, 0);
	zoom_bonus(d, 0, 1, 0);
	if (d->state.zoom_in > d->state.zoom_out)
	{
		successive_operations = (d->state.zoom_in - d->state.zoom_out);
		while (++i < successive_operations)
			zoom_bonus(d, 0, 1, 0);
	}
	else
	{
		successive_operations = (d->state.zoom_out - d->state.zoom_in);
		while (++i < successive_operations)
			zoom_bonus(d, 1, 0, 0);
	}
}
