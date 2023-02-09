/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:58:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/09 15:54:00 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include <sys/types.h>

static void			create_points_list(t_data *d);
static void			check_for_hexcolor(t_data *d);

void	parse_map_bonus(t_data *d)
{
	get_map_dimensions_bonus(d);
	create_points_list(d);
	calculate_default_scale_bonus(d);
	assign_coordinates_bonus(d);
	check_for_hexcolor(d);
	if (d->map->has_hexcolor)
		assign_hexcolor_bonus(d);
	fclose(d->tool.fp);
}

static void	create_points_list(t_data *d)
{
	uint	counter;

	counter = d->map->size;
	d->map->pts = ft_lstpoint_new();
	while (counter-- > 1)
		ft_lstpoint_front(&d->map->pts, ft_lstpoint_new());
}

static inline void	check_for_hexcolor(t_data *d)
{
	char	buf[1];

	while (fread(buf, 1, 1, d->tool.fp))
		if (*buf == ',')
			d->map->has_hexcolor = 1;
	rewind(d->tool.fp);
}

short	is_a_valid_file(t_data *d)
{
	char	*argv;

	argv = d->tool.argv;
	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (0);
	d->tool.fp = fopen(argv, "r");
	if (!d->tool.fp || !d)
		return (0);
	return (1);
}
