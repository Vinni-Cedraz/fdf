/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:27:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 02:05:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_BONUS_H
# define T_POINT_BONUS_H

# include <math.h>
# include <stdlib.h>

typedef struct s_nd		t_node_with_a_point;
typedef struct s_d		t_data;
typedef struct s_pt		t_point;

typedef double			t_d;
static uint				rgb_to_int(t_d r, t_d g, t_d b) __attribute__((unused));
static void				hsv_to_rgb(t_d h, t_d s, t_d v,
							uint *rgb) __attribute__((unused));

typedef struct s_raw
{
	short				x;
	short				y;
	short				z;
}						t_raw;

typedef struct s_origin
{
	double				x;
	double				y;
	double				z;
	double				zoom_x;
	double				zoom_y;
	double				zoom_z;
	t_raw				raw;
}						t_snapshot;

typedef struct s_phere
{
	double				phi;
	double				theta;
	double				r;
}						t_sphere;

typedef struct s_pt
{
	double				x;
	double				y;
	double				z;
	unsigned int		color;
	t_sphere			ball;
	t_snapshot			ol;
	void				(*define_color_by_altitude)(t_point *p, t_data *d);
}						t_point;

static unsigned int	rgb_to_int(double r, double g, double b)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = (unsigned int)(r * 255);
	green = (unsigned int)(g * 255);
	blue = (unsigned int)(b * 255);
	return ((red << 16) | (green << 8) | blue);
}

typedef struct s_nd
{
	t_point				point;
	t_node_with_a_point	*next;
}						t_node_with_a_point;

typedef struct s_rgb
{
	double				r;
	double				g;
	double				b;
}						t_rgb;

static inline void	hsv_to_rgb(double h, double s, double v, uint *rgb)
{
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	i = (int)floor(h / 60) % 6;
	f = h / 60 - i;
	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));
	t_rgb RGB_MAP[] = {
		{v, t, p},
		{q, v, p},
		{p, v, t},
		{p, q, v},
		{t, p, v},
		{v, p, q}};
	*rgb = rgb_to_int(RGB_MAP[i].r, RGB_MAP[i].g, RGB_MAP[i].b);
}

#endif
