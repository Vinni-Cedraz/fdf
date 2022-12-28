/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_transformations_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/27 22:39:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_scale_z_up(t_data *d);
static void	aux_scale_z_down(t_data *d);

void	scale_z_up(t_data *d)
{
	printf("neutral_zoom: %d\n, neutral_iso: %d\n, neutral_x: %d\n, neutral_y: %d\n", d->neutral_zoom, d->neutral_iso, d->neutral_x, d->neutral_y);
	if (d->neutral_zoom && d->neutral_iso && d->neutral_x && d->neutral_y)
	{
		reset_isometry(d);
		aux_scale_z_up(d);
		apply_isometry(d);
	}
	else
	{
		// get_back_to_isometric(d);
		return ;
	}
}

void	scale_z_down(t_data *d)
{
	printf("neutral_zoom: %d\n, neutral_iso: %d\n, neutral_x: %d\n, neutral_y: %d\n", d->neutral_zoom, d->neutral_iso, d->neutral_x, d->neutral_y);
	if (d->neutral_zoom && d->neutral_iso && d->neutral_x && d->neutral_y)
	{
		reset_isometry(d);
		aux_scale_z_down(d);
		apply_isometry(d);
	}
	else
	{
		// get_back_to_isometric(d);
		return ;
	}
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
			d->map->arr[i][j].z *= 1.1;
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
			d->map->arr[i][j].z /= 1.1;
			j++;
		}
		j = 0;
		i++;
	}
}

void	mirror_z(t_data *d)
{
	short int	i;
	short int	j;

	if (!d->neutral_iso || !d->neutral_zoom || !d->neutral_x || !d->neutral_y)
		return ;
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
