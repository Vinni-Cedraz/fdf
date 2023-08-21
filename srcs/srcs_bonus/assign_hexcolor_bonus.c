/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_hexcolor_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:37:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static int			read_points_in_current_row(void);
static int			is_end_of_row(int counter, int width);
static int			get_point_as_a_string(int counter, int row_len);
static int			is_beginning_of_row(int counter, int width);

void	assign_hexcolor_bonus(void)
{
	t_n		*tmp;
	int		counter;
	int		row_len;
	t_data	*d;

	d = get_data();
	tmp = d->map->pts;
	counter = -1;
	row_len = (int)d->map->width;
	while (tmp->next != d->map->pts)
	{
		if (!get_point_as_a_string(++counter, row_len))
			uneven_map_error();
		set_hexcolor_bonus(&tmp->point, d->tool.p_as_str);
		tmp = tmp->next;
		if (is_end_of_row(counter, row_len))
			ft_free_t_split(d->tool.pts_in_this_row);
	}
}

static inline int	get_point_as_a_string(int counter, int row_len)
{
	t_data	*d;

	d = get_data();
	if (is_beginning_of_row(counter, row_len))
		d->tool.successfully_read = read_points_in_current_row();
	if (!d->tool.successfully_read)
		return (0);
	else
		d->tool.p_as_str = d->tool.pts_in_this_row->str_arr[counter % row_len];
	return (1);
}

static inline int	read_points_in_current_row(void)
{
	size_t	len;
	char	*untrimmed_line;
	char	*trimmed_line;
	t_data	*d;

	d = get_data();
	len = 0;
	untrimmed_line = "";
	getline(&untrimmed_line, &len, d->tool.fp);
	trimmed_line = ft_strtrim(untrimmed_line, "\n");
	free(untrimmed_line);
	d->tool.pts_in_this_row = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	if ((int)d->tool.pts_in_this_row->number_of_words < d->map->width)
		return (0);
	return (1);
}

static inline int	is_beginning_of_row(int counter, int width)
{
	return (counter % width == 0);
}

static inline int	is_end_of_row(int counter, int width)
{
	return ((counter + 1) % width == 0);
}
