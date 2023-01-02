/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_steps_to_isometry_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 19:16:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	undo_isometric_steps_bonus(t_data *d);

void	two_steps_to_isometry_bonus(t_data *d, t_short undo)
{
	if (undo)
	{
		undo_isometric_steps_bonus(d);
		return ;
	}
	else if (!d->state.parallel && !d->state.diagonal)
		return ;
	d->state.step_forward++;
	if ((d->state.step_forward - d->state.step_back) == 1)
	{
		d->state.parallel = 1;
		d->state.diagonal = 0;
	}
	else if ((d->state.step_forward - d->state.step_back) == 2)
	{
		d->state.diagonal = 1;
		d->state.parallel = 0;
	}
	if (d->state.parallel)
		linear_transformations_bonus(d, &d->matrix->rot_z_45);
	else if (d->state.diagonal)
		linear_transformations_bonus(d, &d->matrix->rot_x_54_73);
	if (d->state.step_forward - d->state.step_back == 2)
	{
		d->state.isometric = 1;
		d->state.diagonal = 0;
	}
}

static void	undo_isometric_steps_bonus(t_data *d)
{
	if (!d->state.neutral_x || !d->state.neutral_y || !d->state.neutral_zoom
		|| (!d->state.isometric && !d->state.diagonal))
		return ;
	d->state.step_back++;
	printf("back %d\n", d->state.step_back);
	printf("forward %d\n", d->state.step_forward);
	if ((d->state.step_forward - d->state.step_back) == 1)
	{
		d->state.parallel = 0;
		d->state.diagonal = 1;
	}
	else if ((d->state.step_forward - d->state.step_back) == 0)
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
