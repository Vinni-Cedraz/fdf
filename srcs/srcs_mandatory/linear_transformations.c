/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:21:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 20:57:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	transform_a_point(t_point *old_p, t_matrix *matrix, t_data *d);
static void	calculate_z_scale(t_data *d);

void	linear_transformations(t_data *d, t_matrix *rotation_matrix)
{
	short			i;
	short			j;
	static short	counter;

	if (++counter == 1)
		calculate_z_scale(d);
	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			if (counter == 1)
				if (d->map->arr[i][j].z != 0)
					d->map->arr[i][j].z *= d->scale_z;
			transform_a_point(&d->map->arr[i][j], rotation_matrix, d);
			j++;
		}
		i++;
	}
}

static void	transform_a_point(t_point *old, t_matrix *m, t_data *d)
{
	t_point	*p;
	double	cx;
	double	cy;
	double	cz;

	p = &(t_point){
		1,
		1,
		1,
		1,
	};
	cx = d->cx;
	cy = d->cy;
	cz = d->cz;
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
	d->scale_z = 5 / (z_range / 10);
}
