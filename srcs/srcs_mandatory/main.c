/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:00:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/08 17:14:29 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	(void)argc;
	d = ft_calloc(sizeof(t_data), 1);
	d->img = malloc(sizeof(t_img));
	d->argv = argv;
	if (!parse_map(d->argv[1], d))
		return (0);
	data_initializer(d);
	mlx_loop_hook(d->mlx_ptr, draw, d);
	mlx_hook(d->win_ptr, 02, 1L << 0, deal_key, d);
	mlx_hook(d->win_ptr, 17, 0, close_win, d);
	mlx_loop(d->mlx_ptr);
	free(d->img);
}
