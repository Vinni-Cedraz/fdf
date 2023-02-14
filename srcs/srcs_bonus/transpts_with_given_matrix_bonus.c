/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpts_with_given_matrix_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 19:57:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void					transform_a_point(t_point *p, t_matrix *m, t_d *d);
static void					calculate_z_scale(t_data *d);
static t_emporary			move_center_to_origin(t_point *p, t_data *d);
static t_point				*move_center_back_to_place(t_point *p, t_data *d);

void	transpts_with_given_matrix_bonus(t_data *d, t_matrix *rot)
{
	t_n	*tmp;

	tmp = d->map->pts;
	if (d->state != isometric)
		calculate_z_scale(d);
	if (d->state != spherical)
		get_altitude_range_bonus(d->map);
	while (tmp)
	{
		if (d->state == parallel && tmp->point.z)
			tmp->point.z *= d->scale->altitude_factor;
		transform_a_point(&tmp->point, rot, d);
		tmp = tmp->next;
	}
}

static inline void	transform_a_point(t_point *p, t_matrix *m, t_data *d)
{
	t_emporary	t;

	d->map->get_map_center(d);
	t = move_center_to_origin(p, d);
	p->x = t.x * m->row_1.a + t.y * m->row_2.a + t.z * m->row_3.a;
	p->y = t.x * m->row_1.b + t.y * m->row_2.b + t.z * m->row_3.b;
	p->z = t.x * m->row_1.c + t.y * m->row_2.c + t.z * m->row_3.c;
	p = move_center_back_to_place(p, d);
}

static inline t_emporary	move_center_to_origin(t_point *p, t_data *d)
{
	t_emporary	t;

	if (d->state == spherical)
	{
		t.x = p->x - d->map->ball.center_x;
		t.y = p->y - d->map->ball.center_y;
		t.z = p->z - d->map->ball.center_z;
	}
	else
	{
		t.x = p->x - d->map->center.x;
		t.y = p->y - d->map->center.y;
		t.z = p->z - d->map->center.z;
	}
	return (t);
}

static inline t_point	*move_center_back_to_place(t_point *p, t_d *d)
{
	if (d->state == spherical)
	{
		p->x += d->map->ball.center_x;
		p->y += d->map->ball.center_y;
		p->z += d->map->ball.center_z;
	}
	else
	{
		p->x += d->map->center.x;
		p->y += d->map->center.y;
		p->z += d->map->center.z;
	}
	return (p);
}

static inline void	calculate_z_scale(t_data *d)
{
	double	z_range;
	double	z_factor;
	t_scale	*sca;

	sca = d->scale;
	z_range = d->map->max_z - d->map->min_z;
	z_factor = sca->size_factor;
	if (z_factor > 1)
		z_factor = 1;
	sca->altitude_factor = (100 * z_factor) / (z_range * 1.2);
	if (d->map->is_plateau)
		sca->altitude_factor = 1;
}
