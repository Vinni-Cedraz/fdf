/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:27:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/23 21:35:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

void	render_line(t_point p1, t_point p2, int color, t_data *fdf)
{
	t_line	line;

	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;
	if (abs(line.dx) > abs(line.dy))
		line.steps = abs(line.dx);
	else
		line.steps = abs(line.dy);
	line.x_inc = line.dx / (float)line.steps;
	line.y_inc = line.dy / (float)line.steps;
	line.x = p1.x + fdf->move_x + fdf->map->center_x;
	line.y = p1.y + fdf->move_y + fdf->map->center_y;
	while (line.steps--)
	{
		put_pixel_img(fdf->img, line.x, line.y, color);
		line.x += line.x_inc;
		line.y += line.y_inc;
	}
}
