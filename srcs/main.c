/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */ /*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */ /*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2022/12/03 11:51:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/03 14:07:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"


int	main(int argc, char **argv)
{
	t_img		img;
	t_data		data;
	t_square	red_square;
	t_square	white_square;

	(void)argc;
	(void)argv;
	red_square.width_start = 125;
	red_square.height_start = 125;
	red_square.total_width = 375;
	red_square.total_height = 375;
	white_square.width_start = 0;
	white_square.height_start = 0;
	white_square.total_width = 500;
	white_square.total_height = 500;
	open_win_n_img(&data, &img);
	render_square(&img, WHITE, &white_square);
	render_square(&img, RED, &red_square);
	render_line((t_point){0, 0, 0}, (t_point){500, 500, 0}, RED, &img);
	render_line((t_point){500, 0, 0}, (t_point){0, 500, 0}, RED, &img);
	// render_map(open(argv[1], O_RDONLY));
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.mlx_img, 0, 0);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
}
