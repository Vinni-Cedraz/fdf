/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_15_around_z.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:00:57 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 20:18:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	rotate_15_around_z_aux(t_data *d);
static void	reverse_15_around_z_aux(t_data *d);

void	rotate_15_around_z(t_data *d)
{
	blackout_bns(d);
	rotate_15_around_z_aux(d);
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

void	reverse_15_around_z(t_data *d)
{
	blackout_bns(d);
	reverse_15_around_z_aux(d);
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

static void	rotate_15_around_z_aux(t_data *d)
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
			x = d->map->arr[i][j].x;
			y = d->map->arr[i][j].y;
			d->map->arr[i][j].x = x * cos(ANGLE_15) - y * sin(ANGLE_15);
			d->map->arr[i][j].y = x * sin(ANGLE_15) + y * cos(ANGLE_15);
			j++;
		}
		i++;
	}
}

static void	reverse_15_around_z_aux(t_data *d)
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
			x = d->map->arr[i][j].x;
			y = d->map->arr[i][j].y;
			d->map->arr[i][j].x = x * cos(ANGLE_15) + y * sin(ANGLE_15);
			d->map->arr[i][j].y = -x * sin(ANGLE_15) + y * cos(ANGLE_15);
			j++;
		}
		i++;
	}
}
