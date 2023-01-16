/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/15 21:22:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "t_point_bonus.h"

static void		get_max_altitude(t_data *d);
static void		get_min_altitude(t_data *d);
// static t_short	is_colorized(t_data *d);

void	colorize_points_bonus(t_data *d)
{
	t_node_with_a_point	*tmp;

	// if (is_colorized(d))
	// 	return ;
	get_max_altitude(d);
	get_min_altitude(d);
	tmp = d->map->pts;
	while (tmp)
	{
		if (tmp->point.z < 0)
			tmp->point.color = RED;
		if (tmp->point.z == d->map->min_z)
			tmp->point.color = BLUE;
		else if (tmp->point.z == d->map->max_z)
			d->map->pts->point.color = MAGENTA;
		else if (tmp->point.z > 0)
			tmp->point.color = CYAN;
		else if (tmp->point.z == 0)
			tmp->point.color = LIGHT_GRAY;
		tmp = tmp->next;
	}
}

static void	get_max_altitude(t_data *d)
{
	short				max_z;
	t_node_with_a_point	*tmp;

	max_z = -32768;
	tmp = d->map->pts;
	while (tmp)
	{
		if (tmp->point.z > max_z)
			max_z = tmp->point.z;
		tmp = tmp->next;
	}
	d->map->max_z = max_z;
}

static void	get_min_altitude(t_data *d)
{
	short				min_z;
	t_node_with_a_point	*tmp;

	min_z = d->map->max_z;
	tmp = d->map->pts;
	while (tmp)
	{
		if (tmp->point.z < min_z)
			min_z = tmp->point.z;
		tmp = tmp->next;
	}
	d->map->min_z = min_z;
	printf("%d\n", d->map->min_z);
}
//
// static t_short	is_colorized(t_data *d)
// {
// 	t_node_with_a_point	*tmp;
//
// 	tmp = d->map->pts;
// 	while (tmp)
// 	{
// 		if (tmp->point.color != CYAN)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }
