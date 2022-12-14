/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/14 17:11:03 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"
#include "printf_libft_structs.h"
#include <stdio.h>
#include <string.h>

//determines t_point attributes scaling it according to the map/window size//
static void	make_t_point(t_data **d, t_create_map *t);
//stores the map in a 2d array of t_point in the t_data struct//
static int	create_map(t_data *map, char *argv, char *first_line);
//finds a comma and a hex code in the string, then converts it to an int//
static int	get_hex_color(char *str);

int	parse_map(char *argv, t_data *d)
{
	int		fd;
	char	buf[1];
	t_split	*split_to_count_width;
	char	*first_line;

	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (ft_printf("%s", strerror(22)));
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
		else if (*buf != ' ' && *buf != '-' && *buf != ',')
			if (!ft_isdigit(*buf) && !ft_ishexup(*buf) && !ft_ishexlow(*buf))
				return (ft_printf("%s", strerror(22)));
	ft_free_t_split(split_to_count_width);
	return (close(fd), create_map(d, argv, first_line), 0);
}

//tool->x and tool->y are just local counters for the loops //
static int	create_map(t_data *d, char *argv, char *first_line)
{
	d->tool.y = 0;
	d->tool.x = -1;
	d->tool.fd = open(argv, O_RDONLY);
	d->map->arr = ft_calloc(sizeof(t_point *), d->map->height);
	while (1)
	{
		if (d->tool.y == 0)
			d->tool.line = first_line;
		else
		  d->tool.line = ft_gnl(d->tool.fd);
		if (!d->tool.line)
			break ;
		d->tool.split = ft_split(d->tool.line, ' ');
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
	int	scale_x;
	int	scale_y;

	scale_x = WINDOW_WIDTH / (*d)->map->height;
	scale_y = WINDOW_HEIGHT / (*d)->map->width;
	(*d)->map->arr[t->y][t->x].x = t->x * scale_x;
	(*d)->map->arr[t->y][t->x].y = t->y * scale_y;
	(*d)->map->arr[t->y][t->x].z = ft_atoi(t->split->str_arr[t->x]) * 2;
	(*d)->map->arr[t->y][t->x].color = get_hex_color(t->split->str_arr[t->x]);
}

// static void	get_altitude(t_data *d)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	d->map->altitude = 0;
// 	while (i < d->map->height)
// 	{
// 		j = 0;
// 		while (j < d->map->width)
// 		{
// 			if (d->map->arr[i][j].z > d->map->altitude)
// 				d->map->altitude = d->map->arr[i][j].z;
// 			else if (d->map->arr[i][j].z == 0)
// 				d->map->arr[i][j].z = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
			color = ft_atoi_base(&str[i + 3], HEX_BASE_UPPER);
			return (color);
		}
		i++;
	}
	return (0);
}
