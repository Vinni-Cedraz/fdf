/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_center_aux_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:12:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/02 13:25:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	set_t_center_coordinates(t_center *d, t_n *central_node)
{
	d->x = central_node->point.x;
	d->y = central_node->point.y;
	d->z = central_node->point.z;
}

inline int	is_height_even(int height)
{
	return (!(height & 1));
}

inline int	is_width_even(int width)
{
	return (!(width & 1));
}

inline int	are_height_and_width_even(t_data *d)
{
	return (is_height_even(d->map->height) && is_width_even(d->map->width));
}

inline void	is_map_vertical(t_data *d)
{
	if (d->map->height > d->map->width)
		d->map->is_vertical = 1;
	else
		d->map->is_vertical = 0;
}
