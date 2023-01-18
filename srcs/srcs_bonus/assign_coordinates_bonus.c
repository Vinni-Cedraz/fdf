/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_coordinates_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:40:55 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/17 21:25:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static inline void	assign_coordinates_xy(t_n *map, short width, double scale);
static inline void	assign_coordinate_z(t_n *map, double scale, FILE *fp);

void	assign_coordinates_bonus(t_data *d)
{
	assign_coordinates_xy(d->map->pts, d->map->width, d->offset.scale);
	assign_coordinate_z(d->map->pts, d->offset.scale, d->tool.fp);
}

static inline void	assign_coordinates_xy(t_n *map, short w, double scale)
{
	int					counter;
	short				map_width;
	t_node_with_a_point	*tmp;

	tmp = map;
	counter = 0;
	map_width = w;
	while (tmp)
	{
		tmp->point.x = counter % map_width;
		tmp->point.y = (int)((double)counter / map_width);
		tmp->point.ol.raw.y = tmp->point.y;
		tmp->point.ol.raw.x = tmp->point.x;
		tmp->point.x *= scale;
		tmp->point.y *= scale;
		tmp = tmp->next;
		counter++;
	}
}

static inline void	assign_coordinate_z(t_n *map, double scale, FILE *fp)
{
	char				*buf;
	t_node_with_a_point	*tmp;

	tmp = map;
	while (tmp)
	{
		fscanf(fp, "%ms", &buf);
		tmp->point.z = ft_atoi(buf);
		free(buf);
		tmp->point.ol.raw.z = tmp->point.z;
		tmp->point.z *= scale;
		tmp->point.color = CYAN;
		tmp = tmp->next;
	}
	rewind(fp);
}
