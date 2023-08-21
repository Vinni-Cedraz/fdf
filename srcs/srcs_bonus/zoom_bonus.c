/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:38:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:36:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	zoom_in(void)
{
	t_data	*d;

	d = get_data();
	if (d->state == diagonal || d->state == parallel)
		return ;
	zoom_in_method();
	d->offset->neutral_zoom = 0;
}

inline void	zoom_out(void)
{
	t_data	*d;

	d = get_data();
	if (d->state == diagonal || d->state == parallel)
		return ;
	zoom_out_method();
	d->offset->neutral_zoom = 0;
}

void	reset_zoom_from_snapshot(void)
{
	t_data	*d;

	d = get_data();
	if (d->offset->neutral_zoom == 1)
		return ;
	reset_zoom_method();
	d->offset->neutral_zoom = 1;
}

void	take_zoom_snapshot(void)
{
	t_n		*tmp;
	t_data	*d;

	d = get_data();
	tmp = d->map->pts;
	while (tmp->next != d->map->pts)
	{
		tmp->point.ol.zoom_x = tmp->point.x;
		tmp->point.ol.zoom_y = tmp->point.y;
		tmp->point.ol.zoom_z = tmp->point.z;
		tmp = tmp->next;
	}
}
