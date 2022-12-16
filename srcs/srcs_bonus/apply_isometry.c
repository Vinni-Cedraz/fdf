/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:58 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 16:21:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	apply_isometry(t_data *d)
{
	blackout_bns(d);
	rotate_map_bns(d->map);
	render_map_bns(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img->mlx_img, 0, 0);
	return (0);
}
