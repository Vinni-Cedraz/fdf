/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/20 19:20:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	reset_states(t_data *d);
static void	aux_deal_keys(int key, t_data *d);
static void	aux_aux_deal_keys(int key, t_data *d);

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
	else if (key == 'i' || key == ' ')
		two_steps_to_isometry_bonus(d, (t_isometry_changer){&apply_iso_steps});
	else if (key == 'r')
		two_steps_to_isometry_bonus(d, (t_isometry_changer){&undo_iso_steps});
	else if (key == ';' && !d->state.parallel)
		two_steps_to_isometry_bonus(d,(t_isometry_changer){&restore_snapshot});
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
	if (key == 'a' || key == 'd' || key == 'e' || key == 'x' || key == 'v'
		|| key == 'q')
		reset_states(d);
	if (key == 'a' && !d->state.parallel)
		transpts_with_given_matrix_bonus(d, &d->matrix->rot_y);
	else if (key == 'd' && !d->state.parallel)
		transpts_with_given_matrix_bonus(d, &d->matrix->rev_y);
	else if (key == 'q' && !d->state.parallel)
		transpts_with_given_matrix_bonus(d, &d->matrix->rot_x);
	else if (key == 'e' && !d->state.parallel)
		transpts_with_given_matrix_bonus(d, &d->matrix->rev_x);
	else if (key == 'x' && !d->state.parallel)
		transpts_with_given_matrix_bonus(d, &d->matrix->rot_z);
	else if (key == 'v' && !d->state.parallel)
		transpts_with_given_matrix_bonus(d, &d->matrix->rev_z);
	else if (key)
		aux_aux_deal_keys(key, d);
}

static void	aux_aux_deal_keys(int key, t_data *d)
{
	if (key == 'g' && d->state.grid_style_nb == 1)
		d->state.grid_style_nb = 2;
	else if (key == 'g' && d->state.grid_style_nb == 2)
		d->state.grid_style_nb = 3;
	else if (key == 'g' && d->state.grid_style_nb == 3)
		d->state.grid_style_nb = 1;
	else if (key == 'z')
		change_altitude_bonus(d, (t_zscaler){&scale_z_up});
	else if (key == 'c')
		change_altitude_bonus(d, (t_zscaler){&scale_z_down});
	else if (key == 'm')
		change_altitude_bonus(d, (t_zscaler){&scale_z_mirror});
}

static void	reset_states(t_data *d)
{
	d->state.isometric = 0;
	d->state.diagonal = 0;
	d->state.diagonal = 0;
}
