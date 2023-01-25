/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_t_points_methods_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:46:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/25 19:52:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	assign_t_points_methods_bonus(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.set_hexcolor = &set_hexcolor;
		tmp->point.define_p_color_by_altitude = &compute_color_gradient_bonus;
		tmp = tmp->next;
	}
}
