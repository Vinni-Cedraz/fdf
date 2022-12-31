/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:11:35 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 23:21:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	render_lines(t_point p1, t_point p2, int color, t_data *d);
// static void	render_last_line(t_data *d);
// static void	render_last_column(t_data *d);
static void	put_pixel_img_bonus(t_img *img, int x, int y, int color);

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
			{
				if (j < d->map->width / 2)
					render_lines(d->map->arr[i][j], d->map->arr[i][j + 1],
							d->map->arr[i][j].color, d);
				else
					render_lines(d->map->arr[i][j], d->map->arr[i][j + 1],
							d->map->arr[i][j + 1].color, d);
			}
			if (i < d->map->height - 1)
			{
				if (i < d->map->height / 2)
					render_lines(d->map->arr[i][j], d->map->arr[i + 1][j],
							d->map->arr[i][j].color, d);
				else
					render_lines(d->map->arr[i][j], d->map->arr[i + 1][j],
							d->map->arr[i + 1][j].color, d);
			}
			if (j < d->map->width - 1 && i > 0)
			{
				if (j > d->map->width / 2)
					render_lines(d->map->arr[i][j], d->map->arr[i - 1][j + 1],
							d->map->arr[i][j].color, d);
				else
					render_lines(d->map->arr[i][j], d->map->arr[i - 1][j + 1],
							d->map->arr[i - 1][j + 1].color, d);
			}
			if (i > 0 && j < d->map->width - 1)
			{
				if (i < d->map->height / 2)
					render_lines(d->map->arr[i][j], d->map->arr[i - 1][j + 1],
							d->map->arr[i][j].color, d);
				else
					render_lines(d->map->arr[i][j], d->map->arr[i - 1][j + 1],
							d->map->arr[i - 1][j + 1].color, d);
			}
		}
	}
}

static void	render_lines(t_point p1, t_point p2, int color, t_data *d)
{
	t_line	line;

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
//
// static void	render_last_line(t_data *d)
// {
// 	int	j;
//
// 	j = 0;
// 	while (j < d->map->width - 1)
// 	{
// 		if (j <= d->map->width / 2)
// 			render_lines(d->map->arr[d->map->height - 1][j],
// 								d->map->arr[d->map->height - 1][j + 1],
// 								d->map->arr[d->map->height - 1][j].color,
// 								d);
// 		else
// 			render_lines(d->map->arr[d->map->height - 1][j],
// 								d->map->arr[d->map->height - 1][j + 1],
// 								d->map->arr[d->map->height - 1][j + 1].color,
// 								d);
// 		j++;
// 	}
// }
//
// static void	render_last_column(t_data *d)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < d->map->height - 1)
// 	{
// 		if (i < d->map->height - 1)
// 			render_lines(d->map->arr[i][d->map->width - 1],
// 								d->map->arr[i + 1][d->map->width - 1],
// 								d->map->arr[i + 1][d->map->width - 1].color,
// 								d);
// 		i++;
// 	}
// }
