/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/10 12:02:34 by vcedraz-         ###   ########.fr       */
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
	get_xy_range_bonus(d);
	get_phi_and_theta(d);
	colorize_points(d);
	define_rotation_matrices_bonus(d->matrix);
	printf("%f\n", d->offset->move_x);
}
