/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/11 17:19:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	create_map(t_data *map, char *argv);

static void	print_map(t_data **d);

static int	get_hex_color(char *str);

void	parse_map(char *argv, t_data *d)
{
	int		fd;
	int		line_counter;
	char	buf[1];

	d->map = malloc(sizeof(t_map));
	fd = open(argv, O_RDONLY);
	line_counter = 0;
	while (read(fd, buf, 1))
		if (*buf == '\n')
			line_counter++;
	close(fd);
	d->map->height = line_counter;
	create_map(d, argv);
}

static void	create_map(t_data *d, char *argv)
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
		free(t.line);
		d->map->arr[t.y] = ft_calloc(sizeof(t_point), t.split->words + 1);
		while (++t.x < (int)t.split->words)
			d->map->arr[t.y][t.x] = (t_point){t.x, t.y, ft_atoi(t.split-> \
			str_arr[t.x]), get_hex_color(t.split->str_arr[t.x])};
		t.x = -1;
		t.y++;
		if (t.y == 1)
			d->map->width = t.split->words;
		ft_free_t_split(t.split);
	}
	d->map->height = t.y - 1;
	print_map(&d);
}

static	void	print_map(t_data **d)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*d)->map->height)
	{
		x = 0;
		while (x < (*d)->map->width)
		{
			if (ft_numlen((*d)->map->arr[y][x].z) == 1)
			{
				ft_printf("  %d", (*d)->map->arr[y][x].z);
				ft_printf(",%u", (*d)->map->arr[y][x].color);
				x++;
			}
			else
			{
				ft_printf(" %d", (*d)->map->arr[y][x].z);
				ft_printf(",%u", (*d)->map->arr[y][x].color);
				x++;
			}
		}
		ft_printf("\n");
		y++;
	}
	ft_free_data(d);
}

static	int	get_hex_color(char *str)
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
