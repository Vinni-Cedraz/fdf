/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 12:01:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	data_initializer_bonus(void)
{
	open_win_and_img_bonus();
	get_data()->state = parallel;
	get_data()->offset->neutral_zoom = 1;
	initialize_lookup_structs_bonus();
	get_altitude_range_bonus(get_data()->map);
	get_xy_range_bonus();
	ft_lstpoint_iter(get_data()->map->pts, &get_phi_and_theta);
	colorize_points_bonus();
	define_rotation_matrices_bonus(get_data()->matrix);
}
