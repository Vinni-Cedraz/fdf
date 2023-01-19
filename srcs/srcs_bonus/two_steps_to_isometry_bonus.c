/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_steps_to_isometry_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/19 10:47:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	apply_isometric_steps(t_data *d);
static void	take_snapshot(t_data *d);
static void	undo_isometric_steps(t_data *d);
static void	restore_isometric_state_from_snapshot(t_data *d);

// variables renamed locally to improve readability
void	two_steps_to_isometry_bonus(t_data *d, t_short opt_1, t_short opt_2)
{
	t_short		undo_isometry;
	t_short		go_back_to_isometry;

	undo_isometry = opt_1;
	go_back_to_isometry = opt_2;
	if (undo_isometry)
		undo_isometric_steps(d);
	else if (go_back_to_isometry)
		restore_isometric_state_from_snapshot(d);
	else
	{
		apply_isometric_steps(d);
		if (d->state.isometric)
			take_snapshot(d);
	}
}

static void	apply_isometric_steps(t_data *d)
{
	if ((!d->state.parallel && !d->state.diagonal) || d->state.isometric)
		return ;
	d->state.step_towards_isometry++;
	if ((d->state.step_towards_isometry - d->state.step_back) == 1)
	{
		d->state.parallel = 1;
		d->state.diagonal = 0;
	}
	else if ((d->state.step_towards_isometry - d->state.step_back) == 2)
	{
		d->state.diagonal = 1;
		d->state.parallel = 0;
	}
	if (d->state.parallel)
		linear_transformations_bonus(d, &d->matrix->rot_z_45, 0);
	else if (d->state.diagonal)
		linear_transformations_bonus(d, &d->matrix->rot_x_54_73, 0);
	if ((d->state.step_towards_isometry - d->state.step_back) == 2)
	{
		d->state.isometric = 1;
		take_snapshot(d);
	}
}

static void	undo_isometric_steps(t_data *d)
{
	if (!d->state.isometric && !d->state.diagonal)
		return ;
	d->state.step_back++;
	if ((d->state.step_towards_isometry - d->state.step_back) == 1)
	{
		d->state.parallel = 0;
		d->state.diagonal = 1;
	}
	else if ((d->state.step_towards_isometry - d->state.step_back) == 0)
	{
		d->state.diagonal = 0;
		d->state.parallel = 1;
	}
	if (d->state.diagonal)
		linear_transformations_bonus(d, &d->matrix->rev_x_54_73, 0);
	else if (d->state.parallel)
		linear_transformations_bonus(d, &d->matrix->rev_z_45, 0);
	d->state.isometric = 0;
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

static void	restore_isometric_state_from_snapshot(t_data *d)
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
