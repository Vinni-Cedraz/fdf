/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 17:23:15 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	deal_keys(int key, t_data *d)
{
	if (key == XK_ESCAPE)
		close_win_bns(d);
	if (key == XK_RIGHT)
		move_right(d);
	if (key == XK_LEFT)
		move_left(d);
	if (key == XK_UP)
		move_up(d);
	if (key == XK_DOWN)
		move_down(d);
	if (key == 'i')
		apply_isometry(d);
	if (key == 'r')
		reset_isometry(d);
	return (0);
}
