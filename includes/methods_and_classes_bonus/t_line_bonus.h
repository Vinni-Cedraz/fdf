/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_line_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:07:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 19:16:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LINE_BONUS_H
# define T_LINE_BONUS_H

# include "fdf_t_data_bonus.h"
# include "t_offset_bonus.h"
# include <math.h>

typedef struct s_l		t_ln;
static t_ln				init_ln(t_p p1, t_p p2, t_d *d) __attribute__((unused));
static void				lcolor(t_p p1, t_p p2, t_ui *c) __attribute__((unused));

typedef struct s_l
{
	double				x;
	double				y;
	double				x_inc;
	double				y_inc;
	double				delta_x;
	double				delta_y;
	unsigned int		color;
	double				steps;
}						t_line;

static void	lcolor(t_point p1, t_point p2, t_ui *color)
{
	if (p1.color == p2.color)
		*color = p1.color;
	else if (p1.ol.raw.z < p2.ol.raw.z)
		*color = p1.color;
	else
		*color = p2.color;
}

static inline t_line	init_ln(t_point p1, t_point p2, t_data *d)
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

#endif
