/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:14:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/12 22:37:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_BONUS_H
# define T_MAP_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "fdf_t_data_bonus.h"
# include "linked_list_tools.h"

typedef struct s_d		t_d;
static void				get_map_center(t_data *d) __attribute__((unused));
static t_point			**create_arrmap(t_map *map) __attribute__((unused));

typedef struct s_ba
{
	double				center_x;
	double				center_y;
	double				center_z;
	double				delta;
}						t_ball;

typedef struct s_ctr
{
	double				x;
	double				y;
	double				z;
	int					index;
}						t_center;

typedef struct s_mp
{
	int					has_hexcolor;
	int					is_vertical;
	int					is_plateau;
	double				width;
	double				height;
	uint				size;
	double				max_z;
	double				min_z;
	double				max_x;
	double				min_x;
	double				max_y;
	double				min_y;
	double				initial_max_z;
	double				target_width;
	double				target_height;
	double				ratio;
	double				radius;
	t_ball				ball;
	t_n					*pts;
	t_point				**arr;
	t_center			center;
}						t_map;

static inline void	get_map_center(t_data *d)
{
	t_map	*map;

	map = d->map;
	map->center.x = (map->max_x + map->min_x) / 2;
	map->center.y = (map->max_y + map->min_y) / 2;
	map->center.z = (map->max_z + map->min_z) / 2;
}

static inline t_point	**create_arrmap(t_map *map)
{
	int		i;
	int		j;
	t_point	point;
	t_point	**arr;

	i = -1;
	j = 0;
	arr = malloc((map->height) * sizeof(t_point *));
	while (++i < map->height)
	{
		if (j == 0)
			arr[i] = malloc(map->width * sizeof(t_point));
		ft_bzero((char *)&point, sizeof(point));
		arr[i][j] = point;
	}
	return (arr);
}

#endif
