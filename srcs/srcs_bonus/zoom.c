/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/20 12:31:28 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_zoom_in(t_data *d);
static void	aux_zoom_out(t_data *d);

void	zoom_in(t_data *d)
{
	if (d->clockwise - d->counter_clock != 1)
		return ;
	reset_isometry(d);
	aux_zoom_in(d);
	apply_isometry(d);
}

void	zoom_out(t_data *d)
{
	if (d->clockwise - d->counter_clock != 1)
		return ;
	reset_isometry(d);
	aux_zoom_out(d);
	apply_isometry(d);
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
			d->map->arr[i][j].x *= 1.1;
			d->map->arr[i][j].y *= 1.1;
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
			d->map->arr[i][j].x *= 0.9;
			d->map->arr[i][j].y *= 0.9;
			j++;
		}
		i++;
	}
}
