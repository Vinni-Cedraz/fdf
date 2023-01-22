/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:58:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 00:21:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "t_point_bonus.h"

static int			parse_file(t_data *d);
static void			create_points_list(t_data *d);
static void			check_for_hexcolor(t_data *d);
static void			define_color_by_altitude(t_point *p, t_data *d);

int	parse_map_bonus(t_data *d)
{
	if (!parse_file(d))
		return (0);
	create_points_list(d);
	calculate_default_scale_bonus(d);
	assign_coordinates_bonus(d);
	check_for_hexcolor(d);
	if (d->map->has_hexcolor)
		get_and_assign_hexcolor_bonus(d);
	fclose(d->tool.fp);
	return (1);
}

static int	parse_file(t_data *d)
{
	char	*argv;

	argv = d->tool.argv;
	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (printf("%s\n", strerror(22)), 0);
	d->tool.fp = fopen(argv, "r");
	if (!d->tool.fp || !d)
		return (perror("Error"), 0);
	get_map_dimensions_bonus(d);
	return (1);
}

static void	create_points_list(t_data *d)
{
	uint				counter;
	t_node_with_a_point	*tmp;

	counter = d->map->size;
	d->map->pts = ft_lstpoint_new();
	while (counter-- > 1)
		ft_lstpoint_front(&d->map->pts, ft_lstpoint_new());
	tmp = d->map->pts;
	while (tmp)
	{
		tmp->point.define_color_by_altitude = define_color_by_altitude;
		tmp = tmp->next;
	}
}

static inline void	check_for_hexcolor(t_data *d)
{
	char	buf[1];

	while (fread(buf, 1, 1, d->tool.fp))
		if (*buf == ',')
			d->map->has_hexcolor = 1;
	rewind(d->tool.fp);
}

static inline void	define_color_by_altitude(t_point *p, t_data *d)
{
	double	range;
	double	normalized_z;
	double	r;
	double	b;
	double	g;

	range = d->map->max_z - d->map->min_z;
	normalized_z = (p->z - d->map->min_z) / range;
	r = normalized_z;
	g = 1 - normalized_z;
	b = 0;
	if (p->z < d->map->min_z)
		p->color = rgb_to_int(0, 0, 1);
	else if (p->z > d->map->max_z)
		p->color = rgb_to_int(1, 0, 1);
	else
		p->color = rgb_to_int(r, g, b);
}
