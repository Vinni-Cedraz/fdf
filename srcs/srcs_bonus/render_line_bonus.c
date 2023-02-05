/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:55:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 19:52:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			set_line_color(t_point p1, t_point p2, t_ui *c, t_d *d);
static void			put_pixel_img_bonus(t_img *img, int x, int y, t_ui color);
static int			is_behind(t_point p1, t_point p2, t_d *d);

void	render_line_bonus(t_point p1, t_point p2, t_data *d)
{
	t_line			line;
	unsigned int	color;

	set_line_color(p1, p2, &color, d);
	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	line.x_inc = line.dx / (double)line.steps;
	line.y_inc = line.dy / (double)line.steps;
	line.x = p1.x + d->offset->move_x;
	line.y = p1.y + d->offset->move_y;
	while (line.steps--)
	{
		put_pixel_img_bonus(d->img, line.x, line.y, color);
		line.x += line.x_inc;
		line.y += line.y_inc;
	}
}

static void	put_pixel_img_bonus(t_img *img, int x, int y, unsigned int color)
{
	char	*ptr_to_color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	ptr_to_color = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)ptr_to_color = color;
}

static void	set_line_color(t_point p1, t_point p2, t_ui *color, t_data *d)
{
	if (p1.color == p2.color && (!is_behind(p1, p2, d)))
		*color = p1.color;
	else if (!is_behind(p1, p2, d))
	{
		if (p1.ol.raw.z < p2.ol.raw.z)
			*color = p1.color;
		else
			*color = p2.color;
	}
	else if (is_behind(p1, p2, d))
		*color = BLACK;
}

static inline int	is_behind(t_point p1, t_point p2, t_d *d)
{
	double	half_ball;

	half_ball = d->map->max_z / 2;
	if (d->state == spherical && (p1.z < half_ball || p2.z < half_ball))
		return (1);
	return (0);
}
