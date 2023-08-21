/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_coordinates_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:40:55 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:21:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void				assign_coordinate_z(void);
static double			get_column_position(int map_width, int counter);
static double			get_row_position(int map_width, int counter);

void	assign_coordinates_bonus(void)
{
	int		counter;
	t_data	*d;
	t_n		*tmp;

	counter = 0;
	d = get_data();
	tmp = d->map->pts;
	while (tmp->next != d->map->pts)
	{
		tmp->point.x = get_column_position(d->map->width, counter);
		tmp->point.y = get_row_position(d->map->width, counter);
		tmp = tmp->next;
		counter++;
	}
	assign_coordinate_z();
}

static inline double	get_column_position(int map_width, int counter)
{
	return (counter % map_width);
}

static inline double	get_row_position(int map_width, int counter)
{
	return ((int)((double)counter / map_width));
}

static inline void	assign_coordinate_z(void)
{
	char	*buf;
	t_n		*tmp;
	t_data	*d;

	d = get_data();
	tmp = d->map->pts;
	while (tmp->next != d->map->pts)
	{
		fscanf(d->tool.fp, "%ms", &buf);
		tmp->point.z = ft_atoi(buf);
		free(buf);
		tmp->point.color = CYAN;
		tmp = tmp->next;
	}
	rewind(d->tool.fp);
}
