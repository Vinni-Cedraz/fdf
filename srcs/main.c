/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+ 
	+:+       +#+        */
/*                                               
	+#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:51:05 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/03 14:07:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_square	red_square;
	t_square	white_square;

	(void)argc;
	data.img = malloc(sizeof(t_img));
	define_square(&red_square, (t_point){125, 125, 0, 0}, \
	(t_point){375, 375, 0, 0});
	define_square(&white_square, (t_point){0, 0, 0, 0}, \
	(t_point){500, 500, 0, 0});
	open_win_n_img(&data);
	render_square(data.img, WHITE, &white_square);
	render_square(data.img, RED, &red_square);
	render_line((t_point){0, 0, 0, 0}, (t_point){500, 500, 0, 0}, RED, \
	data.img);
	render_line((t_point){500, 0, 0, 0}, (t_point){0, 500, 0, 0}, RED, \
	data.img);
	parse_map(argv[1], &data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
	data.img->mlx_img, 0, 0);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	free(data.img);
}
