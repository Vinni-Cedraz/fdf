/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_transformations_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 14:23:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	transform_a_point(t_point *old_p, t_matrix *matrix);

void	linear_transformations_bonus(t_data *d, t_matrix *rotation_matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			transform_a_point(&d->map->pts[i][j], rotation_matrix);
			j++;
		}
		i++;
	}
}

static void	transform_a_point(t_point *old, t_matrix *m)
{
	t_point	*p;

	p = &(t_point){1, 1, 1, 1};
	p->x = old->x * m->row_1.x + old->y * m->row_1.y + old->z * m->row_1.z;
	p->y = old->x * m->row_2.x + old->y * m->row_2.y + old->z * m->row_2.z;
	p->z = old->x * m->row_3.x + old->y * m->row_3.y + old->z * m->row_3.z;
	old->x = p->x;
	old->y = p->y;
	old->z = p->z;
}
