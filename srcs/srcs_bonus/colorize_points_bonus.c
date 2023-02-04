/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/27 02:37:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	colorize_points_bonus(t_data *d)
{
	t_n	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.define_p_color_by_altitude(&tmp->point, d);
		tmp = tmp->next;
	}
}
