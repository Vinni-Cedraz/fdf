/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_hexcolor_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/18 03:05:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static int			read_points_in_current_row(t_data *d);
static int			is_end_of_row(int counter, int width);
static void			get_point_as_a_string(t_data *d, int counter, int row_len);
static int			is_beginning_of_row(int counter, int width);

void	assign_hexcolor_bonus(t_data *d)
{
	t_n	*tmp;
	int	counter;
	int	row_len;

	tmp = d->map->pts;
	counter = -1;
	row_len = (int)d->map->width;
	while (tmp)
	{
		get_point_as_a_string(d, ++counter, row_len);
		set_hexcolor_bonus(&tmp->point, d->tool.p_as_str);
		tmp = tmp->next;
		if (is_end_of_row(counter, row_len))
			ft_free_t_split(d->tool.pts_in_this_row);
	}
}

static inline void	get_point_as_a_string(t_data *d, int counter, int row_len)
{
	if (is_beginning_of_row(counter, row_len))
		d->tool.successfully_read = read_points_in_current_row(d);
	if (!d->tool.successfully_read)
		d->tool.p_as_str = "";
	else
		d->tool.p_as_str = d->tool.pts_in_this_row->str_arr[counter % row_len];
}

static inline int	read_points_in_current_row(t_data *d)
{
	size_t	len;
	char	*untrimmed_line;
	char	*trimmed_line;

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
