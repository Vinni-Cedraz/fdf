/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_hexcolor_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/25 19:52:32 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static t_split			*read_points_in_current_row(t_data *d);
static int				is_end_of_row(int counter, int width);
static int				is_beginning_of_row(int counter, int width);

void	assign_hexcolor_bonus(t_data *d)
{
	int					counter;
	int					row_len;
	t_node_with_a_point	*tmp;
	char				*p_as_str;

	tmp = d->map->pts;
	counter = -1;
	row_len = (int)d->map->width;
	while (tmp)
	{
		if (is_beginning_of_row(++counter, row_len))
			d->tool.pts_in_this_row = read_points_in_current_row(d);
		p_as_str = d->tool.pts_in_this_row->str_arr[counter % row_len];
		tmp->point.set_hexcolor(&tmp->point, p_as_str);
		tmp = tmp->next;
		if (is_end_of_row(counter, row_len))
			ft_free_t_split(d->tool.pts_in_this_row);
	}
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

static inline int	is_beginning_of_row(int counter, int width)
{
	return (counter % width == 0);
}

static inline int	is_end_of_row(int counter, int width)
{
	if (counter == width - 1)
		return (1);
	return (0);
}
