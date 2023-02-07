/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_line_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:07:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 12:52:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LINE_BONUS_H
# define T_LINE_BONUS_H

# include "fdf_t_data_bonus.h"
# include "t_offset_bonus.h"
# include <math.h>

typedef struct s_l	t_ln;

static int			max_steps(int dx, int dy) __attribute__((unused));
static void			pixel(t_img *i, t_ln l, t_ui c) __attribute__((unused));

typedef struct s_l
{
	double			x;
	double			y;
	double			x_inc;
	double			y_inc;
	double			delta_x;
	double			delta_y;
	unsigned int	color;
	double			steps;
}					t_line;

static inline int	max_steps(int dx, int dy)
{
	int	steps;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	return (steps);
}

static void	pixel(t_img *img, t_line l, t_ui color)
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

#endif
