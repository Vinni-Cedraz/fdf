/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_default_scale_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:32:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/13 16:29:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	calculate_default_scale_bonus(t_data *d)
{
	t_scale	*scale;

	scale = d->scale;
	scale->create_t_scale(d);
	scale->calculate_win_factor(d);
	scale->set_target_width(d);
	scale->calculate_map_size_factor(d);
	scale->set_target_height(d);
}

double	calculate_target_width(t_data *d)
{
	return ((WIN_WDTH - d->scale->menu_width) * 0.5 * d->scale->win_factor);
}
