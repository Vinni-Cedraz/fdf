/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_methods_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:40:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/13 16:30:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	initialize_methods_bonus(t_data *d)
{
	d->scale->create_t_scale = &set_t_scale_attributes;
	d->scale->set_target_width = &set_target_width;
	d->scale->set_target_height = &set_target_height;
	d->scale->calculate_win_factor = &calculate_win_factor;
	d->scale->calculate_map_size_factor = &calculate_map_sz_factor;
}
