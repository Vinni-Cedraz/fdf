/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_isometry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 17:34:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	unrotate_z(t_point *point, double angle);
static void	unrotate_x(t_point *point, double angle);
static void	reset_isometry_aux(t_data *d);

int	reset_isometry(t_data *d)
{
	blackout_bns(d);
	reset_isometry_aux(d);
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
	return (0);
}

static void	reset_isometry_aux(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			unrotate_x(&d->map->arr[i][j], ANGLE_X);
			unrotate_z(&d->map->arr[i][j], ANGLE_Z);
			j++;
		}
		i++;
	}
}

static void	unrotate_z(t_point *point, double angle)
{
	double	x;
	double	y;

	x = point->x;
	y = point->y;
	point->x = x * cos(angle) + y * sin(angle);
	point->y = -x * sin(angle) + y * cos(angle);
}

static void	unrotate_x(t_point *point, double angle)
{
	double	y;
	double	z;

	y = point->y;
	z = point->z;
	point->y = y * cos(angle) + z * sin(angle);
	point->z = -y * sin(angle) + z * cos(angle);
}