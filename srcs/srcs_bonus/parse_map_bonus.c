/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:58:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 21:30:22 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static inline void	get_map_dimensions(t_data *d);
static inline void	assign_point_coordinates_xy(t_data *d);
static inline void	assign_coordinate_z(t_data *d);

int	parse_map_bonus(t_data *d)
{
	char	*argv;
	uint	counter;

	argv = d->tool.argv;
	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (printf("%s\n", strerror(22)), 0);
	d->tool.fp = fopen(argv, "r");
	if (!d->tool.fp || !d)
		return (perror("Error"), 0);
	get_map_dimensions(d);
	counter = d->map->size;
	printf("Map size: %d\n", d->map->size);
	d->map->pts = ft_lstpoint_new();
	while (counter-- > 1)
		ft_lstpoint_front(&d->map->pts, ft_lstpoint_new());
	assign_point_coordinates_xy(d);
	assign_coordinate_z(d);
	return (1);
}

static void	assign_point_coordinates_xy(t_data *d)
{
	t_node_with_a_point	*tmp;
	int					counter;

	tmp = d->map->pts;
	counter = 0;
	while (tmp)
	{
		tmp->point.x = counter % d->map->width;
		tmp->point.y = (int)((double)counter / d->map->width);
		tmp = tmp->next;
		counter++;
	}
}

static inline void	assign_coordinate_z(t_data *d)
{
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		fscanf(d->tool.fp, "%lf", &tmp->point.z);
		tmp = tmp->next;
	}
	fclose(d->tool.fp);
}

static void	get_map_dimensions(t_data *d)
{
	char	buf[1];
	char	*first_line;
	t_split	*split_to_count_width;

	d->map->height = 0;
	while (fread(buf, 1, 1, d->tool.fp))
		if (*buf == '\n' || *buf == '\0')
			d->map->height++;
	rewind(d->tool.fp);
	first_line = ft_special_gnl(d->tool.fp);
	split_to_count_width = ft_split(first_line, ' ');
	free(first_line);
	d->map->width = split_to_count_width->words;
	ft_free_t_split(split_to_count_width);
	d->map->size = d->map->height * d->map->width;
	rewind(d->tool.fp);
}
