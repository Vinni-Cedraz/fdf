/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:01:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 17:24:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

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
	double	current_map_delta;
	double	map_sz_delta;
	double	factor_delta;
	double	*factor;

	map_sz_delta = 2892800 - 228;
	factor_delta = 5.0 - 0.4;
	current_map_delta = d->map->size - 228;
	factor = &d->scale->size_factor;
	*factor = 0.4 + current_map_delta * factor_delta / map_sz_delta;
	if (*factor >= 2.26)
		*factor = 2.26;
}

static inline void	set_target_height(t_data *d)
{
	d->map->target_height = d->map->height * d->scale->default_scale;
}
