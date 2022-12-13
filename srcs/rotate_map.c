/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/13 09:46:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

// // this function rotates the map around the x axis:
static void	rotate_x(t_data *fdf, int i, int j, double angle)
{
	int	previous_y;

	previous_y = fdf->map->arr[i][j].y;
	fdf->map->arr[i][j].y = cos(angle) * fdf->map->arr[i][j].y - sin(angle)
		* fdf->map->arr[i][j].z;
	fdf->map->arr[i][j].z = sin(angle) * previous_y + cos(angle)
		* fdf->map->arr[i][j].z;
}

//this function rotates the map around the z axis:
static void	rotate_z(t_data *fdf, int i, int j, double angle)
{
	int	previous_x;

	previous_x = fdf->map->arr[i][j].x;
	fdf->map->arr[i][j].x = cos(angle) * fdf->map->arr[i][j].x - sin(angle)
		* fdf->map->arr[i][j].y;
	fdf->map->arr[i][j].y = sin(angle) * previous_x + cos(angle)
		* fdf->map->arr[i][j].y;
}

//this function calls the two functions above to rotate the map:
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
			rotate_z(fdf, i, j, ANGLE_Z);
			rotate_x(fdf, i, j, ANGLE_X);
			j++;
		}
		i++;
	}
}
