/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:08:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 17:35:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_data			*pre_parse_allocations(void);
static void				pre_draw_allocations(void);
static void				draw_first_frame(void);

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	t_data	*d;

	d = get_data();
	d = pre_parse_allocations();
	d->tool.argv = argv[1];
	if (!is_a_valid_file())
		error_handler();
	if (argc != 2)
		error_handler();
	(void)argc;
	initialize_methods_bonus();
	parse_map_bonus();
	pre_draw_allocations();
	data_initializer_bonus();
	draw_first_frame();
	mlx_loop_hook(d->mlx->display_ptr, &draw_bonus, d);
	mlx_hook(d->mlx->win_ptr, 02, 1L << 0, &deal_keys_bonus, d);
	mlx_hook(d->mlx->win_ptr, 17, 0, &close_win_bonus, d);
	mlx_loop(d->mlx->display_ptr);
}

static inline t_data	*pre_parse_allocations(void)
{
	t_data	*d;

	d = get_data();
	d->offset = ft_calloc(sizeof(*d->offset), 1);
	d->scale = ft_calloc(sizeof(*d->scale), 1);
	d->map = ft_calloc(sizeof(*d->map), 1);
	d->color = ft_calloc(sizeof(*d->color), 1);
	return (d);
}

static inline void	pre_draw_allocations(void)
{
	t_data	*d;

	d = get_data();
	d->img = ft_calloc(sizeof(*d->img), 1);
	d->matrix = ft_calloc(sizeof(*d->matrix), 1);
	d->mlx = malloc(sizeof(*d->mlx));
	d->map->arr = d->map->create_arrmap(d->map);
	d->lookup.events = ft_calloc(128, sizeof(*d->lookup.events));
}

static inline void	draw_first_frame(void)
{
	void	*dis;
	void	*win;
	void	*img;
	t_data	*d;

	d = get_data();
	dis = d->mlx->display_ptr;
	win = d->mlx->win_ptr;
	img = d->img->ptr;
	ft_lstpoint_toarr(d->map->pts, d->map->width, d->map->arr);
	render_map_bonus();
	draw_menu();
	mlx_put_image_to_window(dis, win, img, 0, 0);
	draw_menu();
}
