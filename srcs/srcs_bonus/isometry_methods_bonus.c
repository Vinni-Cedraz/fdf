/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry_methods_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 18:09:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	loop_through_each_transition_method(t_data *d)
{
	((t_func_ptr)(d->lookup.iso_transit_methods->content))(d);
	d->lookup.iso_transit_methods = d->lookup.iso_transit_methods->next;
}

void	go_isometric_from_state_out_of_position(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.x = tmp->point.ol.x;
		tmp->point.y = tmp->point.ol.y;
		tmp->point.z = tmp->point.ol.z;
		tmp = tmp->next;
	}
}

void	take_snapshot(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.ol.x = tmp->point.x;
		tmp->point.ol.y = tmp->point.y;
		tmp->point.ol.z = tmp->point.z;
		tmp = tmp->next;
	}
}
