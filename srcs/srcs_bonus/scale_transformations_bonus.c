/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_transformations_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 20:10:30 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	scale_z(t_data *d, short int up, short int down, short int mirror);

void	change_altitude(t_data *d, short int up, short int mirror)
{
	two_steps_to_isometry_bonus(d, 1);
	undo_isometric_steps_bonus(d);
	if (up)
	{
		if (d->map->max_z >= 1800)
			return ;
		scale_z(d, 1, 0, 0);
	}
	else if (mirror)
		scale_z(d, 0, 0, 1);
	else
		scale_z(d, 0, 1, 0);
	two_steps_to_isometry_bonus(d, 0);
}

static void	scale_z(t_data *d, short int up, short int down, short int mirror)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			if (up)
				d->map->arr[i][j].z *= 1.1;
			if (down)
				d->map->arr[i][j].z /= 1.1;
			if (mirror)
				d->map->arr[i][j].z *= -1;
			j++;
		}
		i++;
	}
}
