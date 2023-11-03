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
static t_ln			init_ln(t_p *p1, t_p *p2) __attribute__((unused));
static void			lcolor(t_p *p1, t_p *p2, t_ui *c) __attribute__((unused));

typedef struct s_l
{
	float				x;
	float				y;
	t_point				tmp;
	float				slope;
	int					delta_x;
	int					delta_y;
	unsigned int		color;
}						t_line;

static void	lcolor(t_point *p1, t_point *p2, t_ui *color)
{
	if (p1->color == p2->color)
		*color = p1->color;
	else if (p1->ol.raw.z < p2->ol.raw.z)
		*color = p1->color;
	else
		*color = p2->color;
}

static inline t_line	init_ln(t_point *p1, t_point *p2)
{
	t_line	line;

	line.delta_x = p2->x - p1->x;
	line.delta_y = p2->y - p1->y;
	if (abs(line.delta_x) > abs(line.delta_y))
		line.slope = (float)line.delta_y / line.delta_x;
	else
		line.slope = (float)line.delta_x / line.delta_y;
	lcolor(p1, p2, &line.color);
	line.x = p1->x;
	line.y = p1->y;
	return (line);
}

#endif
