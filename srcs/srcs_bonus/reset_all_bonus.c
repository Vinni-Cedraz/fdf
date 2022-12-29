/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_all_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:11:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 18:57:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	reset_zoom(t_data *d)
{
	short int	successive_operations;
	short int	i;

	i = -1;
	if (d->state->neutral_zoom)
		return ;
	zoom(d, 1, 0);
	zoom(d, 0, 1);
	if (d->state->zoomed_in > d->state->zoomed_out)
	{
		successive_operations = (d->state->zoomed_in - d->state->zoomed_out);
		while (++i < successive_operations)
			zoom(d, 1, 0);
	}
	else
	{
		successive_operations = (d->state->zoomed_out - d->state->zoomed_in);
		while (++i < successive_operations)
			zoom(d, 0, 1);
	}
}

void	reset_rotation_around_x(t_data *d)
{
	short int	successive_operations;
	short int	up_rotations;
	short int	down_rotations;
	short int	i;

	i = -1;
	up_rotations = d->offset->rotate_2_around_x;
	down_rotations = d->offset->reverse_2_around_x;
	if (d->state->neutral_x)
		return ;
	else if (up_rotations > down_rotations)
	{
		successive_operations = (up_rotations - down_rotations);
		while (++i < successive_operations)
			rotate_2_around_x(d, 1, 0);
	}
	else
	{
		successive_operations = (down_rotations - up_rotations);
		while (++i < successive_operations)
			rotate_2_around_x(d, 0, 1);
	}
}

void	reset_rotation_around_y(t_data *d)
{
	short int	successive_operations;
	short int	clockwise_rotations;
	short int	counterclock_rotations;
	short int	i;

	i = -1;
	clockwise_rotations = d->offset->rotate_2_around_y;
	counterclock_rotations = d->offset->reverse_2_around_y;
	if (d->state->neutral_y)
		return ;
	else if (clockwise_rotations > counterclock_rotations)
	{
		successive_operations = (clockwise_rotations - counterclock_rotations);
		while (++i < successive_operations)
			rotate_2_around_y(d, 1, 0);
	}
	else
	{
		successive_operations = (counterclock_rotations - clockwise_rotations);
		while (++i < successive_operations)
			rotate_2_around_y(d, 0, 1);
	}
}

void	get_back_to_isometric(t_data *d)
{
	reset_zoom(d);
	reset_rotation_around_x(d);
	reset_rotation_around_y(d);
}
