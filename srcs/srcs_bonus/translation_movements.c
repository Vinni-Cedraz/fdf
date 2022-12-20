/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_movements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:14:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/20 12:21:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	move_right(t_data *d)
{
	d->move_x += 100;
	draw(d);
}

void	move_left(t_data *d)
{
	d->move_x -= 100;
	draw(d);
}

void	move_up(t_data *d)
{
	d->move_y -= 100;
	draw(d);
}

void	move_down(t_data *d)
{
	d->move_y += 100;
	draw(d);
}
