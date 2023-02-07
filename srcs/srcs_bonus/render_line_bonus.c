/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:55:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 12:27:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void				set_line_color(t_point p1, t_point p2, t_ui *c);
static int				is_dark_side_of_a_sphere(t_point p2, t_d *d);
static void				move_line(t_line *line);
static t_line			init_line(t_point p1, t_point p2, t_data *d);

void	render_line_bonus(t_point p1, t_point p2, t_data *d)
{
	t_line			line;
	unsigned int	color;

	if (is_dark_side_of_a_sphere(p2, d))
		return ;
	set_line_color(p1, p2, &color);
	line = init_line(p1, p2, d);
	while (line.steps--)
	{
		pixel(d->img, line, color);
		move_line(&line);
	}
}

static inline t_line	init_line(t_point p1, t_point p2, t_data *d)
{
	t_line	line;

	line.delta_x = p2.x - p1.x;
	line.delta_y = p2.y - p1.y;
	line.steps = max_steps(line.delta_x, line.delta_y);
	line.x_inc = line.delta_x / line.steps;
	line.y_inc = line.delta_y / line.steps;
	line.x = p1.x + d->offset->move_x;
	line.y = p1.y + d->offset->move_y;
	return (line);
}

static inline void	move_line(t_line *line)
{
	line->x += line->x_inc;
	line->y += line->y_inc;
}

static void	set_line_color(t_point p1, t_point p2, t_ui *color)
{
	if (p1.color == p2.color)
		*color = p1.color;
	else if (p1.ol.raw.z < p2.ol.raw.z)
		*color = p1.color;
	else
		*color = p2.color;
}

static inline int	is_dark_side_of_a_sphere(t_point p2, t_d *d)
{
	double	dark_side;

	dark_side = d->map->max_z * 0.05;
	if (d->state == spherical && p2.z < dark_side)
		return (1);
	return (0);
}
