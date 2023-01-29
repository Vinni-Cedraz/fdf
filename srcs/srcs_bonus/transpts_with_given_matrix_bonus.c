/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpts_with_given_matrix_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 11:09:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void				transform_a_point(t_point *p, t_matrix *m, t_data *d);
static void				calculate_z_scale(t_data *d);
static t_emporary		move_center_to_origin(t_point *p, t_center *c);
static t_point			*move_center_back_to_place(t_point *p, t_center *c);

void	transpts_with_given_matrix_bonus(t_data *d, t_matrix *rot)
{
	static short		counter;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	if (++counter == 1)
		calculate_z_scale(d);
	if (d->state.neutral_zoom != 1)
		zoom_bonus(d, &restore_zoom_from_snapshot);
	while (tmp)
	{
		if (counter == 1 && tmp->point.z)
			tmp->point.z *= d->offset.scale_z;
		transform_a_point(&tmp->point, rot, d);
		tmp = tmp->next;
	}
}

static inline void	transform_a_point(t_point *p, t_matrix *m, t_data *d)
{
	t_emporary	t;

	t = move_center_to_origin(p, &d->center);
	p->x = t.x * m->row_1.col_1 + t.y * m->row_2.col_1 + t.z * m->row_3.col_1;
	p->y = t.x * m->row_1.col_2 + t.y * m->row_2.col_2 + t.z * m->row_3.col_2;
	p->z = t.x * m->row_1.col_3 + t.y * m->row_2.col_3 + t.z * m->row_3.col_3;
	p = move_center_back_to_place(p, &d->center);
}

static inline t_emporary	move_center_to_origin(t_point *p, t_center *c)
{
	t_emporary	t;

	t.x = p->x - c->x;
	t.y = p->y - c->y;
	t.z = p->z - c->z;
	return (t);
}

static inline t_point	*move_center_back_to_place(t_point *p, t_center *c)
{
	p->x += c->x;
	p->y += c->y;
	p->z += c->z;
	return (p);
}

static inline void	calculate_z_scale(t_data *d)
{
	double	z_range;

	z_range = d->map->max_z - d->map->min_z;
	d->offset.scale_z = 5 / (z_range / 10);
}
