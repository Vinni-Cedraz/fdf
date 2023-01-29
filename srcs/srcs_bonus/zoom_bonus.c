/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 16:56:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	zoom_in(t_data *d)
{
	d->state.zoom_in++;
	if (d->state.diagonal || d->state.parallel)
		return ;
	zoom_in_method(d);
	update_state_after_zoom(d);
}

inline void	zoom_out(t_data *d)
{
	d->state.zoom_out++;
	if (d->state.diagonal || d->state.parallel)
		return ;
	zoom_out_method(d);
	update_state_after_zoom(d);
}

void	reset_zoom_from_snapshot(t_data *d)
{
	if (d->state.neutral_zoom == 1)
		return ;
	reset_zoom_method(d);
	update_state_after_reset(d);
}

void	take_zoom_snapshot(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.ol.zoom_x = tmp->point.x;
		tmp->point.ol.zoom_y = tmp->point.y;
		tmp->point.ol.zoom_z = tmp->point.z;
		tmp = tmp->next;
	}
}
