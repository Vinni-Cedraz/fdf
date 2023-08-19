/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_through_each_transition_method_bonus.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:06:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 22:35:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static short		check_state_before_looping_stages(t_data *d);
static short		check_state_before_using_iso_snapshot(t_data *d);
static void			take_snapshots_after_looping(t_data *d);

void	loop_through_each_transition_method(t_data *d)
{
	if (!check_state_before_looping_stages(d))
		return ;
	((t_func_ptr)(d->lookup.transition_methods->content))(d);
	d->lookup.transition_methods = d->lookup.transition_methods->next;
	take_snapshots_after_looping(d);
}

void	restore_iso_snapshot(t_data *d)
{
	t_n	*tmp;
	t_n	*dummy;

	if (!check_state_before_using_iso_snapshot(d))
		return ;
	tmp = d->map->pts;
	dummy = tmp;
	while (tmp->next != dummy)
	{
		tmp->point.x = tmp->point.ol.x;
		tmp->point.y = tmp->point.ol.y;
		tmp->point.z = tmp->point.ol.z;
		tmp = tmp->next;
	}
	d->state = isometric;
}

static inline void	take_snapshots_after_looping(t_data *d)
{
	t_n	*tmp;
	t_n	*dummy;

	if (d->state != isometric)
		return ;
	take_zoom_snapshot(d);
	tmp = d->map->pts;
	dummy = tmp;
	while (tmp->next != dummy)
	{
		tmp->point.ol.x = tmp->point.x;
		tmp->point.ol.y = tmp->point.y;
		tmp->point.ol.z = tmp->point.z;
		tmp = tmp->next;
	}
}

static inline short	check_state_before_looping_stages(t_data *d)
{
	if (!d->offset->neutral_zoom || d->state == randomly_rotated)
		return (0);
	if (d->state == spherical)
		return (0);
	return (1);
}

static inline short	check_state_before_using_iso_snapshot(t_data *d)
{
	if (d->state == randomly_rotated || d->state == spherical)
		return (1);
	return (0);
}
