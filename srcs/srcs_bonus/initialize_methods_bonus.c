/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_methods_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:40:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 20:07:14 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			init_t_scale_and_offset(t_scale *scale, t_offset *offset);
static void			init_t_color(t_color *color);
static void			init_t_lookup(t_lookup *lookup);
static void			init_t_map(t_map *map);

void	initialize_methods_bonus(t_data *d)
{
	init_t_map(d->map);
	init_t_scale_and_offset(d->scale, d->offset);
	init_t_color(d->color);
	init_t_lookup(&d->lookup);
}

static inline void	init_t_scale_and_offset(t_scale *scale, t_offset *offset)
{
	scale->create_t_scale = &set_t_scale_attributes;
	scale->calculate_win_factor = &calculate_win_factor;
	offset->set_initial_offset = &calculate_initial_offset;
	offset->move[0] = &up;
	offset->move[1] = &down;
	offset->move[2] = &left;
	offset->move[3] = &right;
}

static inline void	init_t_color(t_color *color)
{
	color->create_hsl_map = &create_hsl_map;
	color->create_rgb_map = &create_rgb_map;
}

static inline void	init_t_lookup(t_lookup *lookup)
{
	lookup->hash_function = &hash_function;
	lookup->set_event_index_by_key = &set_event_index_by_key;
}

static inline void	init_t_map(t_map *map)
{
	map->set_radius = &set_radius;
	map->get_map_center = &get_map_center;
	map->create_arrmap = &create_arrmap;
}
