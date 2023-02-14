/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:01:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/13 22:38:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			do_linear_interpolation_to_get_factor(t_data *d);

void	calculate_default_scale_bonus(t_data *d)
{
	t_scale	*scale;

	scale = d->scale;
	scale->create_t_scale(d);
	scale->calculate_win_factor(d);
	scale->set_target_width(d);
	scale->calculate_default_scale(d);
	scale->set_target_height(d);
}

double	calculate_target_width(t_data *d)
{
	t_scale	*sca;

	sca = d->scale;
	do_linear_interpolation_to_get_factor(d);
	return ((WIN_WDTH - sca->menu_width) * sca->size_factor * sca->win_factor);
}

static inline void	do_linear_interpolation_to_get_factor(t_data *d)
{
	t_scale	*sca;
	double	map_sz;

	sca = d->scale;
	map_sz = d->map->size;
	sca->size_factor = (0.4 + (map_sz - 228) * (0.95 - 0.4) / (180000 - 228));
	if (sca->size_factor > 3.75)
		sca->size_factor = 3.75;
}
