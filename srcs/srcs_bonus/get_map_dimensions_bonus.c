/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_dimensions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:59:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 21:38:41 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			get_map_size(t_data *d);
static void			get_map_height(t_data *d);
static void			get_first_line(t_data *d);
static void			get_map_width(t_data *d);

void	get_map_dimensions_bonus(t_data *d)
{
	get_map_height(d);
	rewind(d->tool.fp);
	get_first_line(d);
	get_map_width(d);
	get_map_size(d);
	rewind(d->tool.fp);
}

static inline void	get_map_height(t_data *d)
{
	char	buf[1];

	while (fread(buf, 1, 1, d->tool.fp))
		if (*buf == '\n' || *buf == '\0')
			d->map->height++;
}

static inline void	get_first_line(t_data *d)
{
	char	*first_line_dirty;
	size_t	len;

	len = 0;
	first_line_dirty = NULL;
	getline(&first_line_dirty, &len, d->tool.fp);
	d->tool.first_line = ft_strtrim(first_line_dirty, "\n");
	free(first_line_dirty);
}

static inline void	get_map_width(t_data *d)
{
	t_split	*get_width;

	get_width = ft_split(d->tool.first_line, ' ');
	d->map->width = get_width->words;
	ft_free_t_split(get_width);
	free(d->tool.first_line);
}

static inline void	get_map_size(t_data *d)
{
	d->map->size = d->map->width * d->map->height;
	d->map->ratio = (double)d->map->height / d->map->width;
	d->map->radius = d->map->width * 0.7;
}
