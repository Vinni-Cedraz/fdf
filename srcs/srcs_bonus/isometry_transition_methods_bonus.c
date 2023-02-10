/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry_transition_methods_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:48:07 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/10 12:45:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	go_to_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_z_45);
	d->state = diagonal;
	d->offset->move_y -= d->offset->move_y * 0.2;
}

inline void	go_to_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_x_54_73);
	d->state = isometric;
	d->offset->move_y -= d->offset->move_y * 0.2;
}

inline void	undo_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_x_54_73);
	d->state = diagonal;
	d->offset->move_y -= d->offset->move_y * 0.2;
}

inline void	undo_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_z_45);
	d->state = parallel;
	d->offset->move_y -= d->offset->move_y * 0.2;
}

inline void	go_isometric_using_snapshot(t_data *d)
{
	restore_iso_snapshot(d);
	d->offset->move_x = d->offset->initial_move_x;
	d->offset->initial_move_y -= d->offset->initial_move_y * 0.2;
	d->offset->move_y = d->offset->initial_move_y;
	get_xy_range_bonus(d);
	get_map_center(d);
	d->state = isometric;
	d->offset->neutral_zoom = 1;
}
