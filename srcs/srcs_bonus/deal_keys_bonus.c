/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 17:32:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_deal_keys(int key, t_data *d);
static void	aux_aux_deal_keys(int key, t_data *d);

int	deal_keys_bonus(int key, t_data *d)
{
	if (key == XK_ESCAPE)
		close_win_bonus(d);
	else if (key == XK_RIGHT || key == 'l')
		right(d);
	else if (key == XK_LEFT || key == 'h')
		left(d);
	else if (key == XK_UP || key == 'k')
		up(d);
	else if (key == XK_DOWN || key == 'j')
		down(d);
	else if ((key == 'i' || key == ' '))
		go_through_each_stage_of_isometric_transform(d);
	else if (key == ';')
		move_back_to_isometric_state(d);
	else if (key)
		aux_deal_keys(key, d);
	return (0);
}

static void	aux_deal_keys(int key, t_data *d)
{
	if (key == 'w')
		zoom_in(d);
	else if (key == 's')
		zoom_out(d);
	else if (key == 'g')
		change_grid_rendering_method(d);
	else if (key == 'z')
		increase_altitude(d);
	else if (key == 'c')
		decrease_altitude(d);
	else if (key == 'm')
		invert_altitude(d);
	else if (key)
		aux_aux_deal_keys(key, d);
}

static void	aux_aux_deal_keys(int key, t_data *d)
{
	if (key == 'a')
		rotate_five_around_y(d);
	else if (key == 'd')
		reverse_five_around_y(d);
	else if (key == 'q')
		rotate_five_around_x(d);
	else if (key == 'e')
		reverse_five_around_x(d);
	else if (key == 'x')
		rotate_five_around_z(d);
	else if (key == 'v')
		reverse_five_around_z(d);
}
