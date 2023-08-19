/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_win_n_img_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:39:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/27 00:03:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static inline void	create_display_and_window(t_data *d);
static inline void	create_image(t_data *d);
static inline void	set_image_dimensions(t_data *d);

void	open_win_and_img_bonus(t_data *d)
{
	create_display_and_window(d);
	create_image(d);
	set_image_dimensions(d);
	d->img->to_be_flushed = 0;
}

static inline void	create_display_and_window(t_data *d)
{
	void	*dis;

	dis = d->mlx->display_ptr;
	d->mlx->display_ptr = mlx_init();
	d->mlx->win_ptr = mlx_new_window(dis, WIN_WDTH, WIN_HGHT, "mlx 42");
}

static inline void	create_image(t_data *d)
{
	int	*bpp;
	int	*endian;
	int	*line_len;

	d->img->ptr = mlx_new_image(d->mlx->display_ptr, WIN_WDTH, WIN_HGHT);
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
