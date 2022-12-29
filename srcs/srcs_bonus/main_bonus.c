/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:08:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 22:27:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	(void)argc;
	d = malloc(sizeof(t_data));
	data_initializer(d);
	if (!parse_map_bonus(argv[1], d))
		return (0);
	open_win_n_img_bonus(d);
	mlx_loop_hook(d->mlx, &draw, d);
	mlx_hook(d->mlx->win, 02, 1l << 0, &deal_keys, d);
	mlx_hook(d->mlx->win, 17, 0, close_win_bonus, d);
	mlx_loop(d->mlx->ptr);
	free(d->img);
}
