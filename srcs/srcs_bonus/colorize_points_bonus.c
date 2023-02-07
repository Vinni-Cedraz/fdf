/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 11:00:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	colorize_points_bonus(t_data *d)
{
	t_n	*tmp;

	d->c->create_hsl_map = &create_hsl_map;
	d->c->create_hsl_map(d);
	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.compute_point_color(&tmp->point, d);
		tmp = tmp->next;
	}
}
