/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:23:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/25 14:30:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	render_line_bns(t_point p1, t_point p2, int color, t_data *fdf)
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
	line.x = p1.x + fdf->move_x + fdf->win_center_x;
	line.y = p1.y + fdf->move_y + fdf->win_center_y;
	while (line.steps--)
	{
		put_pixel_img_bns(fdf->img, line.x, line.y, color);
		line.x += line.x_inc;
		line.y += line.y_inc;
	}
}
