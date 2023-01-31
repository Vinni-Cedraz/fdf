/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry_transition_methods_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:48:07 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/30 22:27:07 by vcedraz-         ###   ########.fr       */
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
	d->state.isometric = 0;
	d->state.diagonal = 1;
}

inline void	undo_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_z_45);
	d->state.isometric = 0;
	d->state.diagonal = 0;
	d->state.parallel = 1;
}

inline void	go_isometric_using_snapshot(t_data *d)
{
	restore_iso_snapshot(d);
	d->state.diagonal = 0;
	d->state.parallel = 0;
	d->state.randomly_rotated = 0;
	d->state.isometric = 1;
}
