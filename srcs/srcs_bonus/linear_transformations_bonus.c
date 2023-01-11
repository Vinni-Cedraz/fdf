/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_transformations_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 20:58:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			transform_a_point(t_point *old_p, t_matrix *m, t_data *d);
static void			calculate_z_scale(t_data *d);
static void			apply_spherical_projection(t_point *p, t_data *d);
static void			define_radius(t_point *p);

void	linear_transformations_bonus(t_data *d, t_matrix *rot, t_short sphere)
{
	t_short			i;
	t_short			j;
	static short	counter;

	if (!d->state.neutral_zoom)
		zoom_bonus(d, 0, 0, 1);
	if (++counter == 1)
		calculate_z_scale(d);
	i = -1;
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			if (counter == 1)
				if (d->map->pts[i][j].z != 0)
					d->map->pts[i][j].z *= d->offset.scale_z;
			if (sphere)
				apply_spherical_projection(&d->map->pts[i][j], d);
			else if (!sphere)
				transform_a_point(&d->map->pts[i][j], rot, d);
		}
	}
}

static void	transform_a_point(t_point *old, t_matrix *m, t_data *d)
{
	t_point	*p;
	double	cx;
	double	cy;
	double	cz;

	p = &(t_point){1, 1, 1, 1, 1, 1, 1, {1, 1, 1}};
	cx = d->offset.cx;
	cy = d->offset.cy;
	cz = d->offset.cz;
	p->x = old->x - cx;
	p->y = old->y - cy;
	p->z = old->z - cz;
	old->x = p->x * m->row_1.x + p->y * m->row_2.x + p->z * m->row_3.x + cx;
	old->y = p->x * m->row_1.y + p->y * m->row_2.y + p->z * m->row_3.y + cy;
	old->z = p->x * m->row_1.z + p->y * m->row_2.z + p->z * m->row_3.z + cz;
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
	p->x = p->r * cos(p->theta) * cos(p->phi) + cx;
	p->y = p->r * cos(p->theta) * sin(p->phi) + cy;
	p->z = p->r * sin(p->theta) + cz;
}

static inline void	define_radius(t_point *p)
{
	p->r = sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
}
