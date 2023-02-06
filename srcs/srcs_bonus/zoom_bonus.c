/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 22:46:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	zoom_in(t_data *d)
{
	if (d->state == diagonal || d->state == parallel)
		return ;
	zoom_in_method(d);
	d->offset->neutral_zoom = 0;
}

inline void	zoom_out(t_data *d)
{
	if (d->state == diagonal || d->state == parallel)
		return ;
	zoom_out_method(d);
	d->offset->neutral_zoom = 0;
}

void	reset_zoom_from_snapshot(t_data *d)
{
	if (d->offset->neutral_zoom == 1)
		return ;
	reset_zoom_method(d);
	d->offset->neutral_zoom = 1;
}

void	take_zoom_snapshot(t_data *d)
{
	t_n	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.ol.zoom_x = tmp->point.x;
		tmp->point.ol.zoom_y = tmp->point.y;
		tmp->point.ol.zoom_z = tmp->point.z;
		tmp = tmp->next;
	}
}
