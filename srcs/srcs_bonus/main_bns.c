/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:00:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/19 15:30:49 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	main(int argc, char **argv)
{
	t_data	d;

	(void)argc;
	d.img = malloc(sizeof(t_img));
	if (!parse_map_bns(argv[1], &d))
		return (0);
	open_win_n_img_bns(&d);
	colorize_bns(d.map);
	d.clockwise = 0;
	d.counter_clock = 0;
	d.move_x = 0;
	d.move_y = 0;
	render_map_bns(&d);
	mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img->mlx_img, 0, 0);
	mlx_key_hook(d.win_ptr, deal_keys, &d);
	mlx_hook(d.win_ptr, 17, 0, close_win_bns, &d);
	mlx_loop(d.mlx_ptr);
	free(d.img);
}
