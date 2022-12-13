/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:44:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/12 21:12:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

// in this c file we have the functions that rotate the map in isometric proj-
// ection, according to the right-hand rule. And taking into consideration the
// fact that the computer screen coordinates are different from the cartesian
// coordinates.

// 1. rotate around the x axis
// 2. rotate around the y axis
// 3. rotate around the z axis

// a is the angle of rotation in radians

// the rotation matrix on the x axis is, with the right-hand rule:
// | 1 0 0 |
// | 0 cos(a) -sin(a) |
// | 0 sin(a) cos(a) |

// now the same as above but considering the computer screen coordinates:
// | 1 0 0 |
// | 0 cos(a) sin(a) |
// | 0 -sin(a) cos(a) |

// the rotation matrix on the y axis is, with the right-hand rule:
// | cos(a) 0 sin(a) |
// | 0 1 0 |
// | -sin(a) 0 cos(a) |

// To apply the formulas above we just need to multiply the matrix by the
// vector that we want to rotate. The vector is composed by the x, y and z
// coordinates of the point that we want to rotate.

// here is how the multiplication of the rotation matrix and the vector is done:
// | x | = | 1 0 0 | * | x | = | x |
// | y | = | 0 cos(a) -sin(a) | * | y | = | cos(a) * y - sin(a) * z |
// | z | = | 0 sin(a) cos(a) | * | z | = | sin(a) * y + cos(a) * z |

// now for the y axis:
// | x | = | cos(a) 0 sin(a) * | x | = | x cos(a) + z sin(a) |
// | y | = | 0 1 0 | * | y | = | y |
// | z | = | -sin(a) 0 cos(a) | * | z | = | -x sin(a) + z cos(a) |

// and for the z axis:
// | x | = | cos(a) -sin(a) 0 | * | x | = | x cos(a) - y sin(a) |
// | y | = | sin(a) cos(a) 0 | * | y | = | x sin(a) + y cos(a) |
// | z | = | 0 0 1 | * | z | = | z |


// now for the implementantion in code:

// this function rotates the map around the x axis //
static void	rotate_x(t_data *fdf, double a)
{
	int		i;
	int		j;
	double	y;
	double	z;

	i = 0;
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			y = fdf->map->arr[i][j].y;
			z = fdf->map->arr[i][j].z;
			fdf->map->arr[i][j].y = y * cos(a) - z * sin(a);
			fdf->map->arr[i][j].z = y * sin(a) + z * cos(a);
			j++;
		}
		i++;
	}
}

// this function rotates the map around the y axis //
static void	rotate_y(t_data *fdf, double a)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			x = fdf->map->arr[i][j].x;
			z = fdf->map->arr[i][j].z;
			fdf->map->arr[i][j].x = x * cos(a) + z * sin(a);
			fdf->map->arr[i][j].z = -x * sin(a) + z * cos(a);
			j++;
		}
		i++;
	}
}

// this function rotates the map around the z axis //
static void	rotate_z(t_data *fdf, double a)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			x = fdf->map->arr[i][j].x;
			y = fdf->map->arr[i][j].y;
			fdf->map->arr[i][j].x = x * cos(a) - y * sin(a);
			fdf->map->arr[i][j].y = x * sin(a) + y * cos(a);
			j++;
		}
		i++;
	}
}

// this function rotates the map in isometric projection //
void	rotate_map(t_data *fdf)
{
	rotate_x(fdf, ANGLE);
	rotate_y(fdf, ANGLE);
	rotate_z(fdf, ANGLE);
}

