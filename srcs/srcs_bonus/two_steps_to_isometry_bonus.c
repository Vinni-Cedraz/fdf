/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_steps_to_isometry_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 02:15:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void		apply_iso_steps(t_data *d);
void		restore_snapshot(t_data *d);
static void	take_snapshot(t_data *d);
static void	initialize_array_of_transitioner_objects(t_data *d);

void	two_steps_to_isometry_bonus(t_data *d, t_isometry_changer changer)
{
	initialize_array_of_transitioner_objects(d);
	if (d->state.isometric)
		take_snapshot(d);
	changer.action(d);
	if (d->state.isometric)
		take_snapshot(d);
}

void	apply_iso_steps(t_data *d)
{
	static int	i;

	d->iso_fsm[i].transition(d);
	i++;
	if (i == 4)
		i = 0;
}

static void	initialize_array_of_transitioner_objects(t_data *d)
{
	d->iso_fsm[0] = (t_iso_context){.transition = go_to_diagonal};
	d->iso_fsm[1] = (t_iso_context){.transition = go_to_isometric};
	d->iso_fsm[2] = (t_iso_context){.transition = undo_iso};
	d->iso_fsm[3] = (t_iso_context){.transition = undo_diag};
}

static void	take_snapshot(t_data *d)
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

void	restore_snapshot(t_data *d)
{
	t_node_with_a_point	*tmp;

	if (d->state.isometric)
		return ;
	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.x = tmp->point.ol.x;
		tmp->point.y = tmp->point.ol.y;
		tmp->point.z = tmp->point.ol.z;
		tmp = tmp->next;
	}
	d->state.diagonal = 0;
	d->state.parallel = 0;
	d->state.isometric = 1;
}
