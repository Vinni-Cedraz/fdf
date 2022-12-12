/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/12 18:26:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	rotate_x(t_point *fdf, int y, int z);
static void	rotate_y(t_point *fdf, int x, int z);
static void	rotate_z(t_point *fdf, int x, int y);

void	rotate_map(t_data *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			rotate_x(&fdf->map->arr[i][j],
				fdf->map->arr[i][j].y,
				fdf->map->arr[i][j].z);
			rotate_y(&fdf->map->arr[i][j],
				fdf->map->arr[i][j].x,
				fdf->map->arr[i][j].z);
			rotate_z(&fdf->map->arr[i][j],
				fdf->map->arr[i][j].x,
				fdf->map->arr[i][j].y);
			j++;
		}
		i++;
	}
}

//30 degrees in radians is 0.523599//
//https://en.wikipedia.org/wiki/Rotation_matrix//
static void	rotate_x(t_point *fdf, int y, int z)
{
	fdf->y = y * cos(0.523599) + z * sin(0.523599);
	fdf->z = -y * sin(0.523599) + z * cos(0.523599);
}

static void	rotate_y(t_point *fdf, int x, int z)
{
	fdf->x = x * cos(0.523599) + z * sin(0.523599);
	fdf->z = -x * sin(0.523599) + z * cos(0.523599);
}

static void	rotate_z(t_point *fdf, int x, int y)
{
	fdf->x = x * cos(0.523599) - y * sin(0.523599);
	fdf->y = x * sin(0.523599) + y * cos(0.523599);
}
