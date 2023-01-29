/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_five_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:05:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 12:08:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void		reset_states(t_data *d);

inline void	rotate_five_around_x(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_x);
	reset_states(d);
}

inline void	reverse_five_around_x(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_x);
	reset_states(d);
}

inline void	rotate_five_around_z(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_z);
	reset_states(d);
}

inline void	reverse_five_around_z(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_z);
	reset_states(d);
}

inline void	reset_states(t_data *d)
{
	d->state.isometric = 0;
	d->state.diagonal = 0;
	d->state.parallel = 0;
	d->state.out_of_position = 1;
}
