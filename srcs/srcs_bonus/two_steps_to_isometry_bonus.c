/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_steps_to_isometry_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 22:17:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void		apply_iso_steps(t_data *d);
void		restore_from_snapshot(t_data *d);
static void	take_snapshot(t_data *d);
static void	initialize_iso_finite_state_machine(t_data *d);

void	two_steps_to_isometry_bonus(t_data *d, t_isometry_changer iso_changer)
{
	initialize_iso_finite_state_machine(d);
	iso_changer.action(d);
	if (d->state.isometric)
		take_snapshot(d);
}

void	apply_iso_steps(t_data *d)
{
	static int	i;

	d->state_transition_method[i](d);
	i++;
	if (i == 4)
		i = 0;
}

static void	initialize_iso_finite_state_machine(t_data *d)
{
	d->state_transition_method[0] = &go_to_diagonal;
	d->state_transition_method[1] = &go_to_isometric;
	d->state_transition_method[2] = &undo_isometric;
	d->state_transition_method[3] = &undo_diagonal;
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

void	restore_from_snapshot(t_data *d)
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
}
