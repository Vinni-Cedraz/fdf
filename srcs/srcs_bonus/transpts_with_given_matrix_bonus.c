/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpts_with_given_matrix_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/10 16:40:55 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void					transform_a_point(t_point *p, t_matrix *m, t_d *d);
static void					calculate_z_scale(t_data *d);
static t_emporary			move_center_to_origin(t_point *p, t_data *d);
static t_point				*move_center_back_to_place(t_point *p, t_data *d);

void	transpts_with_given_matrix_bonus(t_data *d, t_matrix *rot)
{
	static short	counter;
	t_n				*tmp;

	tmp = d->map->pts;
	if (++counter == 1)
		calculate_z_scale(d);
	if (d->state != spherical)
		get_altitude_range_bonus(d->map);
	while (tmp)
	{
		if (counter == 1 && tmp->point.z)
			tmp->point.z *= d->offset->scale_z;
		transform_a_point(&tmp->point, rot, d);
		tmp = tmp->next;
	}
}

static inline void	transform_a_point(t_point *p, t_matrix *m, t_data *d)
{
	t_emporary	t;

	get_map_center(d);
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

	z_range = d->map->max_z - d->map->min_z;
	d->offset->scale_z = 5 / (z_range / 10);
}
