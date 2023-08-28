/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpts_with_given_matrix_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:35:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void					calculate_z_scale(void);
static t_emporary			move_center_to_origin(t_point p);
static t_point				move_center_back_to_place(t_point p);

void	transpts_with_given_matrix_bonus(t_matrix *rot)
{
	t_data	*d;

	d = get_data();
	if (d->state != isometric)
		calculate_z_scale();
	if (d->state != spherical)
		get_xyz_range_bonus();
	multi_threaded_iter((t_action_and_idx){
		.rot = *rot,
		.action = transform_a_point,
	});
}

void	*transform_a_point(t_arrpoints_iter *iter)
{
	t_emporary	t;
	t_data		*d;
	t_point		**arr;
	t_matrix	m;

	d = get_data();
	arr = d->map->arr;
	m = iter->rot;
	if (d->state == parallel && arr[iter->row][iter->col].z)
		arr[iter->row][iter->col].z *= d->scale->altitude_factor;
	d->map->get_map_center();
	t = move_center_to_origin(*iter->p);
	iter->p->x = t.x * m.row_1.a + t.y * m.row_2.a + t.z * m.row_3.a;
	iter->p->y = t.x * m.row_1.b + t.y * m.row_2.b + t.z * m.row_3.b;
	iter->p->z = t.x * m.row_1.c + t.y * m.row_2.c + t.z * m.row_3.c;
	*iter->p = move_center_back_to_place(*iter->p);
	return (NULL);
}

static inline t_emporary	move_center_to_origin(t_point p)
{
	t_emporary	t;
	t_data		*d;

	d = get_data();
	if (d->state == spherical)
	{
		t.x = p.x - d->map->ball.center_x;
		t.y = p.y - d->map->ball.center_y;
		t.z = p.z - d->map->ball.center_z;
	}
	else
	{
		t.x = p.x - d->map->center.x;
		t.y = p.y - d->map->center.y;
		t.z = p.z - d->map->center.z;
	}
	return (t);
}

static inline t_point	move_center_back_to_place(t_point p)
{
	t_data	*d;

	d = get_data();
	if (d->state == spherical)
	{
		p.x += d->map->ball.center_x;
		p.y += d->map->ball.center_y;
		p.z += d->map->ball.center_z;
	}
	else
	{
		p.x += d->map->center.x;
		p.y += d->map->center.y;
		p.z += d->map->center.z;
	}
	return (p);
}

static inline void	calculate_z_scale(void)
{
	double	z_range;
	double	z_factor;
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
