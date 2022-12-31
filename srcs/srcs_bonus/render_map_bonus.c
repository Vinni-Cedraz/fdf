/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:11:35 by vcedraz-          #+#    #+#             */
/*   UpdatedG 2022/12/31 13:21:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	render_lines_square(t_data *d);
static void	render_lines_cross(t_data *d);

void	render_map_bonus(t_data *d, int square, int cross)
{
	if (square)
		render_lines_square(d);
	else if (cross)
		render_lines_cross(d);
}

static void	render_lines_square(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			if (j < d->map->width - 1)
				render_line_bonus(d->map->arr[i][j], d->map->arr[i][j + 1], d);
			if (i < d->map->height - 1)
				render_line_bonus(d->map->arr[i][j], d->map->arr[i + 1][j], d);
		}
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
