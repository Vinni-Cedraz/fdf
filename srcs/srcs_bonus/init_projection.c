/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camerastuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:56:08 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 01:16:36 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

t_projection	init_projection(t_map *map)
{
	t_projection	camera;
	int				zoom1;
	int				zoom2;

	zoom1 = (((WINDOW_WIDTH - X_MENU) / map->width) / 2);
	zoom2 = ((WINDOW_HEIGHT / map->height) / 2);
	if (zoom1 < zoom2)
		camera.zoom = zoom1;
	else
		camera.zoom = zoom2;
	camera.alpha = 0;
	camera.beta = 0;
	camera.gamma = 0;
	camera.z_divisor = 1;
	camera.x_offset = 0;
	camera.y_offset = 0;
	return (camera);
}
