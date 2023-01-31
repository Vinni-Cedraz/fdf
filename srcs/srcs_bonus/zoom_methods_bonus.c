/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_methods_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:42:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/30 21:48:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	zoom_in_method(t_data *d)
{
	double				centered_origin_x;
	double				centered_origin_y;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		centered_origin_x = tmp->point.x - d->center.x;
		centered_origin_y = tmp->point.y - d->center.y;
		tmp->point.x = d->center.x + centered_origin_x * 1.1;
		tmp->point.y = d->center.y + centered_origin_y * 1.1;
		tmp = tmp->next;
	}
}

inline void	zoom_out_method(t_data *d)
{
	double				centered_origin_x;
	double				centered_origin_y;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		centered_origin_x = tmp->point.x - d->center.x;
		centered_origin_y = tmp->point.y - d->center.y;
		tmp->point.x = d->center.x + centered_origin_x / 1.1;
		tmp->point.y = d->center.y + centered_origin_y / 1.1;
		tmp = tmp->next;
	}
}

inline void	reset_zoom_method(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.x = tmp->point.ol.zoom_x;
		tmp->point.y = tmp->point.ol.zoom_y;
		tmp->point.z = tmp->point.ol.zoom_z;
		tmp = tmp->next;
	}
}

inline void	update_state_after_reset(t_data *d)
{
	d->state.zoom_in = 0;
	d->state.zoom_out = 0;
	d->state.diagonal = 0;
	d->state.parallel = 0;
}

inline void	update_state_after_zoom(t_data *d)
{
	if ((d->state.zoom_in - d->state.zoom_out) == 0)
		d->state.neutral_zoom = 1;
	else
		d->state.neutral_zoom = 0;
}
