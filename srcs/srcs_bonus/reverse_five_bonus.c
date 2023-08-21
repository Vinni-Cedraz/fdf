/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_five_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:44:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 20:23:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			update_state_after_revfive(void);
static int			check_state_before_revfive(void);

inline void	reverse_five_around_x(void)
{
	if (!check_state_before_revfive())
		return ;
	transpts_with_given_matrix_bonus(&get_data()->matrix->rev_x);
	if (get_data()->state != spherical)
		update_state_after_revfive();
}

inline void	reverse_five_around_y(void)
{
	if (!check_state_before_revfive())
		return ;
	transpts_with_given_matrix_bonus(&get_data()->matrix->rev_y);
	if (get_data()->state != spherical)
		update_state_after_revfive();
}

inline void	reverse_five_around_z(void)
{
	if (!check_state_before_revfive())
		return ;
	transpts_with_given_matrix_bonus(&get_data()->matrix->rev_z);
	if (get_data()->state != spherical)
		update_state_after_revfive();
}

static inline void	update_state_after_revfive(void)
{
	get_data()->state = randomly_rotated;
	get_data()->offset->neutral_zoom = 1;
}

static inline int	check_state_before_revfive(void)
{
	t_data	*d;

	d = get_data();
	if (d->state == diagonal || d->state == parallel)
		return (0);
	if (d->offset->neutral_zoom != 1)
		return (reset_zoom_from_snapshot(), 1);
	return (1);
}
