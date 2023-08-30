/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_methods_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:42:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:36:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	zoom_in_method(void)
{
	float	centered_origin_x;
	float	centered_origin_y;
	t_n		*tmp;
	t_d		*d;

	d = get_data();
	tmp = d->map->pts;
	while (tmp->next != d->map->pts)
	{
		centered_origin_x = tmp->point.x - d->map->center.x;
		centered_origin_y = tmp->point.y - d->map->center.y;
		tmp->point.x = d->map->center.x + centered_origin_x * 1.1;
		tmp->point.y = d->map->center.y + centered_origin_y * 1.1;
		tmp = tmp->next;
	}
}

inline void	zoom_out_method(void)
{
	float	centered_origin_x;
	float	centered_origin_y;
	t_n		*tmp;
	t_d		*d;

	d = get_data();
	tmp = d->map->pts;
	while (tmp->next != d->map->pts)
	{
		centered_origin_x = tmp->point.x - d->map->center.x;
		centered_origin_y = tmp->point.y - d->map->center.y;
		tmp->point.x = d->map->center.x + centered_origin_x / 1.1;
		tmp->point.y = d->map->center.y + centered_origin_y / 1.1;
		tmp = tmp->next;
	}
}

inline void	reset_zoom_method(void)
{
	t_n	*tmp;
	t_d	*d;

	d = get_data();
	tmp = d->map->pts;
	while (tmp->next != d->map->pts)
	{
		tmp->point.x = tmp->point.ol.zoom_x;
		tmp->point.y = tmp->point.ol.zoom_y;
		tmp->point.z = tmp->point.ol.zoom_z;
		tmp = tmp->next;
	}
}
