/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/29 18:11:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	close_win_bonus(t_data *d)
{
	mlx_destroy_image(d->mlx->ptr, d->img->ptr);
	mlx_destroy_window(d->mlx->ptr, d->mlx->win_ptr);
	mlx_destroy_display(d->mlx->ptr);
	free(d->mlx->ptr);
	free(d->mlx);
	free(d->img);
	free(d->offset);
	free(d->matrix);
	ft_lstpoint_free(&d->map->pts);
	ft_lstcircular_free(&d->lookup.iso_transit_methods);
	ft_lstcircular_free(&d->lookup.grid_methods);
	free(d->map);
	free(d);
	exit(0);
}
