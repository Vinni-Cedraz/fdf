/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_steps_to_isometry_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 19:55:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	apply_isometric_steps(t_data *d);
static void	undo_isometric_steps(t_data *d);

void	two_steps_to_isometry_bonus(t_data *d, t_short undo_iso_steps)
{
	if (!d->state.parallel && !d->state.diagonal && !d->state.isometric)
		return ;
	if (undo_iso_steps)
		undo_isometric_steps(d);
	else
		apply_isometric_steps(d);
}

static void	apply_isometric_steps(t_data *d)
{
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
		linear_transformations_bonus(d, &d->matrix->rot_z_45);
	else if (d->state.diagonal)
		linear_transformations_bonus(d, &d->matrix->rot_x_54_73);
	if ((d->state.step_towards_isometry - d->state.step_back) == 2)
		d->state.isometric = 1;
}

static void	undo_isometric_steps(t_data *d)
{
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
		linear_transformations_bonus(d, &d->matrix->rev_x_54_73);
	else if (d->state.parallel)
		linear_transformations_bonus(d, &d->matrix->rev_z_45);
	d->state.isometric = 0;
}
