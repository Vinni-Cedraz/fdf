/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/29 19:56:35 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	data_initializer(t_data *d)
{
	d->rotations_history = ft_lstnew(NULL);
	d->reverse_5_around_x = 0;
	d->rotate_5_around_x = 0;
	d->neutral_x = 1;
	d->neutral_y = 1;
	d->reverse_5_around_y = 0;
	d->rotate_5_around_y = 0;
	d->apply_iso = 0;
	d->reset_iso = 0;
	d->neutral_iso = 0;
	d->do_step_one = 0;
	d->do_step_two = 0;
	d->zoom_in = 0;
	d->zoom_out = 0;
	d->neutral_zoom = 1;
	d->move_x = 0;
	d->move_y = 0;
}
