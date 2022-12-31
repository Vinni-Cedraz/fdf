/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:11:35 by vcedraz-          #+#    #+#             */
/*   UpdatedG 2022/12/31 13:21:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	render_map_bonus(t_data *d)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			if (j < d->map->width - 1)
				render_line_bonus(d->map->arr[i][j], d->map->arr[i][j + 1], d);
			if (i < d->map->height - 1)
				render_line_bonus(d->map->arr[i][j], d->map->arr[i + 1][j], d);
		}
	}
}
