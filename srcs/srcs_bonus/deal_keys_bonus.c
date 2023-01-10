/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/09 23:53:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	reset_states(t_data *d);
static void	aux_deal_keys(int key, t_data *d);

int	deal_keys_bonus(int key, t_data *d)
{
	if (key == XK_ESCAPE)
		close_win_bonus(d);
	else if (key == XK_RIGHT || key == 'l')
		d->offset.move_x += 25;
	else if (key == XK_LEFT || key == 'h')
		d->offset.move_x -= 25;
	else if (key == XK_UP || key == 'k')
		d->offset.move_y -= 25;
	else if (key == XK_DOWN || key == 'j')
		d->offset.move_y += 25;
	else if (key == 'i')
		two_steps_to_isometry_bonus(d, 0, 0);
	else if (key == 'r')
		two_steps_to_isometry_bonus(d, 1, 0);
	else if (key == ';')
		two_steps_to_isometry_bonus(d, 0, 1);
	else if (key == 'z')
		change_altitude_bonus(d, 1, 0);
	else if (key == 'c')
		change_altitude_bonus(d, 0, 0);
	else if (key == 'm')
		change_altitude_bonus(d, 0, 1);
	else if (key)
		aux_deal_keys(key, d);
	return (0);
}

static void	aux_deal_keys(int key, t_data *d)
{
	if (key == 'w')
		zoom_bonus(d, 1, 0, 0);
	else if (key == 's')
		zoom_bonus(d, 0, 1, 0);
	if (key == 'a' || key == 'd' || key == 'e' || key == 'x' || key == 'v' \
	|| key == 'q')
		reset_states(d);
	if (key == 'a')
		linear_transformations_bonus(d, &d->matrix->rot_y, 0);
	else if (key == 'd')
		linear_transformations_bonus(d, &d->matrix->rev_y, 0);
	else if (key == 'q')
		linear_transformations_bonus(d, &d->matrix->rot_x, 0);
	else if (key == 'e')
		linear_transformations_bonus(d, &d->matrix->rev_x, 0);
	else if (key == 'x')
		linear_transformations_bonus(d, &d->matrix->rot_z, 0);
	else if (key == 'v')
		linear_transformations_bonus(d, &d->matrix->rev_z, 0);
	else if (key == 'p')
		linear_transformations_bonus(d, (void *)d, 1);
	else if (key == 'g' && d->state.grid_style_nb == 1)
		d->state.grid_style_nb = 2;
	else if (key == 'g' && d->state.grid_style_nb == 2)
		d->state.grid_style_nb = 3;
	else if (key == 'g' && d->state.grid_style_nb == 3)
		d->state.grid_style_nb = 1;
}

static void	reset_states(t_data *d)
{
	d->state.isometric = 0;
	d->state.diagonal = 0;
	d->state.diagonal = 0;
}
