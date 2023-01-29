/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_coordinates_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:40:55 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 01:25:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void				assign_coordinate_z(t_data *d);
static double			get_column_position(int map_width, int counter);
static double			get_row_position(int map_width, int counter);
static void				take_snapshot_and_apply_scale(t_point *p, t_data *d);

void	assign_coordinates_bonus(t_data *d)
{
	int					counter;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	counter = 0;
	while (tmp)
	{
		tmp->point.x = get_column_position(d->map->width, counter);
		tmp->point.y = get_row_position(d->map->width, counter);
		take_snapshot_and_apply_scale(&tmp->point, d);
		tmp = tmp->next;
		counter++;
	}
	assign_coordinate_z(d);
}

static inline void	take_snapshot_and_apply_scale(t_point *p, t_data *d)
{
	p->ol.raw.x = p->x;
	p->ol.raw.y = p->y;
	p->x *= d->offset->scale;
	p->y *= d->offset->scale;
}

static inline double	get_column_position(int map_width, int counter)
{
	return (counter % map_width);
}

static inline double	get_row_position(int map_width, int counter)
{
	return ((int)((double)counter / map_width));
}

static inline void	assign_coordinate_z(t_data *d)
{
	char				*buf;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		fscanf(d->tool.fp, "%ms", &buf);
		tmp->point.z = ft_atoi(buf);
		free(buf);
		tmp->point.ol.raw.z = tmp->point.z;
		tmp->point.z *= d->offset->scale;
		tmp->point.color = CYAN;
		tmp = tmp->next;
	}
	rewind(d->tool.fp);
}
