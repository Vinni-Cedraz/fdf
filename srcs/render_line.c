/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:14:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/03 14:25:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static	void	bressenham(t_line *line, t_img *img, int color);

void	render_line(t_point point_a, t_point point_b, int color, t_img *img)
{
	t_line	line;

	line.sx = 0;
	line.sy = 0;
	line.x0 = point_a.x;
	line.y0 = point_a.y;
	line.x1 = point_b.x;
	line.y1 = point_b.y;
	line.color = color;
	line.xdif = abs(line.x1 - line.x0);
	line.ydif = abs(line.y1 - line.y0);
	if (line.x0 < line.x1)
		line.sx = 1;
	else
		line.sx = -1;
	bressenham(&line, img, line.color);
}

static	void	bressenham(t_line *line, t_img *img, int color)
{
	int	p;

	p = 2 * line->ydif - line->xdif;
	while (line->x0 != line->x1)
	{
		put_pixel_img(img, line->x0, line->y0, color);
		if (p >= 0)
		{
			line->y0 += line->sy;
			p -= 2 * line->xdif;
		}
		line->x0 += line->sx;
		p += 2 * line->ydif;
	}
}
