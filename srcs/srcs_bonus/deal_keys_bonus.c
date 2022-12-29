/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 18:49:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_deal_keys(int key, t_data *d);

int	deal_keys(int key, t_data *d)
{
	if (key == XK_ESCAPE)
		close_win_bonus(d);
	else if (key == XK_RIGHT || key == 'l')
		move_right(d);
	else if (key == XK_LEFT || key == 'h')
		move_left(d);
	else if (key == XK_UP || key == 'k')
		move_up(d);
	else if (key == XK_DOWN || key == 'j')
		move_down(d);
	else if (key == 'i')
		do_isometric_steps(d);
	else if (key == 'r')
		undo_isometric_steps(d);
	else if (key == ';')
		get_back_to_isometric(d);
	else if (key)
		aux_deal_keys(key, d);
	return (0);
}

static void	aux_deal_keys(int key, t_data *d)
{
	if (key == 'z')
		scale_z_up(d);
	else if (key == 'c')
		scale_z_down(d);
	else if (key == 'm')
		mirror_z(d);
	else if (key == 'w')
		zoom(d, 1, 0);
	else if (key == 's')
		zoom(d, 0, 1);
	else if (key == 'a')
		rotate_2_around_y(d, 1, 0);
	else if (key == 'd')
		rotate_2_around_y(d, 0, 1);
	else if (key == 'q')
		rotate_2_around_x(d, 1, 0);
	else if (key == 'e')
		rotate_2_around_x(d, 0, 1);
}
