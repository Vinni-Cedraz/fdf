/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/06 22:34:36 by vcedraz-         ###   ########.fr       */
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
	if (key == XK_ESCAPE)
		close_win(d);
	return (0);
}
