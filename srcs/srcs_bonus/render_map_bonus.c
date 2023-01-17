/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:03:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/17 17:44:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	render_pentagram(t_data *d);
static void	render_lines_square(t_data *d);
static void	render_lines_cross(t_data *d);
static void	find_center_of_the_map(t_data *d);

void	render_map_bonus(t_data *d, t_short square, t_short cross, t_short pent)
{
	if (square)
		render_lines_square(d);
	else if (cross)
		render_lines_cross(d);
	else if (pent)
		render_pentagram(d);
	find_center_of_the_map(d);
}

static void	render_lines_square(t_data *d)
{
	int		i;
	int		j;
	t_point	p;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			p = d->map->arr[i][j];
			if (j + 1 < d->map->width)
				render_line_bonus(p, d->map->arr[i][j + 1], d);
			if (i + 1 < d->map->height)
				render_line_bonus(p, d->map->arr[i + 1][j], d);
			j++;
		}
		i++;
	}
}

static void	render_lines_cross(t_data *d)
{
	t_short	i;
	t_short	j;
	t_point	p1;

	i = -1;
	j = -1;
	render_lines_square(d);
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			if (j < d->map->width - 1 && i < d->map->height - 1)
			{
				p1 = d->map->arr[i][j];
				render_line_bonus(p1, d->map->arr[i + 1][j + 1], d);
				p1 = d->map->arr[i + 1][j];
				render_line_bonus(p1, d->map->arr[i][j + 1], d);
			}
		}
	}
}

static void	render_pentagram(t_data *d)
{
	t_short	i;
	t_short	j;
	t_point	p1;

	i = -1;
	j = -1;
	while (++i < d->map->height - 3)
	{
		j = -1;
		while (++j < d->map->width - 3)
		{
			p1 = d->map->arr[i + 1][j];
			render_line_bonus(p1, d->map->arr[i + 1][j + 2], d);
			render_line_bonus(p1, d->map->arr[i + 2][j + 2], d);
			p1 = d->map->arr[i + 2][j];
			render_line_bonus(p1, d->map->arr[i][j + 1], d);
			render_line_bonus(p1, d->map->arr[i + 1][j + 2], d);
			p1 = d->map->arr[i][j + 1];
			render_line_bonus(p1, d->map->arr[i + 2][j + 2], d);
		}
	}
}

static void	find_center_of_the_map(t_data *d)
{
	uint				index;
	t_node_with_a_point	*central_node;

	if (d->map->size % 2 == 0)
		index = (d->map->size / 2) + d->map->width / 2;
	else
		index = d->map->size / 2;
	central_node = ft_lstpoint_getby_index(d->map->pts, index);
	d->center.x = central_node->point.x;
	d->center.y = central_node->point.y;
	d->center.z = central_node->point.z;
}
