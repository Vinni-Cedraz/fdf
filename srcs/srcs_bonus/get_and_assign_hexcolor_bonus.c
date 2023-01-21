/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_assign_hexcolor_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 11:39:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_split			*read_points_in_current_row(t_data *d);
static char				*get_point_string(char *current_point);
static int				is_begining_of_new_row(int counter, int *j, int width);
static int				is_end_of_row(int *j, int width);

void	get_and_assign_hexcolor_bonus(t_data *d)
{
	t_split				*points_in_current_row;
	char				*hexstring;
	int					module_counter;
	int					*j;
	t_node_with_a_point	*tmp;

	j = ft_calloc(sizeof(int), 1);
	tmp = d->map->pts;
	module_counter = 0;
	points_in_current_row = &(t_split){NULL, NULL, 0, 0};
	while (tmp)
	{
		if (is_begining_of_new_row(module_counter, j, (int)d->map->width))
			points_in_current_row = read_points_in_current_row(d);
		hexstring = get_point_string(points_in_current_row->str_arr[*j]);
		if (ft_ishexlow(hexstring))
			tmp->point.color = ft_atoi_base(hexstring, HEX_BASE);
		else if (hexstring)
			tmp->point.color = ft_atoi_base(hexstring, HEX_BASE_UPPER);
		module_counter++;
		if (is_end_of_row(j, d->map->width))
			ft_free_t_split(points_in_current_row);
		tmp = tmp->next;
	}
	free(j);
}

static inline int	is_begining_of_new_row(int counter, int *j, int width)
{
	*j = counter % width;
	if (*j == 0)
		return (1);
	return (0);
}

static inline t_split	*read_points_in_current_row(t_data *d)
{
	size_t	len;
	char	*untrimmed_line;
	char	*trimmed_line;
	t_split	*points_in_current_row;

	len = 0;
	untrimmed_line = "";
	getline(&untrimmed_line, &len, d->tool.fp);
	trimmed_line = ft_strtrim(untrimmed_line, "\n");
	free(untrimmed_line);
	points_in_current_row = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	return (points_in_current_row);
}

static inline char	*get_point_string(char *current_point)
{
	char	*hexstring;
	char	*comma;

	comma = ft_memchr(current_point, ',', ft_strlen(current_point));
	if (comma)
		hexstring = comma + 3;
	else
		hexstring = NULL;
	return (hexstring);
}

static inline int	is_end_of_row(int *j, int width)
{
	if (*j == width - 1)
		return (1);
	return (0);
}
