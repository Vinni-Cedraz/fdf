/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_points_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:22:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/24 22:15:57 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static int	is_colorized(t_data *d);

void	colorize_points_bonus(t_data *d)
{
	t_node_with_a_point	*tmp;

	if (is_colorized(d))
		return ;
	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.define_p_color_by_altitude(&tmp->point, d);
		tmp = tmp->next;
	}
}

static int	is_colorized(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		if (tmp->point.color != CYAN)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
