/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xy_range_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:57:43 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 19:06:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static double			get_max_x(t_n *node);
static double			get_min_x(t_n *node);
static double			get_max_y(t_n *node);
static double			get_min_y(t_n *node);

void	get_xy_range_bonus(t_data *d)
{
	t_n	*node;

	node = d->map->pts;
	d->map->max_x = get_max_x(node);
	d->map->min_x = get_min_x(node);
	d->map->max_y = get_max_y(node);
	d->map->min_y = get_min_y(node);
}

static inline double	get_max_x(t_n *node)
{
	double	max;

	max = node->point.x;
	while (node)
	{
		if (node->point.x > max)
			max = node->point.x;
		node = node->next;
	}
	return (max);
}

static inline double	get_min_x(t_n *node)
{
	double	min;

	min = node->point.x;
	while (node)
	{
		if (node->point.x < min)
			min = node->point.x;
		node = node->next;
	}
	return (min);
}

static inline double	get_max_y(t_n *node)
{
	double	max;

	max = node->point.y;
	while (node)
	{
		if (node->point.y > max)
			max = node->point.y;
		node = node->next;
	}
	return (max);
}

static inline double	get_min_y(t_n *node)
{
	double	min;

	min = node->point.y;
	while (node)
	{
		if (node->point.y < min)
			min = node->point.y;
		node = node->next;
	}
	return (min);
}
