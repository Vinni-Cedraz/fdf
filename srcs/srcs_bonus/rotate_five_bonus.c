/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_five_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:05:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/30 22:40:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			update_state_after_rotfive(t_data *d);
static int			check_state_before_rotfive(t_data *d);

inline void	rotate_five_around_x(t_data *d)
{
	if (!check_state_before_rotfive(d))
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_x);
	update_state_after_rotfive(d);
}

inline void	rotate_five_around_y(t_data *d)
{
	if (!check_state_before_rotfive(d))
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_y);
	update_state_after_rotfive(d);
}

inline void	rotate_five_around_z(t_data *d)
{
	if (!check_state_before_rotfive(d))
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_z);
	update_state_after_rotfive(d);
}

static inline void	update_state_after_rotfive(t_data *d)
{
	d->state.isometric = 0;
	d->state.randomly_rotated = 1;
	d->offset->neutral_zoom = 1;
}

static inline int	check_state_before_rotfive(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return (0);
	if (d->offset->neutral_zoom != 1)
		return (reset_zoom_from_snapshot(d), 1);
	return (1);
}
