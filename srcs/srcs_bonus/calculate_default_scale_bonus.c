/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:32:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/12 21:48:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			calculate_target_width(t_data *d);
static void			calculate_target_height(t_data *d);
static void			calculate_initial_offset(t_data *d);
static void			is_map_square(t_data *d);

void	calculate_default_scale_bonus(t_data *d)
{
	is_map_square(d);
	is_map_vertical(d->map);
	calculate_target_width(d);
	d->offset->scale = d->map->target_width / d->map->width;
	calculate_target_height(d);
	d->map->radius *= d->offset->scale;
	calculate_initial_offset(d);
}

static inline void	calculate_target_width(t_data *d)
{
	d->map->target_width = WIN_HGHT * 0.9;
	if (d->map->size >= 100000)
		d->map->target_width = WIN_HGHT * 1.9;
	if (d->map->is_vertical)
		d->map->target_width = WIN_HGHT * 0.7;
}

static inline void	calculate_target_height(t_data *d)
{
	if (d->map->is_square)
		d->map->target_height = d->map->target_width;
	else
		d->map->target_height = d->map->height * d->offset->scale;
}

static inline void	calculate_initial_offset(t_data *d)
{
	double	x_offset;
	double	y_offset;

	x_offset = ((double)WIN_WDTH - d->map->target_width + d->menu_width) / 2;
	y_offset = ((double)WIN_HGHT - d->map->target_height) / 2;
	d->offset->move_x = x_offset;
	d->offset->move_y = y_offset;
	d->offset->initial_move_x = x_offset;
	d->offset->initial_move_y = y_offset;
}

static inline void	is_map_square(t_data *d)
{
	double	tolerance;
	double	ratio;
	int		*s;

	s = &d->map->is_square;
	ratio = d->map->ratio;
	tolerance = 0.15;
	*s = ((ratio >= 1 - tolerance && ratio <= 1 + tolerance));
}
