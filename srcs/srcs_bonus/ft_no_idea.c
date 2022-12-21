/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_idea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:58:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 04:12:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	ft_no_idea(t_data *d)
{
	int		i;
	int		j;

	i = -1;	
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			rotate_x(&d->map->arr[i][j].y, &d->map->arr[i][j].z, &d->map->cam.alpha);
			rotate_y(&d->map->arr[i][j].x, &d->map->arr[i][j].z, &d->map->cam.beta);
			rotate_z(&d->map->arr[i][j].x, &d->map->arr[i][j].y, &d->map->cam.gamma);
			isometric(&d->map->arr[i][j].x, &d->map->arr[i][j].y, d->map->arr[i][j].z);
		}
	}
}
