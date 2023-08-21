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

static short		check_state_before_looping_stages(void);
static short		check_state_before_using_iso_snapshot(void);
static void			take_snapshots_after_looping(void);

void	loop_through_each_transition_method(void)
{
	t_data	*d;

	d = get_data();
	if (!check_state_before_looping_stages())
		return ;
	((t_func_ptr)(d->lookup.transition_methods->content))();
	d->lookup.transition_methods = d->lookup.transition_methods->next;
	take_snapshots_after_looping();
}

void	restore_iso_snapshot(void)
{
	t_n		*tmp;
	t_n		*dummy;
	t_data	*d;

	d = get_data();
	if (!check_state_before_using_iso_snapshot())
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

static inline void	take_snapshots_after_looping(void)
{
	t_n		*tmp;
	t_n		*dummy;
	t_data	*d;

	d = get_data();
	if (d->state != isometric)
		return ;
	take_zoom_snapshot();
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

static inline short	check_state_before_looping_stages(void)
{
	t_data	*d;

	d = get_data();
	if (!d->offset->neutral_zoom || d->state == randomly_rotated)
		return (0);
	if (d->state == spherical)
		return (0);
	return (1);
}

static inline short	check_state_before_using_iso_snapshot(void)
{
	t_data	*d;

	d = get_data();
	if (d->state == randomly_rotated || d->state == spherical)
		return (1);
	return (0);
}
