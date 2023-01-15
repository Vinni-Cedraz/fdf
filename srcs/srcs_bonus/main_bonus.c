/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:08:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/15 20:11:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	(void)argc;
	d = ft_calloc(sizeof(t_data), 1);
	d->tool.argv = argv[1];
	d->map = calloc(sizeof(t_map), 1);
	d->img = calloc(sizeof(t_img), 1);
	if (!parse_map_bonus(d))
		return (0);
	data_initializer_bonus(d);
	mlx_loop_hook(d->mlx->mlx_ptr, draw_bonus, d);
	mlx_hook(d->mlx->win_ptr, 02, 1L << 0, deal_keys_bonus, d);
	mlx_hook(d->mlx->win_ptr, 17, 0, close_win_bonus, d);
	mlx_loop(d->mlx->mlx_ptr);
}
