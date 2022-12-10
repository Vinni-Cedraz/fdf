/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_dimensions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/09 22:25:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

void	get_map_height(char *argv)
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

void	create_map(t_map **map, char *argv)
{
	int		width;
	int		height;
	int		fd;
	char	*line;
	t_split	*split;

	width = -1;
	height = 0;
	fd = open(argv, O_RDONLY);
	(*map)->map = malloc(sizeof(int *) * (*map)->height);
	while (1)
	{
		line = ft_gnl(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		(*map)->map[height] = malloc(sizeof(int) * split->words);
		free(line);
		while (++width < (int)split->words)
			(*map)->map[height][width] = ft_atoi(split->str_arr[width]);
		width = -1;
		height++;
		if (height == 1)
			(*map)->width = split->words;
		ft_free_t_split(split);
	}
	(*map)->height = height;
	print_map(*map);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width - 1)
		{
			if (ft_numlen(map->map[i][j]) == 1)
			{
				ft_printf("  %d", map->map[i][j]);
				j++;
			}
			else if (ft_numlen(map->map[i][j]) == 2)
			{
				ft_printf(" %d", map->map[i][j]);
				j++;
			}
		}
		j = 0;
		ft_printf("\n");
		i++;
	}
	ft_free_arr((char **)map->map, (void **)map->map);
	free(map);
}
