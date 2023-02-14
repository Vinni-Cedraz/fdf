/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_methods_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:40:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 14:51:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			initialize_t_scale_methods(t_scale *scale);
static void			initialize_t_color_methods(t_color *color);
static void			initialize_t_lookup_methods(t_lookup *lookup);
static void			initialize_t_map_methods(t_map *map);

void	initialize_methods_bonus(t_data *d)
{
	initialize_t_map_methods(d->map);
	initialize_t_scale_methods(d->scale);
	initialize_t_color_methods(d->color);
	initialize_t_lookup_methods(&d->lookup);
}

static inline void	initialize_t_scale_methods(t_scale *scale)
{
	scale->create_t_scale = &set_t_scale_attributes;
	scale->set_target_width = &set_target_width;
	scale->set_target_height = &set_target_height;
	scale->calculate_win_factor = &calculate_win_factor;
}

static inline void	initialize_t_color_methods(t_color *color)
{
	color->create_hsl_map = &create_hsl_map;
	color->create_rgb_map = &create_rgb_map;
}

static inline void	initialize_t_lookup_methods(t_lookup *lookup)
{
	lookup->hash_function = &hash_function;
	lookup->set_event_index_by_key = &set_event_index_by_key;
}

static inline void	initialize_t_map_methods(t_map *map)
{
	map->set_radius = &set_radius;
}
