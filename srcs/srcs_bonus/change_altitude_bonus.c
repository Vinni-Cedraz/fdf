/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_altitude_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/19 20:54:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	scale_z(t_data *d, t_short up, t_short down, t_short mirror);

void	change_altitude_bonus(t_data *d, t_short up, t_short mirror)
{
	get_altitude_range_bonus(d->map);
	if (!d->state.isometric)
		return ;
	if (!d->state.neutral_zoom)
		zoom_bonus(d, 0, 0, 1);
	if (up && d->map->max_z >= 450)
		return ;
	if (up && abs(d->map->min_z) >= 450)
		return ;
	if (up)
		scale_z(d, 1, 0, 0);
	else if (mirror)
		scale_z(d, 0, 0, 1);
	else if (!up)
		scale_z(d, 0, 1, 0);
}

static void	scale_z(t_data *d, t_short up, t_short down, t_short mirror)
{
	if (up)
		linear_transformations_bonus(d, &d->matrix->change_altitude_up, 0);
	else if (down)
		linear_transformations_bonus(d, &d->matrix->change_altitude_down, 0);
	else if (mirror)
		linear_transformations_bonus(d, &d->matrix->change_altitude_mirror, 0);
}
