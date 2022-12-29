/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_movements_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:14:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 17:49:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	move_right(t_data *d)
{
	d->offset->move_x += 100;
}

void	move_left(t_data *d)
{
	d->offset->move_x -= 100;
}

void	move_up(t_data *d)
{
	d->offset->move_y -= 100;
}

void	move_down(t_data *d)
{
	d->offset->move_y += 100;
}
