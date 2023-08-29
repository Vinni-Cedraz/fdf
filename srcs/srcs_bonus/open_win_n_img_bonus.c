/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_win_n_img_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:37:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/21 17:37:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static inline void	create_display_and_window(void);
static inline void	create_image(void);
static inline void	set_image_dimensions(void);

void	open_win_and_img_bonus(void)
{
	create_display_and_window();
	create_image();
	set_image_dimensions();
	get_data()->img->to_be_flushed = 0;
}

static inline void	create_display_and_window(void)
{
	void	*dis;
	t_data	*d;

	d = get_data();
	d->mlx->display_ptr = mlx_init();
	dis = d->mlx->display_ptr;
	d->mlx->win_ptr = mlx_new_window(dis, WIN_WDTH, WIN_HGHT, "mlx 42");
}

static inline void	create_image(void)
{
	t_data	*d;
	int		*bpp;
	int		*endian;
	int		*line_len;

	d = get_data();
	d->img->ptr = mlx_new_image(d->mlx->display_ptr, WIN_WDTH, WIN_HGHT);
	bpp = &d->img->bpp;
	endian = &d->img->endian;
	line_len = &d->img->line_len;
	d->img->addr = mlx_get_data_addr(d->img->ptr, bpp, line_len, endian);
}

static inline void	set_image_dimensions(void)
{
	get_data()->img->width = WIN_WDTH;
	get_data()->img->height = WIN_HGHT;
}
