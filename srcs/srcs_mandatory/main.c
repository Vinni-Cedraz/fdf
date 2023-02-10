/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:00:00 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/09 20:28:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static int	handle_argument_error(t_data *d);
static int	handle_create_map_error(t_data *d);

int	main(int argc, char **argv)
{
	t_data	*d;
	int		error;

	(void)argc;
	d = ft_calloc(sizeof(t_data), 1);
	d->img = malloc(sizeof(t_img));
	d->argv = argv;
	d->map = malloc(sizeof(t_map));
	error = parse_map(d->argv[1], d);
	if (error == -1)
		return (handle_argument_error(d));
	else if (error == -2)
		return (handle_create_map_error(d));
	data_initializer(d);
	mlx_loop_hook(d->mlx_ptr, draw, d);
	mlx_hook(d->win_ptr, 02, 1L << 0, deal_key, d);
	mlx_hook(d->win_ptr, 17, 0, close_win, d);
	mlx_loop(d->mlx_ptr);
	return (0);
}

static int	handle_argument_error(t_data *d)
{
	free(d->img);
	free(d->map);
	free(d);
	ft_printf("%s\n", strerror(22));
	return (0);
}

static int	handle_create_map_error(t_data *d)
{
	free(d->img);
	ft_free_arr((char **)d->map->arr, (void **)d->map->arr);
	free(d->map);
	free(d);
	ft_printf("%s\n", strerror(22));
	return (0);
}
