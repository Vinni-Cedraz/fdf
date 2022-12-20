/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/20 08:43:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_deal_keys(int key, t_data *d);

int	deal_keys(int key, t_data *d)
{
	if (key == XK_ESCAPE)
		close_win_bns(d);
	if (key == XK_RIGHT || key == 'l')
		move_right(d);
	if (key == XK_LEFT || key == 'h')
		move_left(d);
	if (key == XK_UP || key == 'k')
		move_up(d);
	if (key == XK_DOWN || key == 'j')
		move_down(d);
	if (key == 'i')
		apply_isometry(d);
	if (key == 'r')
		reset_isometry(d);
	if (key == 'a')
		rotate_15_around_z(d);
	if (key == 'd')
		reverse_15_around_z(d);
	else if (key)
		aux_deal_keys(key, d);
	return (0);
}

static void	aux_deal_keys(int key, t_data *d)
{
	if (key == 'z')
		scale_z_up(d);
	if (key == 'c')
		scale_z_down(d);
	if (key == 'm')
		mirror_z(d);
	if (key == 'w')
		zoom_in(d);
	if (key == 's')
		zoom_out(d);
}
