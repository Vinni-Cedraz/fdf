/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_center_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:04:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 13:17:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CENTER_BONUS_H
# define T_CENTER_BONUS_H

# include "fdf_t_data_bonus.h"
# include "fdf_prototypes_bonus.h"

static void	get_map_center(t_data *d)__attribute__((unused));

typedef struct s_ctr
{
	double				x;
	double				y;
	double				z;
	int					index;
}						t_center;

static inline void	get_map_center(t_data *d)
{
	t_n	*central_node;

	vertical_map_center(d);
	horizontal_map_center(d);
	square_map_center(d);
	central_node = ft_lstpoint_getby_index(d->map->pts, d->map->center.index);
	set_t_center_coordinates(&d->map->center, central_node);
}

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

#endif
