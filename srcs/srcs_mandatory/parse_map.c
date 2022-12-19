/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/19 14:52:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	make_t_point(t_data **d, t_create_map *t);
static int	create_map(t_data *map, char *argv);
static int	get_hex_color(char *str);

int	parse_map(char *argv, t_data *d)
{
	int		fd;
	char	buf[1];
	char	*first_line;
	t_split	*split_to_count_width;

	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (ft_printf("%s\n", strerror(22)), 0);
	fd = open(argv, O_RDONLY);
	if ((fd == -1 || read(fd, buf, 0) == -1 || !d))
		return (perror("Error"), 0);
	d->map = malloc(sizeof(t_map));
	first_line = ft_gnl(fd);
	split_to_count_width = ft_split(first_line, ' ');
	d->map->width = split_to_count_width->words;
	close(fd);
	fd = open(argv, O_RDONLY);
	d->map->height = 0;
	while (read(fd, buf, 1))
		if (*buf == '\n')
			d->map->height++;
	ft_free_t_split(split_to_count_width);
	return (close(fd), create_map(d, argv), free(first_line), 1);
}

static int	create_map(t_data *d, char *argv)
{
	d->tool.y = 0;
	d->tool.x = -1;
	d->tool.fd = open(argv, O_RDONLY);
	d->map->arr = ft_calloc(d->map->height, sizeof(t_point));
	while (d->tool.y < d->map->height)
	{
		d->tool.line = ft_gnl(d->tool.fd);
		d->tool.split = ft_split(d->tool.line, ' ');
		free(d->tool.line);
		d->map->arr[d->tool.y] = ft_calloc(sizeof(t_point), d->map->width);
		while (++d->tool.x < d->map->width)
			make_t_point(&d, &d->tool);
		d->tool.x = -1;
		d->tool.y++;
		ft_free_t_split(d->tool.split);
	}
	return (close(d->tool.fd), 0);
}

static void	make_t_point(t_data **d, t_create_map *t)
{
	int	hexcolor;

	(*d)->scale_y = (double)WINDOW_HEIGHT / (*d)->map->height / 1.5;
	(*d)->scale_x = (double)WINDOW_WIDTH / (*d)->map->width / 1.5;
	(*d)->map->arr[t->y][t->x].x = t->x * (*d)->scale_x;
	(*d)->map->arr[t->y][t->x].y = t->y * (*d)->scale_y;
	(*d)->map->arr[t->y][t->x].z = ft_atoi(t->split->str_arr[t->x]) * 2.5;
	hexcolor = get_hex_color(t->split->str_arr[t->x]);
	if (hexcolor)
		(*d)->map->arr[t->y][t->x].color = hexcolor;
	else
		(*d)->map->arr[t->y][t->x].color = CYAN;
}

static int	get_hex_color(char *str)
{
	int	i;
	int	color;

	i = 0;
	color = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			if (ft_ishexlow(&str[i + 3]))
				color = ft_atoi_base(str + i + 3, HEX_BASE);
			else
				color = ft_atoi_base(&str[i + 3], HEX_BASE_UPPER);
			return (color);
		}
		i++;
	}
	return (0);
}
