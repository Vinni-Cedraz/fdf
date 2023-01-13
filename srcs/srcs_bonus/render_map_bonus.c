/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:03:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/13 00:43:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "t_point_bonus.h"

// static void	render_pentagram(t_data *d);
static void	render_lines_list(t_data *d);
// static void	render_lines_cross(t_data *d);
static void	find_center_of_the_map(t_data *d);

void	render_map_bonus(t_data *d, t_short list, t_short cross, t_short pent)
{
	if (list)
		render_lines_list(d);
	else if (cross)
		return ;
	else if (pent)
		return ;
	find_center_of_the_map(d);
}

static void	render_lines_list(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp->next)
	{
		render_line_bonus(tmp->point, tmp->next->point, d);
		tmp = tmp->next;
	}
}
//
// static void	render_lines_cross(t_data *d)
// {
// 	t_short	i;
// 	t_short	j;
// 	t_point	p1;
//
// 	i = -1;
// 	j = -1;
// 	render_lines_list(d);
// 	while (++i < d->map->height)
// 	{
// 		j = -1;
// 		while (++j < d->map->width)
// 		{
// 			if (j < d->map->width - 1 && i < d->map->height - 1)
// 			{
// 				p1 = d->map->pts[i][j];
// 				render_line_bonus(p1, d->map->pts[i + 1][j + 1], d);
// 				p1 = d->map->pts[i + 1][j];
// 				render_line_bonus(p1, d->map->pts[i][j + 1], d);
// 			}
// 		}
// 	}
// }
//
// static void	render_pentagram(t_data *d)
// {
// 	t_short	i;
// 	t_short	j;
// 	t_point	p1;
//
// 	i = -1;
// 	j = -1;
// 	while (++i < d->map->height - 3)
// 	{
// 		j = -1;
// 		while (++j < d->map->width - 3)
// 		{
// 			p1 = d->map->pts[i + 1][j];
// 			render_line_bonus(p1, d->map->pts[i + 1][j + 2], d);
// 			render_line_bonus(p1, d->map->pts[i + 2][j + 2], d);
// 			p1 = d->map->pts[i + 2][j];
// 			render_line_bonus(p1, d->map->pts[i][j + 1], d);
// 			render_line_bonus(p1, d->map->pts[i + 1][j + 2], d);
// 			p1 = d->map->pts[i][j + 1];
// 			render_line_bonus(p1, d->map->pts[i + 2][j + 2], d);
// 		}
// 	}
// }

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
