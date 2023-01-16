/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_altitude_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/13 00:39:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	scale_z(t_data *d, t_short up, t_short down, t_short mirror);

void	change_altitude_bonus(t_data *d, t_short up, t_short mirror)
{
	get_altitude_range_bonus(d->map);
	if (!d->state.isometric)
		return ;
	if (!d->state.neutral_zoom)
		zoom_bonus(d, 0, 0, 1);
	if (up && d->map->max_z >= 500)
		return ;
	if (up && abs(d->map->min_z) >= 500)
		return ;
	else
		two_steps_to_isometry_bonus(d, 1, 0);
	if (up)
		scale_z(d, 1, 0, 0);
	else if (mirror)
		scale_z(d, 0, 0, 1);
	else if (!up)
		scale_z(d, 0, 1, 0);
	two_steps_to_isometry_bonus(d, 0, 0);
}

static void	scale_z(t_data *d, t_short up, t_short down, t_short mirror)
{
	t_point				*p;
	t_node_with_a_point	*node;

	node = d->map->pts;
	while (node)
	{
		p = &node->point;
		if (up && p->z != 0)
			p->z *= 1.1;
		if (down && p->z != 0)
			p->z /= 1.1;
		if (mirror && p->z != 0)
			p->z *= -1;
		node = node->next;
	}
}
