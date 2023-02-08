/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:32:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/08 12:10:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void				calculate_target_size(t_data *d);
static void				calculate_initial_offset(t_data *d);
static double			calculate_magic_factor(t_data *d);
static int				is_map_square(double ratio);

void	calculate_default_scale_bonus(t_data *d)
{
	d->map->is_square = is_map_square(d->map->ratio);
	calculate_target_size(d);
	d->offset->scale = d->map->target_width / d->map->width;
	d->map->radius *= d->offset->scale;
	calculate_initial_offset(d);
}

static inline void	calculate_target_size(t_data *d)
{
	is_map_vertical(d->map);
	d->map->target_width = WIN_HGHT * 0.9;
	if (d->map->size > 1800 && d->map->is_square)
		d->map->target_width = WIN_HGHT;
	else if (d->map->size > 1800 && !d->map->is_square)
		d->map->target_width = WIN_HGHT * 1.5;
	if (d->map->is_vertical)
		d->map->target_width = WIN_HGHT * 0.7;
}

static inline void	calculate_initial_offset(t_data *d)
{
	double	x_offset;
	double	y_offset;

	x_offset = (WINDOW_WIDTH - d->map->width * d->offset->scale) / 2;
	x_offset += (double)MENU_WIDTH / 2;
	y_offset = (WIN_HGHT - d->map->height * d->offset->scale) / 2;
	y_offset += calculate_magic_factor(d);
	d->offset->move_x += x_offset;
	d->offset->move_y += y_offset;
}

static inline double	calculate_magic_factor(t_data *d)
{
	double	factor;

	factor = d->offset->scale;
	if (factor > 10)
		factor /= 10;
	return (factor);
}

static inline int	is_map_square(double ratio)
{
	double	tolerance;

	tolerance = 0.15;
	return ((ratio >= 1 - tolerance && ratio <= 1 + tolerance));
}
