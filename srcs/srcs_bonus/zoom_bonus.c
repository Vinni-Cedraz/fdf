/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/19 21:26:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			zoom_in(t_data *d);
static void			zoom_out(t_data *d);
static void			snapshot_zoom(t_data *d, int take, int restore);
static void			update_state(t_data *d, int snapshot_zoom);

void	zoom_bonus(t_data *d, int in, int out, int restore)
{
	if (d->state.neutral_zoom)
		snapshot_zoom(d, 1, 0);
	if (in)
	{
		if ((d->state.zoom_in - d->state.zoom_out) >= 36)
			return ;
		zoom_in(d);
	}
	else if (out)
	{
		if ((d->state.zoom_out - d->state.zoom_in) >= 36)
			return ;
		zoom_out(d);
	}
	else if (restore)
		snapshot_zoom(d, 0, 1);
}

static inline void	zoom_in(t_data *d)
{
	double				centered_origin_x;
	double				centered_origin_y;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	d->state.zoom_in++;
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

static inline void	zoom_out(t_data *d)
{
	double				centered_origin_x;
	double				centered_origin_y;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	d->state.zoom_out++;
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

static inline void	snapshot_zoom(t_data *d, int take, int restore)
{
	t_node_with_a_point	*tmp;

	if (d->state.neutral_zoom)
		return ;
	tmp = d->map->pts;
	if (take)
	{
		while (tmp)
		{
			tmp->point.ol.zoom_x = tmp->point.x;
			tmp->point.ol.zoom_y = tmp->point.y;
			tmp->point.ol.zoom_z = tmp->point.z;
			tmp = tmp->next;
		}
	}
	else if (restore)
	{
		while (tmp)
		{
			tmp->point.x = tmp->point.ol.zoom_x;
			tmp->point.y = tmp->point.ol.zoom_y;
			tmp->point.z = tmp->point.ol.zoom_z;
			tmp = tmp->next;
		}
		update_state(d, 1);
	}
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
