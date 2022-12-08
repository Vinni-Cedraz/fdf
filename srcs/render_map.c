/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/08 20:46:18 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

typedef struct s_map
{
	int		i;
	int		j;
	int		lines;
	int		**map;
	char	**line;
}			t_map;

static void	printf_map(t_map *map);

void	render_map(int fd)
{
	t_split			*split;
	static t_map	map;

	map.i = 0;
	map.j = 0;
	while (1)
	{
		map.line[map.lines] = ft_gnl(fd);
		if (!map.line)
			break ;
		map.lines++;
	}
	split = ft_split(*map.line, ' ');
	map.map = ft_calloc(map.lines, split->words);
	while (map.i < map.lines)
	{
		split = ft_split(map.line[map.i], ' ');
		while (map.j < (int)split->words - 1)
		{
			map.map[map.i][map.j] = ft_atoi(split->str_arr[map.j]);
			map.j++;
		}
		map.j = 0;
		map.i++;
	}
	map.lines++;
	map.j = split->words;
	ft_free_arr(split->str_arr, (void **)split->str_arr);
	printf_map(&map);
}
static void	printf_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->lines)
	{
		while (j < map->j - 1)
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
}
