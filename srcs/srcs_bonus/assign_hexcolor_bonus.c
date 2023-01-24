/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_assign_hexcolor_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/24 22:24:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_split			*read_points_in_current_row(t_data *d);
static int				is_end_of_row(int j, int width);

void	assign_hexcolor_bonus(t_data *d)
{
	t_split				*pts_in_this_row;
	int					counter;
	int					j;
	int					row_len;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	counter = 0;
	row_len = (int)d->map->width;
	pts_in_this_row = &(t_split){NULL, NULL, 0, 0};
	while (tmp)
	{
		j = counter % row_len;
		if (j == 0)
			pts_in_this_row = read_points_in_current_row(d);
		tmp->point.set_hexcolor(&tmp->point, pts_in_this_row->str_arr[j]);
		tmp = tmp->next;
		counter++;
		if (is_end_of_row(j, row_len))
			ft_free_t_split(pts_in_this_row);
	}
}

static inline int	is_end_of_row(int j, int width)
{
	if (j == width - 1)
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
