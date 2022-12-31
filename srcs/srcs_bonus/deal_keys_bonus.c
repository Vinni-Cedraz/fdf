/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 14:57:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	aux_deal_keys(int *key, t_data *d);

int	deal_keys_bonus(int key, t_data *d)
{
	if (key == XK_ESCAPE)
		close_win_bonus(d);
	else if (key == XK_RIGHT || key == 'l')
		d->move_x += 100;
	else if (key == XK_LEFT || key == 'h')
		d->move_x -= 100;
	else if (key == XK_UP || key == 'k')
		d->move_y -= 100;
	else if (key == XK_DOWN || key == 'j')
		d->move_y += 100;
	else if (key == 'i')
		two_steps_to_isometry_bonus(d, 0);
	else if (key == 'r')
		undo_isometric_steps_bonus(d);
	else if (key == ';')
		two_steps_to_isometry_bonus(d, 1);
	else if (key)
		aux_deal_keys(&key, d);
	return (0);
}

static void	aux_deal_keys(int *key, t_data *d)
{
	if (*key == 'z')
		change_altitude_bonus(d, 1, 0);
	else if (*key == 'c')
		change_altitude_bonus(d, 0, 0);
	else if (*key == 'm')
		change_altitude_bonus(d, 0, 1);
	else if (*key == 'w')
		zoom_bonus(d, 1, 0, 0);
	else if (*key == 's')
		zoom_bonus(d, 0, 1, 0);
	else if (*key == 'a')
		rotate_around_y(d, 1, 0);
	else if (*key == 'd')
		rotate_around_y(d, 0, 1);
	else if (*key == 'q')
		rotate_around_x(d, 1, 0);
	else if (*key == 'e')
		rotate_around_x(d, 0, 1);
	else if (*key == 'g' && !ft_strncmp(d->grid_style, "square", 4))
	{
		free(d->grid_style);
		d->grid_style = ft_strdup("cross");
	}
	else if (*key == 'g' && !ft_strncmp(d->grid_style, "cross", 4))
	{
		free(d->grid_style);
		d->grid_style = ft_strdup("square");
	}
}
