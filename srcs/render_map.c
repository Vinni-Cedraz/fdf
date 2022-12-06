/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:29:52 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/06 19:00:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include "../includes/includes.h"
#include "libft.h"
#include <stdio.h>

static void	printf_map(int map[11][19]);
void		render_map(int fd);

void	render_map(int fd)
{
	int		map[11][19];
	char	**splitted_line;
	char	*line;
	int		i;
	int		j;

	splitted_line = NULL;
	i = -1;
	j = -1;
	while (++i < 11)
	{
		line = ft_gnl(fd);
		splitted_line = ft_split(line, ' ');
		while (++j < 19)
			map[i][j] = ft_atoi(splitted_line[j]);
		j = -1;
	}
	printf_map(map);
}
static void	printf_map(int map[11][19])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 11)
	{
		while (j < 19)
		{
			if (ft_numlen(map[i][j]) == 1)
			{
				printf("  %d", map[i][j]);
				j++;
			}
			else if (ft_numlen(map[i][j]) == 2)
			{
				printf(" %d", map[i][j]);
				j++;
			}
		}
		j = 0;
		printf("\n");
		i++;
	}
}
