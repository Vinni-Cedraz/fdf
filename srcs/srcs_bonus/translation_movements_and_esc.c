/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 01:25:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	move_right(t_data *d);
static void	move_left(t_data *d);
static void	move_up(t_data *d);
static void	move_down(t_data *d);

int	translation_movements_and_esc(int key, t_data *d)
{
	if (key == XK_ESCAPE)
		close_win(d);
	if (key == XK_RIGHT)
		move_right(d);
	if (key == XK_LEFT)
		move_left(d);
	if (key == XK_UP)
		move_up(d);
	if (key == XK_DOWN)
		move_down(d);
	return (0);
}

static void	move_right(t_data *d)
{
	blackout(d);
	d->move_x += 25;
	render_map(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

static void	move_left(t_data *d)
{
	blackout(d);
	d->move_x -= 25;
	render_map(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

static void	move_up(t_data *d)
{
	blackout(d);
	d->move_y -= 25;
	render_map(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

static void	move_down(t_data *d)
{
	blackout(d);
	d->move_y += 25;
	render_map(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}
