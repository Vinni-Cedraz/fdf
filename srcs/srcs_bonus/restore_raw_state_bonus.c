/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_raw_state_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:14:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 23:25:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	restore_raw_state_bonus(t_data *d)
{
	t_n		*dummy;
	t_n		*map;
	t_scale	scale;
	t_point	p;

	scale = *d->scale;
	dummy = map = d->map->pts;
	while (map->next != dummy)
	{
		p = map->point;
		p.x = p.ol.raw.x;
		p.y = p.ol.raw.y;
		p.z = p.ol.raw.z;
		p.x *= scale.default_scale;
		p.y *= scale.default_scale;
		p.z *= scale.default_scale;
		map->point = p;
		map = map->next;
	}
	d->state = parallel;
}
