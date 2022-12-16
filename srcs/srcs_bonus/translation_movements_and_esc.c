/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_movements_and_esc.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:15:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 15:09:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	move_right(t_data *d);
static void	move_left(t_data *d);
static void	move_up(t_data *d);
static void	move_down(t_data *d);
static void	apply_isometry(t_data *d);

int	translation_movements_and_esc(int key, t_data *d)
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
	return (0);
}
//
// static void	apply_isometry(t_data *d)
// {
// 	mlx_clear_window(d->mlx_ptr, d->win_ptr);
// 	mlx_destroy_image(d->mlx_ptr, d->img->mlx_img);
// 	d->img->mlx_img = mlx_new_image(d->mlx_ptr, d->img->width, d->img->height);
// 	d->img->addr = mlx_get_data_addr(d->img->mlx_img, &d->img->bpp, \
// 	&d->img->width, &d->img->endian);
// 	rotate_map_bns(d->map);
// 	render_map_bns(d);
// 	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
// }

static void	apply_isometry(t_data *d)
{	
	blackout_bns(d);
	rotate_map_bns(d->map);
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

static void	move_right(t_data *d)
{
	blackout_bns(d);
	d->move_x += 100;
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

static void	move_left(t_data *d)
{
	blackout_bns(d);
	d->move_x -= 100;
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

static void	move_up(t_data *d)
{
	blackout_bns(d);
	d->move_y -= 100;
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}

static void	move_down(t_data *d)
{
	blackout_bns(d);
	d->move_y += 100;
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
}
