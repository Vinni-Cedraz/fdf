/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/18 23:47:26 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

//determines t_point attributes scaling it according to the map/window size//
static void	make_t_point(t_data **d, t_split *t_split, int x, int y);
//stores the map in a 2d array of t_point in the t_data struct//
static int	create_map(t_data *map, char *argv);
//finds a comma and a hex code in the string, then converts it to an int//
static int	get_hex_color(char *str);
// frees and exits the program if the map is invalid //
static void	free_error(t_data *d, int fd);

int	parse_map_bns(char *argv, t_data *d)
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
	d->map = malloc(sizeof(t_map));
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
	free(first_line);
	return (close(fd), create_map(d, argv), 1);
}

//tool->x and tool->y are just local counters for the loops //
static int	create_map(t_data *d, char *argv)
{
	d->tool.y = 0;
	d->tool.x = -1;
	d->tool.fd = open(argv, O_RDONLY);
	d->map->arr = ft_calloc(d->map->height, sizeof(t_point));
	while (1)
	{
		printf("[%d] out of [%d]\r", d->tool.y, d->map->height);
		d->tool.line = ft_gnl(d->tool.fd);
		if (d->tool.line == NULL)
			break ;
		d->tool.split = ft_split(d->tool.line, ' ');
		if ((int)d->tool.split->words != d->map->width)
			return (ft_printf("%s\n", "Error: uneven map."), \
		free_error(d, d->tool.fd), 0);
		free(d->tool.line);
		d->map->arr[d->tool.y] = ft_calloc(sizeof(t_point), d->map->width);
		while (++d->tool.x < d->map->width)
			make_t_point(&d, d->tool.split, d->tool.x, d->tool.y);
		d->tool.x = -1;
		d->tool.y++;
		ft_free_t_split(d->tool.split);
	}
	return (close(d->tool.fd), 0);
}

static void	make_t_point(t_data **d, t_split *t_split, int x, int y)
{
	int	hexcolor;

	(*d)->scale_x = (double)WINDOW_WIDTH / (*d)->map->width / 1.5;
	(*d)->scale_y = (double)WINDOW_HEIGHT / (*d)->map->height / 1.5;
	(*d)->map->arr[y][x].x = x * (*d)->scale_x;
	(*d)->map->arr[y][x].y = y * (*d)->scale_y;
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

static void	free_error(t_data *d, int fd)
{
	free(d->map);
	close(fd);
	exit(0);
}
