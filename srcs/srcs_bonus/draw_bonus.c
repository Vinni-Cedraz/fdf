/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 23:47:42 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/27 22:25:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			flush_image(void);

int	draw_bonus(void)
{
	t_data	*d;
	void	*dis;
	void	*win;
	void	*img;

	d = get_data();
	img = d->img->ptr;
	win = d->mlx->win_ptr;
	dis = d->mlx->display_ptr;
	if (d->img->to_be_flushed)
	{
		flush_image();
		d->img->to_be_flushed = 1;
		if (d->offset->neutral_zoom)
			take_zoom_snapshot();
		ft_lstpoint_toarr(d->map->pts, d->map->width, d->map->arr);
		render_map_bonus();
		mlx_put_image_to_window(dis, win, img, 0, 0);
		draw_menu();
	}
	return (0);
}

void	flush_image(void)
{
	multi_threaded_workers((t_worker_task){.action = &paint_it_black});
}

void	*paint_it_black(t_worker_task *iter)
{
	t_data	*d;

	d = get_data();
	if (iter->col > d->scale->menu_width)
		put_pixel_img_bonus(d->img, iter->col, iter->row, BLACK);
	return (NULL);
}

int	get_img_start_idx(int thread_number)
{
	t_img	*img;
	int	img_size;
	int		remainder;

	if (1 == thread_number)
		return (0);
	img = get_data()->img;
	img_size = img->width * img->height;
	remainder = img_size % NUM_THREADS;
	return ((img_size / NUM_THREADS) * (thread_number - 1) + remainder);
}

int	get_img_end_idx(int thread_number)
{
	t_img	*img;
	uint	img_size;
	short	remainder;

	img = get_data()->img;
	img_size = img->width * img->height;
	remainder = img_size % NUM_THREADS;
	return ((img_size / NUM_THREADS) * thread_number + remainder);
}
