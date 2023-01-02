/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_transformations_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:49:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 01:30:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	transform_a_point(t_point *point, t_matrix *matrix);

void	linear_transformations_bonus(t_point **point, t_matrix *rotation_matrix)
{
	int	i;
	int	j;

	i = 0;
	while (point[i])
	{
		j = 0;
		while (j < point[i][0].x)
		{
			transform_a_point(&point[i][j], rotation_matrix);
			j++;
		}
		i++;
	}
}

//multiplies a given point by a given matrix
static void	transform_a_point(t_point *point, t_matrix *mat)
{
	t_point	*p;

	p = point;
	while (p)
	{
		p->x = p->x * mat->row_1.x + p->y * mat->row_2.x + p->z * mat->row_3.x;
		p->y = p->x * mat->row_1.y + p->y * mat->row_2.y + p->z * mat->row_3.y;
		p->z = p->x * mat->row_1.z + p->y * mat->row_2.z + p->z * mat->row_3.z;
	}
}
