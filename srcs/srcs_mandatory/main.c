/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:00:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/07 00:00:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	(void)argc;
	d = ft_calloc(sizeof(t_data), 1);
	d->img = malloc(sizeof(t_img));
	if (!parse_map(argv[1], d))
		return (0);
	data_initializer(d);
	mlx_loop_hook(d->mlx_ptr, draw, d);
	mlx_hook(d->win_ptr, 02, 1L << 0, deal_key, d);
	mlx_hook(d->win_ptr, 17, 0, close_win, d);
	mlx_loop(d->mlx_ptr);
	free(d->img);
}
