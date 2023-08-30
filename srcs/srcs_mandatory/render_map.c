/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/06 22:40:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	determine_line_color(t_point p1, t_point p2, unsigned int *color);
static void	render_line(t_point p1, t_point p2, t_data *d);

void	render_map(t_data *d)
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
				render_line(d->map->arr[i][j], d->map->arr[i][j + 1], d);
			if (i < d->map->height - 1)
				render_line(d->map->arr[i][j], d->map->arr[i + 1][j], d);
		}
	}
}

static void	render_line(t_point p1, t_point p2, t_data *d)
{
	t_line			line;
	unsigned int	color;

	determine_line_color(p1, p2, &color);
	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	line.x_inc = line.dx / (float)line.steps;
	line.y_inc = line.dy / (float)line.steps;
	line.x = p1.x + d->move_x;
	line.y = p1.y + d->move_y;
	while (line.steps--)
	{
		put_pixel_img(d->img, line.x, line.y, color);
		line.x += line.x_inc;
		line.y += line.y_inc;
	}
}

static void	determine_line_color(t_point p1, t_point p2, unsigned int *color)
{
	if (p1.color == p2.color)
		*color = p1.color;
	else
	{
		if (p1.z < p2.z)
			*color = p1.color;
		else
			*color = p2.color;
	}
}
