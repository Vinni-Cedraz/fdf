/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:00:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 02:53:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf_includes_bonus.h"

int	main(int argc, char **argv)
{
	t_data		data;

	(void)argc;
	data.img = malloc(sizeof(t_img));
	if (!parse_map_bns(argv[1], &data))
		return (0);
	open_win_n_img_bns(&data);
	colorize_bns(data.map);
	data.move_x = 0;
	data.move_y = 0;
	rotate_map_bns(data.map);
	render_map_bns(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, \
	data.img->mlx_img, 0, 0);
	mlx_key_hook(data.win_ptr, translation_movements_and_esc, &data);
	mlx_hook(data.win_ptr, 17, 0, close_win_bns, &data);
	mlx_loop(data.mlx_ptr);
	free(data.img);
}
