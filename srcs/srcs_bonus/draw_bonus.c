/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:47:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 17:35:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			paint_it_black(void);
static void			put_pixel_img_bonus(t_img *img, int x, int y, int color);

int	draw_bonus(void)
{
	void	*dis;
	void	*win;
	void	*img;
	t_data	*d;

	d = get_data();
	img = d->img->ptr;
	win = d->mlx->win_ptr;
	dis = d->mlx->display_ptr;
	if (d->img->to_be_flushed)
	{
		paint_it_black();
		d->img->to_be_flushed = 0;
		ft_lstpoint_toarr(d->map->pts, d->map->width, d->map->arr);
		if (d->offset->neutral_zoom)
			take_zoom_snapshot();
		render_map_bonus();
		mlx_put_image_to_window(dis, win, img, 0, 0);
		draw_menu();
	}
	return (0);
}

static inline void	paint_it_black(void)
{
	t_data	*d;
	int		counter;
	int		img_size;
	int		i;
	int		j;

	d = get_data();
	counter = 0;
	img_size = d->img->width * d->img->height;
	while (counter < img_size)
	{
		counter++;
		i = counter / d->img->height;
		if (i >= d->scale->menu_width)
		{
			j = counter % d->img->height;
			put_pixel_img_bonus(d->img, i, j, BLACK);
		}
	}
}

static inline void	put_pixel_img_bonus(t_img *img, int x, int y, int color)
{
	char	*ptr_to_color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	ptr_to_color = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)ptr_to_color = color;
}
