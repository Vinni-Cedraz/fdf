/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:03:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/26 12:57:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	render_pentagram(t_data *d);
static void	render_lines_square(t_data *d);
static void	render_lines_cross(t_data *d);

void	render_map_bonus(t_data *d, int square, int cross, int pent)
{
	if (square)
		render_lines_square(d);
	else if (cross)
		render_lines_cross(d);
	else if (pent)
		render_pentagram(d);
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
	int		i;
	int		j;
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
	int		i;
	int		j;
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
