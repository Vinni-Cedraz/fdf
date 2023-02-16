/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_transition_methods_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:58:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/16 19:59:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	go_to_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_z_45);
	d->state = diagonal;
}

inline void	go_to_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_x_54_73);
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_y);
	d->state = isometric;
}

inline void	undo_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_y);
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_x_54_73);
	d->state = diagonal;
}

inline void	undo_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_z_45);
	d->state = parallel;
}

inline void	go_isometric_using_snapshot(t_data *d)
{
	restore_iso_snapshot(d);
	d->offset->move_x = d->offset->initial_move_x;
	d->offset->move_y = d->offset->initial_move_y;
	if (d->state == spherical)
		get_xy_range_bonus(d);
	get_altitude_range_bonus(d->map);
	d->map->get_map_center(d);
	d->state = isometric;
	d->offset->neutral_zoom = 1;
}
