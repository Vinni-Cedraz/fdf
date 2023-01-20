/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/17 15:37:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static int	is_colorized(t_data *d);

void	colorize_points_bonus(t_data *d)
{
	t_node_with_a_point	*tmp;
	double				tolerance;

	if (is_colorized(d))
		return ;
	tolerance = 0.1;
	tmp = d->map->pts;
	while (tmp)
	{
		if (tmp->point.z == 0)
			tmp->point.color = WHITE;
		else if (tmp->point.z == d->map->min_z)
			tmp->point.color = BLUE;
		else if (tmp->point.z < 0)
			tmp->point.color = RED;
		else if (tmp->point.z > d->map->max_z - tolerance)
			tmp->point.color = MAGENTA;
		else if (tmp->point.z > 0)
			tmp->point.color = CYAN;
		tmp = tmp->next;
	}
}

static int	is_colorized(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		if (tmp->point.color != CYAN)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
