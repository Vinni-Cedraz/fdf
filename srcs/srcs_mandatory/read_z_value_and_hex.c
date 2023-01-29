/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_z_value_and_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:48:34 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/28 20:19:56 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static int			read_points_in_current_row(t_data *d);
static int			is_end_of_row(int counter, int width);
static int			is_beginning_of_row(int counter, int width);
static void			handle_uneven_map(t_data *d);

int	read_z_value_and_hex(t_data *d)
{
	int					counter;
	int					row_len;
	t_node_with_a_point	*tmp;
	char				*p_as_str;
	int					success;

	tmp = d->map->pts;
	counter = -1;
	row_len = (int)d->map->width;
	while (tmp)
	{
		if (is_beginning_of_row(++counter, row_len))
			success = read_points_in_current_row(d);
		if (!success)
			return (handle_uneven_map(d), 0);
		p_as_str = d->tool.pts_in_this_row->str_arr[counter % row_len];
		tmp->point.set_z_value(&tmp->point, d->offset.scale, p_as_str);
		tmp->point.set_hexcolor(&tmp->point, p_as_str);
		tmp = tmp->next;
		if (is_end_of_row(counter, row_len))
			ft_free_t_split(d->tool.pts_in_this_row);
	}
	return (1);
}

static inline int	read_points_in_current_row(t_data *d)
{
	char		*untrimmed_line;
	char		*trimmed_line;
	static int	not_first_row;
	char		*buggy_line;

	d->tool.fd = open(d->tool.argv, O_RDONLY);
	if (!not_first_row)
		trimmed_line = d->tool.first_line;
	else
	{
		untrimmed_line = ft_gnl(d->tool.fd);
		trimmed_line = ft_strtrim(untrimmed_line, " \n");
		free(untrimmed_line);
	}
	d->tool.pts_in_this_row = ft_split(trimmed_line, ' ');
	free(trimmed_line);
	if (!not_first_row)
		not_first_row = 1;
	close(d->tool.fd);
	buggy_line = ft_gnl(d->tool.fd);
	ft_putstr(buggy_line);
	if ((int)d->tool.pts_in_this_row->words < d->map->width)
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

static inline void	handle_uneven_map(t_data *d)
{
	errno = EINVAL;
	ft_free_t_split(d->tool.pts_in_this_row);
	ft_lstpoint_free(&d->map->pts);
	perror("First line of the map shouldn't be longer than any other line");
}
