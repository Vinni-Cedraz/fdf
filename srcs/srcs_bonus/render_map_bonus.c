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

static void	render_line_bonus(t_point p1, t_point p2, t_data *d);
static void	put_pixel_img_bonus(t_img *img, int x, int y, int color);
static void	determine_line_color(t_point p1, t_point p2, int *color);

void	render_map_bonus(t_data *d)
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

static void	render_line_bonus(t_point p1, t_point p2, t_data *d)
{
	t_line	line;
	int		color;

	determine_line_color(p1, p2, &color);
	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	line.x_inc = line.dx / (double)line.steps;
	line.y_inc = line.dy / (double)line.steps;
	line.x = p1.x + d->move_x + d->centralize_img_x;
	line.y = p1.y + d->move_y + d->centralize_img_y;
	while (line.steps--)
	{
		put_pixel_img_bonus(d->img, line.x, line.y, color);
		line.x += line.x_inc;
		line.y += line.y_inc;
	}
}

static void	put_pixel_img_bonus(t_img *img, int x, int y, int color)
{
	char	*ptr_to_color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	ptr_to_color = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)ptr_to_color = color;
}

static void	determine_line_color(t_point p1, t_point p2, int *color)
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
