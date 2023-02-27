/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_transition_methods_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:58:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 23:51:35 by vcedraz-         ###   ########.fr       */
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
	d->state = isometric;
}

inline void	undo_isometric(t_data *d)
{
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
	if (d->state == spherical) {
		normalize_after_leaving_sphere_bonus(d);
		transpts_with_given_matrix_bonus(d, &d->matrix->go_iso);
   }
	else {
		restore_iso_snapshot(d);
		d->offset->neutral_zoom = 1;
   }
	d->state = isometric;
}
