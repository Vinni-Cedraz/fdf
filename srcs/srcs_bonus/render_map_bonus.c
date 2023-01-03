/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:03:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/03 00:34:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	find_center_of_the_img(t_data *d);
static void	render_pentagram(t_data *d);
static void	render_lines_square(t_data *d);
static void	render_lines_cross(t_data *d);

void	render_map_bonus(t_data *d, t_short square, t_short cross, t_short pent)
{
	if (square)
		render_lines_square(d);
	else if (cross)
		render_lines_cross(d);
	else if (pent)
		render_pentagram(d);
	find_center_of_the_img(d);
}

static void	render_lines_square(t_data *d)
{
	t_short	i;
	t_short	j;

	i = -1;
	j = -1;
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			if (j < d->map->width - 1)
				render_line_bonus(d->map->pts[i][j], d->map->pts[i][j + 1], d);
			if (i < d->map->height - 1)
				render_line_bonus(d->map->pts[i][j], d->map->pts[i + 1][j], d);
		}
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
				p1 = d->map->pts[i][j];
				render_line_bonus(p1, d->map->pts[i + 1][j + 1], d);
				p1 = d->map->pts[i + 1][j];
				render_line_bonus(p1, d->map->pts[i][j + 1], d);
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
			p1 = d->map->pts[i + 1][j];
			render_line_bonus(p1, d->map->pts[i + 1][j + 2], d);
			render_line_bonus(p1, d->map->pts[i + 2][j + 2], d);
			p1 = d->map->pts[i + 2][j];
			render_line_bonus(p1, d->map->pts[i][j + 1], d);
			render_line_bonus(p1, d->map->pts[i + 1][j + 2], d);
			p1 = d->map->pts[i][j + 1];
			render_line_bonus(p1, d->map->pts[i + 2][j + 2], d);
		}
	}
}

static void	find_center_of_the_img(t_data *d)
{
	d->offset.cx = d->map->pts[d->map->height / 2][d->map->width / 2].x;
	d->offset.cy = d->map->pts[d->map->height / 2][d->map->width / 2].y;
	d->offset.cz = d->map->pts[d->map->height / 2][d->map->width / 2].z;
}
