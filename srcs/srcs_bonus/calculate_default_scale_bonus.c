/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:01:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/13 21:26:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static double			do_linear_interpolation_to_get_factor(double size);

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
	double	size_factor;
	double	win_factor;
	t_scale	sca;

	sca = *d->scale;
	win_factor = sca.win_factor;
	size_factor = do_linear_interpolation_to_get_factor(d->map->size);
	return ((WIN_WDTH - sca.menu_width) * size_factor * win_factor);
}

static inline double	do_linear_interpolation_to_get_factor(double size)
{
	return (0.4 + (size - 228) * (0.95 - 0.4) / (180000 - 228));
}
