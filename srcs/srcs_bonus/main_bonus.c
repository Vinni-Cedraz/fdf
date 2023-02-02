/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:08:03 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/02 12:43:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_data			*pre_parse_allocations(void);
static void				pre_draw_allocations(t_data *d);

int	main(int argc, char **argv)
{
	t_data	*d;

	(void)argc;
	d = pre_parse_allocations();
	d->tool.argv = argv[1];
	if (!parse_map_bonus(d))
		return (free(d->map), free(d->offset), free(d), 0);
	pre_draw_allocations(d);
	data_initializer_bonus(d);
	mlx_loop_hook(d->mlx->ptr, draw_bonus, d);
	mlx_hook(d->mlx->win_ptr, 02, 1L << 0, deal_keys_bonus, d);
	mlx_hook(d->mlx->win_ptr, 17, 0, close_win_bonus, d);
	mlx_loop(d->mlx->ptr);
}

static inline t_data	*pre_parse_allocations(void)
{
	t_data	*d;

	d = ft_calloc(sizeof(*d), 1);
	d->offset = ft_calloc(sizeof(*d->offset), 1);
	d->map = ft_calloc(sizeof(*d->map), 1);
	return (d);
}

static inline void	pre_draw_allocations(t_data *d)
{
	d->img = ft_calloc(sizeof(*d->img), 1);
	d->matrix = ft_calloc(sizeof(*d->matrix), 1);
	d->mlx = malloc(sizeof(*d->mlx));
	d->lookup.events = ft_calloc(128, sizeof(*d->lookup.events));
}
