/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/28 22:33:09 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	make_t_point(t_data **d, t_split *t_split, int x, int y);
static int	create_map(t_data *map, char *argv, char *first_line);
static int	get_hex_color(char *str);
static int	is_shorter_than_first_line(t_data *d);

int	parse_map(char *argv, t_data *d)
{
	int		fd;
	char	buf[1];
	t_split	*split_to_count_width;
	char	*first_line;

	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (ft_printf("%s\n", strerror(22)), 0);
	fd = open(argv, O_RDONLY);
	if ((fd == -1 || read(fd, buf, 0) == -1 || !d))
		return (perror("Error"), 0);
	first_line = ft_gnl(fd);
	split_to_count_width = ft_split(first_line, ' ');
	d->map->width = split_to_count_width->words;
	close(fd);
	fd = open(argv, O_RDONLY);
	d->map->height = 0;
	while (read(fd, buf, 1))
		if (*buf == '\n' || *buf == '\0')
			d->map->height++;
	ft_free_t_split(split_to_count_width);
	standard_scale(d, WINDOW_HEIGHT);
	close(fd);
	if (!create_map(d, argv, first_line))
		return (ft_free_arr((char **)d->map->arr, (void **)d->map->arr), 0);
	return (1);
}

static int	create_map(t_data *d, char *argv, char *first_line)
{
	d->tool.y = 0;
	d->tool.x = -1;
	d->tool.fd = open(argv, O_RDONLY);
	d->map->arr = ft_calloc(d->map->height, sizeof(t_point));
	while (1)
	{
		ft_printf("[%d] out of [%d]\r", d->tool.y, d->map->height);
		if (d->tool.y == 0)
			d->tool.line = first_line;
		else
			d->tool.line = ft_gnl(d->tool.fd);
		if (d->tool.line == NULL)
			break ;
		if (is_shorter_than_first_line(d))
			return (ft_printf("Error: map is too uneven"), 0);
		d->tool.split = ft_split(d->tool.line, ' ');
		free(d->tool.line);
		d->map->arr[d->tool.y] = ft_calloc(sizeof(t_point), d->map->width);
		while (++d->tool.x < d->map->width)
			make_t_point(&d, d->tool.split, d->tool.x, d->tool.y);
		d->tool.x = -1;
		d->tool.y++;
		ft_free_t_split(d->tool.split);
	}
	return (close(d->tool.fd), 1);
}

static void	make_t_point(t_data **d, t_split *t_split, int x, int y)
{
	int	hexcolor;

	(*d)->map->arr[y][x].x = (double)x * (*d)->scale;
	(*d)->map->arr[y][x].y = (double)y * (*d)->scale;
	(*d)->map->arr[y][x].z = ft_atoi(t_split->str_arr[x]);
	hexcolor = get_hex_color(t_split->str_arr[x]);
	if (hexcolor)
		(*d)->map->arr[y][x].color = hexcolor;
	else
		(*d)->map->arr[y][x].color = CYAN;
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
			if (ft_ishexlow(str + i + 3))
				color = ft_atoi_base(str + i + 3, HEX_BASE);
			else
				color = ft_atoi_base(&str[i + 3], HEX_BASE_UPPER);
			return (color);
		}
		i++;
	}
	return (0);
}

static int	is_shorter_than_first_line(t_data *d)
{
	char	*gnl_buggy_line;

	gnl_buggy_line = d->tool.line;
	if (d->map->width > (int)ft_strlen(d->tool.line))
	{
		while (gnl_buggy_line != NULL)
		{
			free(gnl_buggy_line);
			gnl_buggy_line = ft_gnl(d->tool.fd);
		}
		return (1);
	}
	return (0);
}
