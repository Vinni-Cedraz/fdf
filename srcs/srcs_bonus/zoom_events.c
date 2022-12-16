/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 01:36:11 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 02:34:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	zoom_in(t_data *d);
static void	zoom_out(t_data *d);

int	zoom_events(int key, t_data *d)
{
	if (key == XK_KP_ADD)
		zoom_in(d);
	if (key == XK_KP_SUBTRACT)
		zoom_out(d);
	return (0);
}

static void	zoom_in(t_data *d)
{
	blackout(d);
	d->scale_x += 1;
	d->scale_y += 1;
	d->scale_x += 20;
	d->scale_y += 20;
	render_map(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
}

static void	zoom_out(t_data *d)
{
	blackout(d);
	d->scale_x -= 1;
	d->scale_y -= 1;
	d->scale_x -= 20;
	d->scale_y -= 20;
	render_map(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
}
