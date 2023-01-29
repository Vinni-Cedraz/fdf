/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_coordinates_xy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:25:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/28 16:27:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void				apply_scale(t_point *p, t_data *d);
static double			get_column_position(int map_width, int counter);
static double			get_row_position(int map_width, int counter);

void	assign_coordinates_xy(t_data *d)
{
	int					counter;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	counter = 0;
	while (tmp)
	{
		tmp->point.x = get_column_position(d->map->width, counter);
		tmp->point.y = get_row_position(d->map->width, counter);
		apply_scale(&tmp->point, d);
		tmp = tmp->next;
		counter++;
	}
}

static inline void	apply_scale(t_point *p, t_data *d)
{
	p->x *= d->offset.scale;
	p->y *= d->offset.scale;
}

static inline double	get_column_position(int map_width, int counter)
{
	return (counter % map_width);
}

static inline double	get_row_position(int map_width, int counter)
{
	return ((int)((double)counter / map_width));
}
