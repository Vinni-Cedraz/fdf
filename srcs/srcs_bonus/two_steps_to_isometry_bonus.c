/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_steps_to_isometry_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 00:06:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	apply_isometric_steps(t_data *d);
static void	take_snapshot(t_data *d);
static void	undo_isometric_steps(t_data *d);
static void	restore_isometric_state_from_snapshot(t_data *d);

void	two_steps_to_isometry_bonus(t_data *d, t_short undo_iso_steps,
		t_short restore_iso_state)
{
	if (undo_iso_steps)
		undo_isometric_steps(d);
	else if (restore_iso_state)
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
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			d->map->pts[i][j].snapshot.old_x = d->map->pts[i][j].x;
			d->map->pts[i][j].snapshot.old_y = d->map->pts[i][j].y;
			d->map->pts[i][j].snapshot.old_z = d->map->pts[i][j].z;
			j++;
		}
		i++;
	}
}

static void	restore_isometric_state_from_snapshot(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->map->height)
	{
		j = 0;
		while (j < d->map->width)
		{
			d->map->pts[i][j].x = d->map->pts[i][j].snapshot.old_x;
			d->map->pts[i][j].y = d->map->pts[i][j].snapshot.old_y;
			d->map->pts[i][j].z = d->map->pts[i][j].snapshot.old_z;
			j++;
		}
		i++;
	}
	d->state.diagonal = 0;
	d->state.parallel = 0;
	d->state.isometric = 1;
}
