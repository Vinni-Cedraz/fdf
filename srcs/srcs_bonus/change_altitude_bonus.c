/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_altitude_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 15:39:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	change_altitude_bonus(t_data *d, t_zscaler scaler)
{
	if (!d->state.isometric)
		return ;
	zoom_bonus(d, 0, 0, 1);
	scaler.scale_method(d);
}

inline void	z_mirror_method(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_mirror);
}

inline void	z_up_method(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_up);
}

inline void	z_down_method(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_down);
}
