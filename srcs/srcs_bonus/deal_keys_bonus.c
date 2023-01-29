/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 12:08:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			aux_deal_keys(int key, t_data *d);
static void			aux_aux_deal_keys(int key, t_data *d);
static void			rotate_five_around_y(t_data *d);
static void			reverse_five_around_y(t_data *d);

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
	else if ((key == 'i' || key == ' '))
		two_steps_to_isometry_bonus(d, (t_isometry_changer){&apply_iso_steps});
	else if (key == ';' && !d->state.parallel)
		two_steps_to_isometry_bonus(d, (t_isometry_changer){&restore_snapshot});
	else if (key)
		aux_deal_keys(key, d);
	return (0);
}

static void	aux_deal_keys(int key, t_data *d)
{
	if (key == 'w')
		zoom_bonus(d, &zoom_in);
	else if (key == 's')
		zoom_bonus(d, &zoom_out);
	else if (key == 'g')
		change_grid_rendering_method(d);
	else if (key == 'z')
		change_altitude_bonus(d, (t_zscaler){&z_up_method});
	else if (key == 'c')
		change_altitude_bonus(d, (t_zscaler){&z_down_method});
	else if (key == 'm')
		change_altitude_bonus(d, (t_zscaler){&z_mirror_method});
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

static inline void	rotate_five_around_y(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_y);
	reset_states(d);
}

static inline void	reverse_five_around_y(t_data *d)
{
	if (d->state.diagonal || d->state.parallel)
		return ;
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_y);
	reset_states(d);
}
