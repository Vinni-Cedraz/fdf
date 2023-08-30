/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:14:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:30:53 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_BONUS_H
# define T_MAP_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "fdf_t_data_bonus.h"
# include "linked_list_tools.h"
# include "t_scale_bonus.h"
# include <math.h>
# include <stddef.h>

typedef struct s_d		t_d;
static void				get_map_center(void) __attribute__((unused));
static t_point			***create_arrmap(t_map *map) __attribute__((unused));
static void				set_radius(void) __attribute__((unused));

typedef struct s_ba
{
	float				center_x;
	float				center_y;
	float				center_z;
	float				delta;
}						t_ball;

typedef struct s_ctr
{
	float				x;
	float				y;
	float				z;
}						t_center;

typedef struct s_mp
{
	int					has_hexcolor;
	int					is_vertical;
	int					is_plateau;
	float				width;
	float				height;
	size_t				size;
	float				max_z;
	float				min_z;
	float				max_x;
	float				min_x;
	float				max_y;
	float				min_y;
	float				initial_max_z;
	float				target_width;
	float				target_height;
	float				ratio;
	float				radius;
	t_ball				ball;
	t_n					*pts;
	t_point				***arr;
	t_center			center;
	t_func_ptr			set_radius;
	t_func_ptr			get_map_center;
	t_point				***(*create_arrmap)(struct s_mp *map);
}						t_map;

static inline void	get_map_center(void)
{
	t_map	*map;

	map = get_data()->map;
	map->center.x = (map->max_x + map->min_x) / 2;
	map->center.y = (map->max_y + map->min_y) / 2;
	map->center.z = (map->max_z + map->min_z) / 2;
}

static inline void	set_radius(void)
{
	t_data	*d;
	float	ball_sz_factor;
	float	map_sz;

	d = get_data();
	map_sz = d->map->size;
	ball_sz_factor = d->scale->size_factor;
	if (ball_sz_factor > 1.6)
		ball_sz_factor = 1.6;
	if (ball_sz_factor < 0.417)
		ball_sz_factor = 0.1;
	d->map->radius = sqrt((map_sz / ball_sz_factor) / (PI * ball_sz_factor));
}

static inline t_point	***create_arrmap(t_map *map)
{
	int		i;
	t_point	***arr;

	i = -1;
	arr = malloc((map->height) * sizeof(t_point **));
	while (++i < map->height)
	{
		arr[i] = malloc(map->width * sizeof(t_point *));
	}
	return (arr);
}

#endif
