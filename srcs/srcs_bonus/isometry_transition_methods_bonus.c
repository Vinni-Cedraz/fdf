/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry_transition_methods_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:48:07 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 18:01:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	go_to_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_z_45);
	d->state.isometric = 0;
	d->state.parallel = 0;
	d->state.diagonal = 1;
}

inline void	go_to_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_x_54_73);
	d->state.parallel = 0;
	d->state.diagonal = 0;
	d->state.isometric = 1;
}

inline void	undo_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_x_54_73);
	d->state.parallel = 0;
	d->state.diagonal = 0;
	d->state.isometric = 1;
}

inline void	undo_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_z_45);
	d->state.isometric = 0;
	d->state.diagonal = 0;
	d->state.parallel = 1;
}

inline void	restore_snapshot(t_data *d)
{
	go_isometric_from_state_out_of_position(d);
	d->state.diagonal = 0;
	d->state.parallel = 0;
	d->state.out_of_position = 0;
	d->state.isometric = 1;
}
