/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_transformations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 06:50:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_scale_z_up(t_data *d);
static void	aux_scale_z_down(t_data *d);

void	scale_z_up(t_data *d)
{
	if (d->clockwise - d->counter_clock != 1)
		return ;
	reset_isometry(d);
	aux_scale_z_up(d);
	apply_isometry(d);
}

void	scale_z_down(t_data *d)
{
	if (d->clockwise - d->counter_clock != 1)
		return ;
	reset_isometry(d);
	aux_scale_z_down(d);
	apply_isometry(d);
}

static void	aux_scale_z_up(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < d->map->height)
	{
		while (j < d->map->width)
		{
			d->map->arr[i][j].z *= (double)1.1;
			j++;
		}
		j = 0;
		i++;
	}
}

static void	aux_scale_z_down(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < d->map->height)
	{
		while (j < d->map->width)
		{
			d->map->arr[i][j].z /= (double)1.1;
			j++;
		}
		j = 0;
		i++;
	}
}

void	mirror_z(t_data *d)
{
	int	i;
	int	j;

	reset_isometry(d);
	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			d->map->arr[i][j].z *= -1;
			j++;
		}
		i++;
	}
	apply_isometry(d);
}
