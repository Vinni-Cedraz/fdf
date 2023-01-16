/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/15 22:42:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "t_point_bonus.h"

// static t_short	is_colorized(t_data *d);

void	colorize_points_bonus(t_data *d)
{
	t_node_with_a_point	*tmp;

	// if (is_colorized(d))
	// 	return ;
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
