/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 11:06:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			free_simple_pointers(t_data *d);
static void			free_complex_pointers(t_data *d);

void	call_close_window(t_data *d)
{
	close_win_bonus(d);
}

int	close_win_bonus(t_data *d)
{
	mlx_destroy_image(d->mlx->ptr, d->img->ptr);
	mlx_destroy_window(d->mlx->ptr, d->mlx->win_ptr);
	mlx_destroy_display(d->mlx->ptr);
	free_simple_pointers(d);
	free_complex_pointers(d);
	free(d->map);
	free(d);
	exit(0);
}

static inline void	free_simple_pointers(t_data *d)
{
	free(d->mlx->ptr);
	free(d->mlx);
	free(d->img);
	free(d->offset);
	free(d->matrix);
	free(d->lookup.events);
	free(d->c);
}

static inline void	free_complex_pointers(t_data *d)
{
	ft_free_arr_size((void **)d->map->arr, d->map->height);
	ft_lstpoint_free(&d->map->pts);
	ft_lstcircular_free(&d->lookup.iso_transit_methods);
	ft_lstcircular_free(&d->lookup.grid_methods);
}
