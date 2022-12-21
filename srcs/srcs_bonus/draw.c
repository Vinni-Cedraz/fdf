/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 04:31:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	draw(t_data *d)
{
	blackout_bns(d);
	colorize_bns(d->map);
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
	return (0);
}
