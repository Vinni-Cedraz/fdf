/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 15:42:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_zoom_in(t_data *d);
static void	aux_zoom_out(t_data *d);

void	zoom_in(t_data *d)
{
	if (d->clockwise - d->counter_clock != 1)
		return ;
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
			d->map->arr[i][j].x = (d->map->arr[i][j].x - d->cx) * 1.1 + d->cx;
			d->map->arr[i][j].y = (d->map->arr[i][j].y - d->cy) * 1.1 + d->cy;
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
			d->map->arr[i][j].x = (d->map->arr[i][j].x - d->cx) * 0.9 + d->cx;
			d->map->arr[i][j].y = (d->map->arr[i][j].y - d->cy) * 0.9 + d->cy;
			j++;
		}
		i++;
	}
}
