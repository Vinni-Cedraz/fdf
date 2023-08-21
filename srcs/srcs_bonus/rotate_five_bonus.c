/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_five_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:05:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 20:23:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			update_state_after_rotfive(void);
static int			check_state_before_rotfive(void);

inline void	rotate_five_around_x(void)
{
	if (!check_state_before_rotfive())
		return ;
	transpts_with_given_matrix_bonus(&get_data()->matrix->rot_x);
	if (get_data()->state != spherical)
		update_state_after_rotfive();
}

inline void	rotate_five_around_y(void)
{
	if (!check_state_before_rotfive())
		return ;
	transpts_with_given_matrix_bonus(&get_data()->matrix->rot_y);
	if (get_data()->state != spherical)
		update_state_after_rotfive();
}

inline void	rotate_five_around_z(void)
{
	if (!check_state_before_rotfive())
		return ;
	transpts_with_given_matrix_bonus(&get_data()->matrix->rot_z);
	if (get_data()->state != spherical)
		update_state_after_rotfive();
}

static inline void	update_state_after_rotfive(void)
{
	get_data()->state = randomly_rotated;
	get_data()->offset->neutral_zoom = 1;
}

static inline int	check_state_before_rotfive(void)
{
	t_data	*d;

	d = get_data();
	if (d->state == diagonal || d->state == parallel)
		return (0);
	if (d->offset->neutral_zoom != 1)
		return (reset_zoom_from_snapshot(), 1);
	return (1);
}
