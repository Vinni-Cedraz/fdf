/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_movements_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:14:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 11:47:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	translation_movements(t_data *d, short int y_up, short int x_right)
{
	if (y_up == 1)
		d->move_y -= 100;
	else if (y_up == -1)
		d->move_y += 100;
	else if (x_right == 1)
		d->move_x += 100;
	else if (x_right == -1)
		d->move_x -= 100;
}
