/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/02 21:40:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

int	deal_key(int key, t_data *d)
{
	if (key == ' ' && !d->do_step_one)
	{
		linear_transformations(d, &d->matrix->rot_z_45);
		d->do_step_one = 1;
		linear_transformations(d, &d->matrix->rot_x_54_73);
		d->do_step_two = 1;
	}
	if (key == ESC)
		close_win(d);
	return (0);
}
