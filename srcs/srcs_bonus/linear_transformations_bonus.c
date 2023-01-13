/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_transformations_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 21:50:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			transform_a_point(t_point *p, t_matrix *m, t_data *d);
static void			calculate_z_scale(t_data *d);
static void			apply_spherical_projection(t_point *p, t_data *d);
static void			define_radius(t_point *p);

void	linear_transformations_bonus(t_data *d, t_matrix *rot, t_short sphere)
{
	t_short			i;
	t_short			j;
	static short	counter;

	// if (!d->state.neutral_zoom)
	// 	zoom_bonus(d, 0, 0, 1);
	if (++counter == 1)
		calculate_z_scale(d);
	i = -1;
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			if (counter == 1)
				if (d->map->pts->point.z != 0)
					d->map->pts->point.z *= d->offset.scale_z;
			if (sphere)
				apply_spherical_projection(&d->map->pts->point, d);
			else if (!sphere)
				transform_a_point(&d->map->pts->point, rot, d);
		}
	}
}

static void	transform_a_point(t_point *p, t_matrix *m, t_data *d)
{
	t_emporary	t;

	t.x = p->x - d->offset.cx;
	t.y = p->y - d->offset.cy;
	t.z = p->z - d->offset.cz;
	p->x = t.x * m->row_1.col_1 + t.y * m->row_2.col_1 + t.z * m->row_3.col_1;
	p->y = t.x * m->row_1.col_2 + t.y * m->row_2.col_2 + t.z * m->row_3.col_2;
	p->z = t.x * m->row_1.col_3 + t.y * m->row_2.col_3 + t.z * m->row_3.col_3;
	p->x += d->offset.cx;
	p->y += d->offset.cy;
	p->z += d->offset.cz;
}

static void	calculate_z_scale(t_data *d)
{
	double	z_range;

	z_range = d->map->max_z - d->map->min_z;
	d->offset.scale_z = 5 / (z_range / 10);
}

static void	apply_spherical_projection(t_point *old, t_data *d)
{
	t_point	*p;
	double	cx;
	double	cy;
	double	cz;

	cx = d->offset.cx;
	cy = d->offset.cy;
	cz = d->offset.cz;
	p = old;
	p->x -= cx;
	p->y -= cy;
	p->z -= cz;
	define_radius(p);
	p->x = p->ball.r * cos(p->ball.theta) * cos(p->ball.phi) + cx;
	p->y = p->ball.r * cos(p->ball.theta) * sin(p->ball.phi) + cy;
	p->z = p->ball.r * sin(p->ball.theta) + cz;
}

static inline void define_radius(t_point *p)
{
    p->ball.r = hypot(p->x, hypot(p->y, p->z));
}
