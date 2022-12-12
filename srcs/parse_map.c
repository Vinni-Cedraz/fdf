/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/12 09:03:46 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"
#include <stdio.h>
#include <string.h>

// determines t_point attributes//
static void	make_t_point(t_data **d, t_create_map *t);
// stores the map in a 2d array of t_point in the t_data struct//
static int	create_map(t_data *map, char *argv);
// finds a comma and a hex code in the string, then converts it to an int//
static int	get_hex_color(char *str);
// just prints is so I can check if the map is being stored correctly//
static void	print_map(t_data **d);
// checks for invalid files, args invalid maps and counts map's line number//

int	parse_map(char *argv, t_data *d)
{
	int		fd;
	char	buf[1];

	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (ft_printf("%s", strerror(22)));
	d->map = malloc(sizeof(t_map));
	fd = open(argv, O_RDONLY);
	if ((fd == -1 || read(fd, buf, 0) == -1 || !d))
		return (perror("Error"), 0);
	d->map->height = 0;
	while (read(fd, buf, 1))
	{
		if (*buf == '\n')
		{
			d->map->height++;
		}
		else if (*buf != ' ' && *buf != '-' && *buf != ',')
		{
			if (!ft_isdigit(*buf) && !ft_ishexup(*buf) && !ft_ishexlow(*buf))
				return (ft_printf("%s", strerror(22)));
		}
	}
	return (create_map(d, argv), 0);
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
			color = ft_atoi_base(&str[i + 3], HEX_BASE_UPPER);
			return (color);
		}
		i++;
	}
	return (0);
}

static int	create_map(t_data *d, char *argv)
{
	t_create_map	t;

	t.y = 0;
	t.x = -1;
	t.fd = open(argv, O_RDONLY);
	d->map->arr = ft_calloc(sizeof(t_point *), d->map->height);
	while (1)
	{
		t.line = ft_gnl(t.fd);
		if (!t.line)
			break ;
		t.split = ft_split(t.line, ' ');
		if (t.y == 0)
			d->map->width = t.split->words;
		free(t.line);
		d->map->arr[t.y] = ft_calloc(sizeof(t_point), d->map->width);
		while (++t.x < d->map->width)
			make_t_point(&d, &t);
		t.x = -1;
		t.y++;
		ft_free_t_split(t.split);
	}
	d->map->height = t.y - 1;
	return (close(t.fd), print_map(&d), 0);
}

static void	make_t_point(t_data **d, t_create_map *t)
{
	(*d)->map->arr[t->y][t->x].x = t->x;
	(*d)->map->arr[t->y][t->x].y = t->y;
	(*d)->map->arr[t->y][t->x].z = ft_atoi(t->split->str_arr[t->x]);
	(*d)->map->arr[t->y][t->x].color = get_hex_color(t->split->str_arr[t->x]);
}

static void	print_map(t_data **d)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (*d)->map->height)
	{
		x = -1;
		while (++x < (*d)->map->width)
		{
			if (ft_numlen((*d)->map->arr[y][x].z) == 1)
			{
				ft_printf("  %d", (*d)->map->arr[y][x].z);
			}
			else
			{
				ft_printf(" %d", (*d)->map->arr[y][x].z);
			}
		}
		ft_printf("\n");
	}
	ft_free_data(d);
}
