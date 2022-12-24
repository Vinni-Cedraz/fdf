/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:00:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/21 05:19:02 by vcedraz-         ###   ########.fr       */
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
	data_initializer(&d);
	open_win_n_img_bns(&d);
	mlx_loop_hook(d.mlx_ptr, &draw, &d);
	mlx_hook(d.win_ptr, 02, 1L << 0, &deal_keys, &d);
	mlx_hook(d.win_ptr, 17, 0, &close_win_bns, &d);
	mlx_loop(d.mlx_ptr);
	free(d.img);
}
