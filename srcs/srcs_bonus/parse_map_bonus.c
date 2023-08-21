/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:58:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/21 17:39:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			create_points_list(void);
static void			check_for_hexcolor(void);
static void			apply_scale(t_point *point);

void	parse_map_bonus(void)
{
	get_map_dimensions_bonus();
	create_points_list();
	calculate_default_scale_bonus();
	get_data()->offset->set_initial_offset();
	assign_coordinates_bonus();
	ft_lstpoint_iter(get_data()->map->pts, &apply_scale);
	check_for_hexcolor();
	if (get_data()->map->has_hexcolor)
		assign_hexcolor_bonus();
	fclose(get_data()->tool.fp);
}

static void	create_points_list(void)
{
	uint	counter;
	t_data	*d;

	d = get_data();
	counter = d->map->size;
	d->map->pts = ft_lstpoint_new();
	while (counter-- > 1)
		ft_lstpoint_front(&d->map->pts, ft_lstpoint_new());
	ft_lstpoint_make_it_circular(&d->map->pts);
}

static inline void	apply_scale(t_point *point)
{
	t_scale	sca;
	t_data	*d;

	d = get_data();
	sca = *d->scale;
	point->ol.raw.x = point->x;
	point->ol.raw.y = point->y;
	point->ol.raw.z = point->z;
	point->x *= sca.default_scale;
	point->y *= sca.default_scale;
	point->z *= sca.default_scale;
	d->map->radius *= d->scale->default_scale;
}

static inline void	check_for_hexcolor(void)
{
	char	buf[1];
	t_data	*d;

	d = get_data();
	while (fread(buf, 1, 1, d->tool.fp))
		if (*buf == ',')
			d->map->has_hexcolor = 1;
	rewind(d->tool.fp);
}

short	is_a_valid_file(void)
{
	char	*argv;
	t_data	*d;

	d = get_data();
	argv = d->tool.argv;
	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (0);
	d->tool.fp = fopen(argv, "r");
	if (!d->tool.fp || !d)
		return (0);
	return (1);
}
