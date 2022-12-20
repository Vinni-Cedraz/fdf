/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:06:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/20 14:08:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	data_initializer(t_data *d)
{
	d->clockwise = 0;
	d->counter_clock = 0;
	d->move_x = 0;
	d->move_y = 0;
}
