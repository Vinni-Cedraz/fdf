/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:00:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 20:45:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	d = ft_calloc(1, sizeof(t_data));
	(void)argc;
	if (!parse_map(argv[1], d))
		return (0);
	open_win_n_img(d);
	colorize(d->map);
	d->offset->move_x = 0;
	d->offset->move_y = 0;
	rotate_map(d->map);
	render_map(d);
	mlx_put_image_to_window(d->mlx->ptr, d->mlx->win, d->img->ptr, 0, 0);
	mlx_key_hook(d->mlx->win, deal_key, d);
	mlx_hook(d->mlx->win, 17, 0, close_win, d);
	mlx_loop(d->mlx->ptr);
	free(d);
}
