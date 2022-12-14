/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:58:02 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/08 12:40:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/ft_printf_libft/libft/libft_bonus.h"
#include "fdf_includes_bonus.h"

static int	get_hex_color_bonus(char *str);
static int	create_map_bonus(t_data *map, char *argv, char *first_line);
static void	make_t_point_bonus(t_data **d, t_split *t_split, short x, short y);

int	parse_map_bonus(char *argv, t_data *d)
{
	FILE	*fp;
	char	buf[1];
	t_split	*split_to_count_width;
	char	*first_line;

	if (!argv || !*argv || !ft_strnstr(argv, ".fdf", ft_strlen(argv)))
		return (printf("%s\n", strerror(22)), 0);
	fp = fopen(argv, "r");
	if (!fp || !d)
		return (perror("Error"), 0);
	d->map = malloc(sizeof(t_map));
	first_line = ft_special_gnl(fp);
	split_to_count_width = ft_split(first_line, ' ');
	d->map->width = split_to_count_width->words;
	fclose(fp);
	fp = fopen(argv, "r");
	d->map->height = 0;
	while (fread(buf, 1, 1, fp))
		if (*buf == '\n' || *buf == '\0')
			d->map->height++;
	ft_free_t_split(split_to_count_width);
	calculate_default_scale_bonus(d, WINDOW_HEIGHT);
	return (fclose(fp), create_map_bonus(d, argv, first_line), 1);
}

//tool->x and tool->y are just local counters for the loops //
static int	create_map_bonus(t_data *d, char *argv, char *first_line)
{
	d->tool.y = 0;
	d->tool.x = -1;
	d->tool.fp = fopen(argv, "r");
	d->map->pts = ft_calloc(d->map->height, sizeof(t_point));
	while (1)
	{
		printf("[%d] out of [%d]\r", d->tool.y, d->map->height);
		if (d->tool.y == 0)
			d->tool.line = first_line;
		else
			d->tool.line = ft_special_gnl(d->tool.fp);
		if (d->tool.line == NULL)
			break ;
		d->tool.split = ft_split(d->tool.line, ' ');
		free(d->tool.line);
		d->map->pts[d->tool.y] = ft_calloc(sizeof(t_point), d->map->width);
		while (++d->tool.x < d->map->width)
			make_t_point_bonus(&d, d->tool.split, d->tool.x, d->tool.y);
		d->tool.x = -1;
		d->tool.y++;
		ft_free_t_split(d->tool.split);
	}
	return (fclose(d->tool.fp), 0);
}

static void	make_t_point_bonus(t_data **d, t_split *t_split, short x, short y)
{
	unsigned int	hexcolor;

	(*d)->map->pts[y][x].x = (double)x * (*d)->offset.scale;
	(*d)->map->pts[y][x].y = (double)y * (*d)->offset.scale;
	(*d)->map->pts[y][x].z = ft_atoi(t_split->str_arr[x]);
	hexcolor = get_hex_color_bonus(t_split->str_arr[x]);
	if (hexcolor)
		(*d)->map->pts[y][x].color = hexcolor;
	else
		(*d)->map->pts[y][x].color = CYAN;
}

static int	get_hex_color_bonus(char *str)
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
