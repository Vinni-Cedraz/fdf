/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_ways_to_isometry_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:23:40 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/30 21:51:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	go_through_each_stage_of_isometric_transform(t_data *d)
{
	if (!d->state.out_of_position)
		go_isometric_from_any(d, &loop_through_each_transition_method);
}

void	move_back_to_isometric_state(t_data *d)
{
	if (d->state.out_of_position)
		go_isometric_from_any(d, &go_isometric_from_state_out_of_position);
}

void	go_isometric_from_any(t_data *d, t_func_ptr isometry_method)
{
	isometry_method(d);
	if (d->state.isometric)
		take_snapshot(d);
}
