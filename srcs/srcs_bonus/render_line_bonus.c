/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:55:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/24 16:23:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static int			is_dark_side_of_a_sphere(t_point p, t_point p2);
static void			move_line(t_line *line);
static void			put_pixel(t_img *img, t_line l, t_ui color);
int					max_steps(int dx, int dy);

// lcolor and init_ln are methods defined in t_line_bonus.h
void	render_line_bonus(t_point p1, t_point p2)
{
	t_line			line;
	unsigned int	color;

	if (is_dark_side_of_a_sphere(p1, p2))
		return ;
	lcolor(p1, p2, &color);
	line = init_ln(p1, p2);
	while (line.steps--)
	{
		put_pixel(get_data()->img, line, color);
		move_line(&line);
	}
}

static void	put_pixel(t_img *img, t_line l, t_ui color)
{
	char	*ptr_to_color;
	int		y_offset;
	int		x_offset;

	y_offset = (int)l.y * img->line_len;
	x_offset = (int)l.x * (img->bpp / 8);
	if (l.x < 0 || l.x >= img->width || l.y < 0 || l.y >= img->height)
		return ;
	ptr_to_color = img->addr + y_offset + x_offset;
	*(unsigned int *)ptr_to_color = color;
}

inline int	max_steps(int dx, int dy)
{
	int	steps;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	return (steps);
}

static inline void	move_line(t_line *line)
{
	line->x += line->x_inc;
	line->y += line->y_inc;
}

static inline int	is_dark_side_of_a_sphere(t_point p, t_point p2)
{
	double	dark_side;
	t_data	*d;

	d = get_data();
	dark_side = d->map->max_z * 0.01;
	if (d->state == spherical && p.z < dark_side && p2.z < dark_side)
		return (1);
	return (0);
}
