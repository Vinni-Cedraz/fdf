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
	t_square	white_square;

	(void)argc;
	data.img = malloc(sizeof(t_img));
	define_square(&white_square, (t_point){0, 0, 0, WHITE}, \
	(t_point){1920, 1920, 0, WHITE}),
	open_win_n_img(&data);
	render_square(data.img, WHITE, &white_square);
	parse_map(argv[1], &data);
	rotate_map(data.map);
	render_map(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
	data.img->mlx_img, 0, 0);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	free(data.img);
}
