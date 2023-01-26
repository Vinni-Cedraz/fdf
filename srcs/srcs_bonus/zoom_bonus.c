/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/26 20:26:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			update_state(t_data *d, int snapshot_zoom);

void	zoom_bonus(t_data *d, t_func_ptr zoom_method)
{
	if (d->state.neutral_zoom == 1)
		take_zoom_snapshot(d);
	zoom_method(d);
}

void	zoom_in(t_data *d)
{
	double				centered_origin_x;
	double				centered_origin_y;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	d->state.zoom_in++;
	if ((d->state.zoom_in - d->state.zoom_out) >= 36)
		return ;
	while (tmp)
	{
		centered_origin_x = tmp->point.x - d->center.x;
		centered_origin_y = tmp->point.y - d->center.y;
		tmp->point.x = d->center.x + centered_origin_x * 1.1;
		tmp->point.y = d->center.y + centered_origin_y * 1.1;
		tmp = tmp->next;
	}
	update_state(d, 0);
}

void	zoom_out(t_data *d)
{
	double				centered_origin_x;
	double				centered_origin_y;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	d->state.zoom_out++;
	if ((d->state.zoom_out - d->state.zoom_in) >= 36)
		return ;
	while (tmp)
	{
		centered_origin_x = tmp->point.x - d->center.x;
		centered_origin_y = tmp->point.y - d->center.y;
		tmp->point.x = d->center.x + centered_origin_x / 1.1;
		tmp->point.y = d->center.y + centered_origin_y / 1.1;
		tmp = tmp->next;
	}
	update_state(d, 0);
}

void	restore_zoom_from_snapshot(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	if (d->state.neutral_zoom == 1)
		return ;
	while (tmp)
	{
		tmp->point.x = tmp->point.ol.zoom_x;
		tmp->point.y = tmp->point.ol.zoom_y;
		tmp->point.z = tmp->point.ol.zoom_z;
		tmp = tmp->next;
	}
	update_state(d, 1);
}

static inline void	update_state(t_data *d, int snapshot_zoom)
{
	if (snapshot_zoom)
	{
		d->state.zoom_in = 0;
		d->state.zoom_out = 0;
	}
	if ((d->state.zoom_in - d->state.zoom_out) == 0)
		d->state.neutral_zoom = 1;
	else
		d->state.neutral_zoom = 0;
}
