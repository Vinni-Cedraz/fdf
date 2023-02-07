/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 19:48:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	data_initializer_bonus(t_data *d)
{
	open_win_and_img_bonus(d);
	d->state = parallel;
	d->offset->neutral_zoom = 1;
	initialize_lookup_structs_bonus(d);
	get_altitude_range_bonus(d->map);
	get_phi_and_theta(d);
	colorize_points_bonus(d);
	define_rotation_matrices_bonus(d->matrix);
	d->map->get_center = &find_map_center;
}
