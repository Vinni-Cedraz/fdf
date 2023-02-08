/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_hexcolor_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:46 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 21:49:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static int			read_points_in_current_row(t_data *d);
static int			is_end_of_row(int counter, int width);
static int			is_beginning_of_row(int counter, int width);
static void			handle_error(t_data *d);

int	assign_hexcolor_bonus(t_data *d)
{
	t_n		*tmp;
	int		success;
	int		counter;
	int		row_len;
	char	*p_as_str;

	tmp = d->map->pts;
	counter = -1;
	row_len = (int)d->map->width;
	while (tmp)
	{
		if (is_beginning_of_row(++counter, row_len))
			success = read_points_in_current_row(d);
		if (!success)
			return (handle_error(d), 0);
		p_as_str = d->tool.pts_in_this_row->str_arr[counter % row_len];
		set_hexcolor(&tmp->point, p_as_str);
		tmp = tmp->next;
		if (is_end_of_row(counter, row_len))
			ft_free_t_split(d->tool.pts_in_this_row);
	}
	return (1);
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

static void	handle_error(t_data *d)
{
	errno = EINVAL;
	ft_free_t_split(d->tool.pts_in_this_row);
	ft_lstpoint_free(&d->map->pts);
	perror("First line of the map shouldn't be longer than any other line");
}
