/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_dimensions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:59:12 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/18 03:05:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			get_map_size(void);
static void			get_map_height(void);
static void			get_first_line(void);
static void			get_map_width(void);

void	get_map_dimensions_bonus(void)
{
	get_map_height();
	rewind(get_data()->tool.fp);
	get_first_line();
	get_map_width();
	get_map_size();
	rewind(get_data()->tool.fp);
}

static inline void	get_map_height(void)
{
	char	buf[1];
	t_data	*d;

	d = get_data();
	while (fread(buf, 1, 1, d->tool.fp))
		if (*buf == '\n' || *buf == '\0')
			d->map->height++;
}

static inline void	get_first_line(void)
{
	char	*first_line_dirty;
	t_data	*d;
	size_t	len;

	d = get_data();
	len = 0;
	first_line_dirty = NULL;
	getline(&first_line_dirty, &len, get_data()->tool.fp);
	d->tool.first_line = ft_strtrim(first_line_dirty, "\n");
	free(first_line_dirty);
}

static inline void	get_map_width(void)
{
	t_split	*get_width;

	get_width = ft_split(get_data()->tool.first_line, ' ');
	get_data()->map->width = get_width->number_of_words;
	ft_free_t_split(get_width);
	free(get_data()->tool.first_line);
}

static inline void	get_map_size(void)
{
	t_data	*d;

	d = get_data();
	d->map->size = d->map->width * d->map->height;
	d->map->ratio = (float)d->map->height / d->map->width;
	printf("map size: %lu\n", d->map->size);
}
