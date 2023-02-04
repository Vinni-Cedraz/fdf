/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/04 18:47:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	get_xy_range(t_data *d);

void	data_initializer_bonus(t_data *d)
{
	open_win_and_img_bonus(d);
	d->state = (t_state){0, 0, 0, 1};
	initialize_lookup_structs_bonus(d);
	get_altitude_range_bonus(d->map);
	get_xy_range(d);
	get_phi_and_theta(d);
	colorize_points_bonus(d);
	define_rotation_matrices_bonus(d->matrix);
	d->map->get_center = &find_map_center;
}

static void	get_xy_range(t_data *d)
{
	get_max_x(d);
	get_max_y(d);
	get_min_x(d);
	get_min_y(d);
}
