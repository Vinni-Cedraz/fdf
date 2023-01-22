/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:58:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 11:59:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "t_point_bonus.h"

static int			parse_file(t_data *d);
static void			create_points_list(t_data *d);
static void			check_for_hexcolor(t_data *d);

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
		tmp->point.define_p_color_by_altitude = compute_color_gradient_bonus;
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
