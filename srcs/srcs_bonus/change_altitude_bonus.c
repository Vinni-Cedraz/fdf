/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_altitude_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:42:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/20 18:33:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	change_altitude_bonus(t_data *d, t_zscaler direction)
{
	get_altitude_range_bonus(d->map);
	if (!d->state.isometric)
		return ;
	if (!d->state.neutral_zoom)
		zoom_bonus(d, 0, 0, 1);
	direction.scale_method(d);
}
