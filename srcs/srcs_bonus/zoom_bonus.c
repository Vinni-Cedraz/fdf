/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 18:09:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	iterate_points(t_data *d, short int zoom_in, short int zoom_out);
static void	zoom_in_or_out(t_point *p, t_data *d, short int in, short int out);

void	zoom(t_data *d, short int zoom_in, short int zoom_out)
{
	d->offset->center_x = d->map->arr[d->map->height / 2][d->map->width / 2].x;
	d->offset->center_y = d->map->arr[d->map->height / 2][d->map->width / 2].y;
	d->offset->center_z = d->map->arr[d->map->height / 2][d->map->width / 2].z;
	if (zoom_in)
	{
		if ((d->state->zoomed_in - d->state->zoomed_out) >= 36)
			return ;
		iterate_points(d, 1, 0);
	}
	else if (zoom_out)
	{
		if ((d->state->zoomed_out - d->state->zoomed_in) >= 36)
			return ;
		iterate_points(d, 0, 1);
	}
	if ((d->state->zoomed_in - d->state->zoomed_out) == 0)
		d->state->neutral_zoom = 1;
	else
		d->state->neutral_zoom = 0;
}

static void	iterate_points(t_data *d, short int zoom_in, short int zoom_out)
{
	short int	i;
	short int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			if (zoom_in)
				zoom_in_or_out(&d->map->arr[i][j], d, 1, 0);
			else if (zoom_out)
				zoom_in_or_out(&d->map->arr[i][j], d, 0, 1);
			j++;
		}
		i++;
	}
}

static void	zoom_in_or_out(t_point *p, t_data *d, short int in, short int out)
{
	if (in)
	{
		p->x = d->offset->center_x + (p->x - d->offset->center_x) * 1.1;
		p->y = d->offset->center_y + (p->y - d->offset->center_y) * 1.1;
		d->state->zoomed_in++;
	}
	else if (out)
	{
		p->x = d->offset->center_x + (p->x - d->offset->center_x) / 1.1;
		p->y = d->offset->center_y + (p->y - d->offset->center_y) / 1.1;
		d->state->zoomed_out++;
	}
}
