/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:14:16 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/04 19:01:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_BONUS_H
# define T_MAP_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "fdf_structs_bonus.h"
# include "linked_list_tools.h"

static void				find_vertical_center(t_data *d) __attribute__((unused));
static void				find_square_center(t_data *d);
static void				find_horizontal_center(t_data *d) __attribute__((unused));
typedef struct s_d		t_d;
static void				find_horizontal_center(t_d *d) __attribute__((unused));
static void				find_map_center(t_data *d) __attribute__((unused));
static t_point			**create_arrmap(t_map *map) __attribute__((unused));

typedef struct s_mp
{
	int					has_hexcolor;
	int					is_vertical;
	int					is_square;
	int					is_plateau;
	int					width;
	int					height;
	uint				size;
	short				max_z;
	short				min_z;
	double	 			max_x;
	double	 			min_x;
	double	 			max_y;
	double	 			min_y;
	double				initial_max_z;
	double				target_width;
	double				target_height;
	double				ratio;
	double 				radius;
	t_n					*pts;
	t_point				**arr;
	t_point				**(*create_arrmap)(t_map *map);
	t_func_ptr			get_center;
}						t_map;

static inline void	find_map_center(t_data *d)
{
	t_n	*central_node;

	find_vertical_center(d);
	find_horizontal_center(d);
	find_square_center(d);
	central_node = ft_lstpoint_getby_index(d->map->pts, d->center.index);
	set_t_center_coordinates(&d->center, central_node);
}

static inline void	find_vertical_center(t_data *d)
{
	if (!d->map->is_vertical)
		return ;
	d->center.index = (d->map->size + 1) / 2;
	d->center.index += are_height_and_width_even(d) * (d->map->width / 2);
}

static inline void	find_square_center(t_data *d)
{
	if (!d->map->is_square)
		return ;
	d->center.index = (d->map->size + 1) / 2;
	d->center.index += are_height_and_width_even(d) * (d->map->width / 2);
}

static inline void	find_horizontal_center(t_data *d)
{
	if (d->map->is_vertical)
		return ;
	d->center.index = d->map->size / 2;
	d->center.index += is_height_even(d->map->height) * (d->map->width / 2);
	d->center.index -= is_width_even(d->map->width) * (d->map->height / 2);
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
