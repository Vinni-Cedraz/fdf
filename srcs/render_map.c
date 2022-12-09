/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/08 23:26:17 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

typedef struct s_map
{
	int		i;
	int		j;
	int		numbers;
	int		lines;
	int		map[900][900];
	char	*line;
}			t_map;

static void	printf_map(t_map *map);

void	render_map(int fd)
{
	t_map	map;
	t_split	*split;
	
	map.lines = 0;
	map.numbers = -1;
	while(1)
	{
	  map.line = ft_gnl(fd);
	  if (!map.line)
	    break;
	  split = ft_split(map.line, ' ');
	  free(map.line);
	  while (++map.numbers < (int)split->words - 1)
	    map.map[map.lines][map.numbers] = ft_atoi(split->str_arr[map.numbers]);
	  map.numbers = -1;
	  map.lines++;
	}
	map.numbers = (int)split->words;
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
		while (j < map->numbers - 1)
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
