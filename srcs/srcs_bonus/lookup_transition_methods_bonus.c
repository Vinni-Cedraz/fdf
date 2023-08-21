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

inline void	go_to_diagonal(void)
{
	t_data	*d;

	d = get_data();
	transpts_with_given_matrix_bonus(&d->matrix->rot_z_45);
	d->state = diagonal;
}

inline void	go_to_isometric(void)
{
	transpts_with_given_matrix_bonus(&get_data()->matrix->rot_x_54_73);
	get_data()->state = isometric;
}

inline void	undo_isometric(void)
{
	transpts_with_given_matrix_bonus(&get_data()->matrix->rev_x_54_73);
	get_data()->state = diagonal;
}

inline void	undo_diagonal(void)
{
	transpts_with_given_matrix_bonus(&get_data()->matrix->rev_z_45);
	get_data()->state = parallel;
}

inline void	go_isometric_using_snapshot(void)
{
	t_data	*d;

	d = get_data();
	if (d->state == spherical)
	{
		normalize_after_leaving_sphere_bonus();
		transpts_with_given_matrix_bonus(&d->matrix->go_iso);
	}
	else
	{
		restore_iso_snapshot();
		d->offset->neutral_zoom = 1;
	}
	d->state = isometric;
}
