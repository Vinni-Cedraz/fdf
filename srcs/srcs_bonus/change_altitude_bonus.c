/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_altitude_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 20:30:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

inline void	mirror_altitude(void)
{
	if (get_data()->state != isometric)
		go_isometric_using_snapshot();
	reset_zoom_from_snapshot();
	transpts_with_given_matrix_bonus(&get_data()->matrix->change_altitude_mirr);
}

inline void	increase_altitude(void)
{
	if (get_data()->state != isometric)
		go_isometric_using_snapshot();
	reset_zoom_from_snapshot();
	transpts_with_given_matrix_bonus(&get_data()->matrix->change_altitude_up);
}

inline void	decrease_altitude(void)
{
	if (get_data()->state != isometric)
		go_isometric_using_snapshot();
	reset_zoom_from_snapshot();
	transpts_with_given_matrix_bonus(&get_data()->matrix->change_altitude_down);
}
