/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:36 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/25 12:06:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			free_simple_pointers(void);
static void			free_complex_pointers(void);

void	call_close_window(void)
{
	close_win_bonus();
}

int	close_win_bonus(void)
{
	t_data	*d;

	d = get_data();
	mlx_destroy_image(d->mlx->display_ptr, d->img->ptr);
	mlx_destroy_window(d->mlx->display_ptr, d->mlx->win_ptr);
	mlx_destroy_display(d->mlx->display_ptr);
	free_simple_pointers();
	free_complex_pointers();
	free(d->map);
	exit(0);
}

static inline void	free_simple_pointers(void)
{
	t_data	*d;

	d = get_data();
	free(d->mlx->display_ptr);
	free(d->mlx);
	free(d->img);
	free(d->offset);
	free(d->scale);
	free(d->matrix);
	free(d->lookup.events);
	free(d->color);
}

static inline void	free_complex_pointers(void)
{
	t_data	*d;

	d = get_data();
	ft_free_arr_size((void **)d->map->arr, d->map->height);
	ft_lstpoint_free(&d->map->pts);
	ft_lstcircular_free(&d->lookup.transition_methods);
	ft_lstcircular_free(&d->lookup.grid_methods);
}
