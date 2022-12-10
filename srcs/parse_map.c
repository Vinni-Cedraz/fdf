/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/10 16:02:52 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	create_map(t_map **map, char *argv);

static void	print_map(t_map *map);

void	parse_map(char *argv)
{
	int		fd;
	int		line_counter;
	char	buf[1];
	t_map	*map;

	map = malloc(sizeof(t_map));
	fd = open(argv, O_RDONLY);
	line_counter = 0;
	while (read(fd, buf, 1))
		if (*buf == '\n')
			line_counter++;
	close(fd);
	map->height = line_counter;
	create_map(&map, argv);
}

static void	create_map(t_map **map, char *argv)
{
	t_create_map	t;

	t.width = -1;
	t.height = 0;
	t.fd = open(argv, O_RDONLY);
	(*map)->map = malloc(sizeof(int *) * (*map)->height);
	while (1)
	{
		t.line = ft_gnl(t.fd);
		if (!t.line)
			break ;
		t.split = ft_split(t.line, ' ');
		(*map)->map[t.height] = malloc(sizeof(int) * t.split->words);
		free(t.line);
		while (++t.width < (int)t.split->words)
			(*map)->map[t.height][t.width] = ft_atoi(t.split->str_arr[t.width]);
		t.width = -1;
		t.height++;
		if (t.height == 1)
			(*map)->width = t.split->words;
		ft_free_t_split(t.split);
	}
	(*map)->height = t.height;
	print_map(*map);
}

static void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (ft_numlen(map->map[i][j]) == 1)
				ft_printf("  %d", map->map[i][j++]);
			else if (ft_numlen(map->map[i][j]) == 2)
				ft_printf(" %d", map->map[i][j++]);
		}
		j = 0;
		ft_printf("\n");
		i++;
	}
	ft_free_arr((char **)map->map, (void **)map->map);
	free(map);
}
