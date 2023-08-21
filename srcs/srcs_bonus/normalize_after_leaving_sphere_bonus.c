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

void	normalize_after_leaving_sphere_bonus(void)
{
	int		i;
	t_data	*d;

	i = 3;
	d = get_data();
	restore_raw_state_bonus();
	d->offset->move_x = d->offset->initial_move_x;
	d->offset->move_y = d->offset->initial_move_y;
	get_xyz_range_bonus();
	while (i--)
	{
		go_to_diagonal();
		go_to_isometric();
		undo_isometric();
		undo_diagonal();
	}
}
