/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpts_with_given_matrix_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/28 16:20:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void					calculate_z_scale(void);
static t_emporary			move_center_to_origin(t_point *p);
static void					move_center_back_to_place(t_point *p);

void	transpts_with_given_matrix_bonus(t_matrix *rot)
{
	t_data	*d;

	d = get_data();
	if (d->state != isometric)
		calculate_z_scale();
	if (d->state != spherical)
		get_xyz_range_bonus();
	d->map->get_map_center();
	multi_threaded_workers((t_worker_task){
		.rot = *rot,
		.action = transform_a_point,
	});
}

void	*transform_a_point(t_worker_task *task)
{
	t_emporary	t;
	t_matrix	m;
	t_data		*d;
	t_point		***arr;

	d = get_data();
	arr = d->map->arr;
	m = task->rot;
	if (d->state == parallel && arr[task->row][task->col]->z)
		arr[task->row][task->col]->z *= d->scale->altitude_factor;
	t = move_center_to_origin(task->p);
	task->p->x = t.x * m.row_1.a + t.y * m.row_2.a + t.z * m.row_3.a;
	task->p->y = t.x * m.row_1.b + t.y * m.row_2.b + t.z * m.row_3.b;
	task->p->z = t.x * m.row_1.c + t.y * m.row_2.c + t.z * m.row_3.c;
	move_center_back_to_place(task->p);
	return (NULL);
}

static inline t_emporary	move_center_to_origin(t_point *p)
{
	t_emporary	t;
	t_data		*d;

	d = get_data();
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

static inline void	move_center_back_to_place(t_point *p)
{
	t_data	*d;

	d = get_data();
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
}

static inline void	calculate_z_scale(void)
{
	float	z_range;
	float	z_factor;
	t_scale	*sca;
	t_data	*d;

	d = get_data();
	sca = d->scale;
	z_range = d->map->max_z - d->map->min_z;
	z_factor = sca->size_factor;
	if (z_factor > 1)
		z_factor = 1;
	sca->altitude_factor = (100 * z_factor) / (z_range * 1.2);
	if (d->map->is_plateau)
		sca->altitude_factor = 1;
}
