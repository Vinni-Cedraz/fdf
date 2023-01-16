/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:55:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/16 01:23:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	determine_line_color(t_point p1, t_point p2, unsigned int *color);
static void	put_pixel_img_bonus(t_img *img, int x, int y, unsigned int color);

void	render_line_bonus(t_point p1, t_point p2, t_data *d)
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
	line.x_inc = line.dx / (double)line.steps;
	line.y_inc = line.dy / (double)line.steps;
	line.x = p1.x + d->offset.move_x;
	line.y = p1.y + d->offset.move_y;
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

static void	determine_line_color(t_point p1, t_point p2, unsigned int *color)
{
	if (fabs(p1.z) < fabs(p2.z))
		*color = p1.color;
	else if (fabs(p1.z) > fabs(p2.z))
		*color = p2.color;
	else if (p1.ol.z < p2.ol.z)
		*color = p1.color;
	else if (p1.ol.z > p2.ol.z)
		*color = p2.color;
	else
		*color = p1.color;
}
