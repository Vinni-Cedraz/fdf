/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_win_n_img_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:39:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/26 12:49:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static inline void	open_mlx_and_create_window(t_data *d);
static inline void	create_image(t_data *d);
static inline void	get_image_data_address(t_data *d);
static inline void	set_image_dimensions(t_data *d);

void	open_win_and_img_bonus(t_data *d)
{
	open_mlx_and_create_window(d);
	create_image(d);
	get_image_data_address(d);
	set_image_dimensions(d);
}

static inline void	open_mlx_and_create_window(t_data *d)
{
	d->mlx->ptr = mlx_init();
	d->mlx->win_ptr = mlx_new_window(d->mlx->ptr, WIN_WDTH, WIN_HGHT, "mlx 42");
}

static inline void	create_image(t_data *d)
{
	d->img->ptr = mlx_new_image(d->mlx->ptr, WIN_WDTH, WIN_HGHT);
}

static inline void	get_image_data_address(t_data *d)
{
	int	*bpp;
	int	*endian;
	int	*line_len;

	bpp = &d->img->bpp;
	endian = &d->img->endian;
	line_len = &d->img->line_len;
	d->img->addr = mlx_get_data_addr(d->img->ptr, bpp, line_len, endian);
}

static inline void	set_image_dimensions(t_data *d)
{
	d->img->width = WIN_WDTH;
	d->img->height = WIN_HGHT;
}
