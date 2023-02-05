/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_altitude_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 19:37:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	mirror_altitude(t_data *d)
{
	if (d->state != isometric)
		return ;
	reset_zoom_from_snapshot(d);
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_mirror);
}

inline void	increase_altitude(t_data *d)
{
	if (d->state != isometric)
		return ;
	reset_zoom_from_snapshot(d);
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_up);
}

inline void	decrease_altitude(t_data *d)
{
	if (d->state != isometric)
		return ;
	reset_zoom_from_snapshot(d);
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_down);
}
