/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/17 17:50:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

//this functions draws in an img a line between the points of a map:
void	render_map_bns(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			if (j < d->map->width - 1)
				render_line_bns(d->map->arr[i][j],
					d->map->arr[i][j + 1],
					d->map->arr[i][j + 1].color,
					d);
			if (i < d->map->height - 1)
				render_line_bns(d->map->arr[i][j],
					d->map->arr[i + 1][j],
					d->map->arr[i + 1][j].color,
					d);
			j++;
		}
		i++;
	}
}
