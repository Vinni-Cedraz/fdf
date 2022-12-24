/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 16:31:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_zoom_in(t_data *d);
static void	aux_zoom_out(t_data *d);
static void	find_center(t_data *d);

static void	find_center(t_data *d)
{
	d->cx = (double)d->map->width / 2;
	d->cy = (double)d->map->height / 2;
	d->cz = (double)d->map->max_z / 2;
}

void	zoom_in(t_data *d)
{
	if (d->clockwise - d->counter_clock != 1)
		return ;
	find_center(d);
	aux_zoom_in(d);
}

void	zoom_out(t_data *d)
{
	if (d->clockwise - d->counter_clock != 1)
		return ;
	aux_zoom_out(d);
}

static void	aux_zoom_in(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			d->map->arr[i][j].x = (d->map->arr[i][j].x - d->cx) * 1.1 + d-> \
				cx * 0.9;
			d->map->arr[i][j].y = (d->map->arr[i][j].y - d->cy) * 1.1 + d-> \
				cy * 0.9;
			j++;
		}
		i++;
	}
}

static void	aux_zoom_out(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			d->map->arr[i][j].x = (d->map->arr[i][j].x - d->cx) * 0.9 + d-> \
				cx * 1.1;
			d->map->arr[i][j].y = (d->map->arr[i][j].y - d->cy) * 0.9 + d-> \
				cy * 1.1;
			j++;
		}
		i++;
	}
}
