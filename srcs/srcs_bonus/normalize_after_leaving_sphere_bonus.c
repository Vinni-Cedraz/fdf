/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_after_leaving_sphere_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:47:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 23:48:05 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	normalize_after_leaving_sphere_bonus(t_data *d)
{
	int	i;

	i = 3;
	restore_raw_state_bonus(d);
	d->offset->move_x = d->offset->initial_move_x;
	d->offset->move_y = d->offset->initial_move_y;
	get_xy_range_bonus(d);
	while (i--)
	{
		go_to_diagonal(d);
		go_to_isometric(d);
		undo_isometric(d);
		undo_diagonal(d);
	}
}
