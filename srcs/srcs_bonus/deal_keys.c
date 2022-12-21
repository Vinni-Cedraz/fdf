/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 12:36:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_deal_keys(int *key, t_data *d);

int	deal_keys(int key, t_data *d)
{
	if (key == XK_ESCAPE)
		close_win_bns(d);
	else if (key == XK_RIGHT || key == 'l')
		move_right(d);
	else if (key == XK_LEFT || key == 'h')
		move_left(d);
	else if (key == XK_UP || key == 'k')
		move_up(d);
	else if (key == XK_DOWN || key == 'j')
		move_down(d);
	else if (key == 'i')
		apply_isometry(d);
	else if (key == 'r')
		reset_isometry(d);
	else if (key == 'a')
		rotate_5_around_z(d);
	else if (key == 'd')
		reverse_5_around_z(d);
	else if (key)
		aux_deal_keys(&key, d);
	return (0);
}

static void	aux_deal_keys(int *key, t_data *d)
{
	if (*key == 'z')
		scale_z_up(d);
	else if (*key == 'c')
		scale_z_down(d);
	else if (*key == 'm')
		mirror_z(d);
	else if (*key == 'w')
		zoom_in(d);
	else if (*key == 's')
		zoom_out(d);
	else if (*key == 'q')
		rotate_5_around_y(d);
	else if (*key == 'e')
		reverse_5_around_y(d);
	else if (*key == 'f')
		rotate_5_around_x(d);
	else if (*key == 'g')
		reverse_5_around_x(d);		
}
