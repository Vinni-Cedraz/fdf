/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 05:08:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	draw(t_data *d)
{
	blackout_bonus(d);
	colorize_bonus(d->map);
	render_map_bonus(d);
	draw_menu_background(d->img);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
	draw_menu(d);
	return (0);
}
