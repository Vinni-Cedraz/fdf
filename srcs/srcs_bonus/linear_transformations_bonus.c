/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_transformations_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 20:58:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	transform_a_point(t_point *old_p, t_matrix *matrix, t_data *d);

void	linear_transformations_bonus(t_data *d, t_matrix *rotation_matrix)
{
	int	i;
	int	j;

	if (!d->state.neutral_zoom)
		zoom_bonus(d, 0, 0, 1);
	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			transform_a_point(&d->map->pts[i][j], rotation_matrix, d);
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

	p = &(t_point){1, 1, 1, 1, {1, 1, 1}};
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
