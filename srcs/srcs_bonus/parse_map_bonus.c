/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:58:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/11 18:00:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf_libft/libft/libft_bonus.h"
#include "fdf_includes_bonus.h"
#include "fdf_structs_bonus.h"

static inline void	get_map_dimensions(t_data *d, char *argv);

int	parse_map_bonus(char *argv, t_data *d)
{
	t_point	*point_placeholder;
	char	*argv;
	int		map_size;

	point_placeholder = NULL;
	argv = d->tool.argv;
	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (printf("%s\n", strerror(22)), 0);
	d->tool.fp = fopen(argv, "r");
	if (!d->tool.fp || !d)
		return (perror("Error"), 0);
	get_map_dimensions(d);
	map_size = d->map->height * d->map->width;
	d->map->pts = ft_lstnew(point_placeholder);
	while (map_size-- > 1)
		ft_lstadd_front(&d->map->pts, ft_lstnew(point_placeholder));
	ft_lstprint(&d->map->pts);
	return (1);
}

static inline void	get_map_dimensions(t_data *d, char *argv)
{
	char	buf[1];
	char	*first_line;
	t_split	*split_to_count_width;

	d->map->height = 0;
	while (fread(buf, 1, 1, d->tool.fp))
		if (*buf == '\n' || *buf == '\0')
			d->map->height++;
	fclose(d->tool.fp);
	d->tool.fp = fopen(d->tool.argv, "r");
	first_line = ft_special_gnl(d->tool.fp);
	split_to_count_width = ft_split(first_line, ' ');
	free(first_line);
	d->map->width = split_to_count_width->words;
	ft_free_t_split(split_to_count_width);
	fclose(d->tool.fp);
}
