/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_center_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:42:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/26 14:02:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			set_t_center_coordinates(t_center *d, t_n *central_node);
static uint			find_map_center_index(t_data *d);

void	find_map_center_bonus(t_data *d)
{
	uint				index;
	t_node_with_a_point	*central_node;

	index = find_map_center_index(d);
	central_node = ft_lstpoint_getby_index(d->map->pts, index);
	set_t_center_coordinates(&d->center, central_node);
}

static inline uint	find_map_center_index(t_data *d)
{
	uint	index;

	if (d->map->size % 2 == 0)
		index = (d->map->size / 2) + d->map->width / 2;
	else
		index = d->map->size / 2;
	return (index);
}

static inline void	set_t_center_coordinates(t_center *d, t_n *central_node)
{
	d->x = central_node->point.x;
	d->y = central_node->point.y;
	d->z = central_node->point.z;
}
