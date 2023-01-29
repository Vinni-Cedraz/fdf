/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_five_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:44:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 18:15:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			update_state_after_revfive(t_data *d);

inline void	reverse_five_around_x(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_x);
	update_state_after_revfive(d);
}

inline void	reverse_five_around_y(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_y);
	update_state_after_revfive(d);
}

inline void	reverse_five_around_z(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_z);
	update_state_after_revfive(d);
}

static inline void	update_state_after_revfive(t_data *d)
{
	d->state.isometric = 0;
	d->state.diagonal = 0;
	d->state.parallel = 0;
	d->state.out_of_position = 1;
}
