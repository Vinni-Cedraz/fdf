/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:58:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/17 16:51:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static inline void	get_map_dimensions(t_data *d);
static inline void	get_hexstring(t_data *d);
static inline int	get_hexcolor_from_hexstring(char *str);

int	parse_map_bonus(t_data *d)
{
	char	*argv;
	uint	counter;

	argv = d->tool.argv;
	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (printf("%s\n", strerror(22)), 0);
	d->tool.fp = fopen(argv, "r");
	if (!d->tool.fp || !d)
		return (perror("Error"), 0);
	get_map_dimensions(d);
	counter = d->map->size;
	d->map->pts = ft_lstpoint_new();
	while (counter-- > 1)
		ft_lstpoint_front(&d->map->pts, ft_lstpoint_new());
	calculate_default_scale_bonus(d, WINDOW_HEIGHT);
	assign_coordinates_bonus(d);
	get_hexstring(d);
	fclose(d->tool.fp);
	return (1);
}

static void	get_map_dimensions(t_data *d)
{
	char	buf[1];
	size_t	len;
	char	*first_line_dirty;
	char	*first_line_clean;
	t_split	*get_width;

	len = 0;
	d->map->height = 0;
	first_line_dirty = "";
	while (fread(buf, 1, 1, d->tool.fp))
		if (*buf == '\n' || *buf == '\0')
			d->map->height++;
	rewind(d->tool.fp);
	getline(&first_line_dirty, &len, d->tool.fp);
	first_line_clean = ft_strtrim(first_line_dirty, "\n");
	free(first_line_dirty);
	get_width = ft_split(first_line_clean, ' ');
	d->map->width = get_width->words;
	d->map->size = d->map->height * d->map->width;
	ft_free_t_split(get_width);
	free(first_line_clean);
	rewind(d->tool.fp);
}

static inline void	get_hexstring(t_data *d)
{
	char				*buf;
	t_node_with_a_point	*tmp;

	tmp = d->map->pts;
	while (tmp)
	{
		buf = "\0";
		fscanf(d->tool.fp, "%*d,%ms", &buf);
		tmp->point.color = get_hexcolor_from_hexstring(buf);
		tmp = tmp->next;
	}
}

static inline int	get_hexcolor_from_hexstring(char *str)
{
	int	i;
	int	color;

	i = 0;
	color = 0;
	while (str[i] != '\0')
	{
		if (ft_ishexlow(&str[i + 2]))
			color = ft_atoi_base(&str[i + 2], HEX_BASE);
		else
			color = ft_atoi_base(&str[i + 2], HEX_BASE_UPPER);
		return (color);
		i++;
	}
	return (CYAN);
}
