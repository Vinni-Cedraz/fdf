/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:01:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/24 17:06:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "t_interpolation_bonus.h"

static void			calculate_default_scale(t_data *d);
static void			calculate_size_factor(t_data *d);
static void			set_target_height(t_data *d);
static void			set_target_width(t_data *d);

void	calculate_default_scale_bonus(t_data *d)
{
	d->scale->create_t_scale(d);
	d->scale->calculate_win_factor(d);
	calculate_size_factor(d);
	set_target_width(d);
	calculate_default_scale(d);
	set_target_height(d);
}

static inline void	set_target_width(t_data *d)
{
	double	*target;
	double	real_width;

	target = &d->map->target_width;
	real_width = (WIN_WDTH - d->scale->menu_width);
	*target = (real_width * d->scale->size_factor * d->scale->win_factor);
}

static inline void	calculate_default_scale(t_data *d)
{
	d->scale->default_scale = d->map->target_width / d->map->width;
}

static inline void	calculate_size_factor(t_data *d)
{
	double			*result;
	t_interpolation	inter;

	inter.interpolate = &interpolate_linear;
	inter.normalize_result = &normalize;
	inter.size_delta = 2892800 - 228;
	inter.factor_delta = 5.0 - 0.35;
	inter.current_delta = d->map->size - 1;
	inter.min_factor = 0.35;
	result = &d->scale->size_factor;
	*result = inter.interpolate(inter);
	inter.normalize_result(*result);
}

static inline void	set_target_height(t_data *d)
{
	d->map->target_height = d->map->height * d->scale->default_scale;
}
