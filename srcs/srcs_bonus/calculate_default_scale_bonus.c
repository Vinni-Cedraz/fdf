/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:02:04 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/30 18:02:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "t_interpolation_bonus.h"

static void			calculate_default_scale(void);
static void			calculate_size_factor(void);
static void			set_target_height(void);
static void			set_target_width(void);

void	calculate_default_scale_bonus(void)
{
	get_data()->scale->create_t_scale();
	get_data()->scale->calculate_win_factor();
	calculate_size_factor();
	set_target_width();
	calculate_default_scale();
	set_target_height();
}

static inline void	set_target_width(void)
{
	float	*target;
	float	real_width;
	t_data	*d;

	d = get_data();
	target = &d->map->target_width;
	real_width = (WIN_WDTH - d->scale->menu_width);
	*target = (real_width * d->scale->size_factor * d->scale->win_factor);
}

static inline void	calculate_default_scale(void)
{
	t_data	*d;

	d = get_data();
	d->scale->default_scale = d->map->target_width / d->map->width;
}

static inline void	calculate_size_factor(void)
{
	float			*result;
	t_interpolation	inter;

	inter.interpolate = &interpolate_linear;
	inter.normalize_result = &normalize;
	inter.size_delta = 2892800 - 228;
	inter.factor_delta = 5.0 - 0.35;
	inter.current_delta = get_data()->map->size - 1;
	inter.min_factor = 0.35;
	result = &get_data()->scale->size_factor;
	*result = inter.interpolate(inter);
	inter.normalize_result(*result);
}

static inline void	set_target_height(void)
{
	t_data	*d;

	d = get_data();
	d->map->target_height = d->map->height * d->scale->default_scale;
}
