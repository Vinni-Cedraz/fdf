/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:03:24 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/24 18:26:42 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

// call the function in the current node of grid_methods
void	render_map_bonus(void)
{
	((t_func_ptr)(get_data()->lookup.grid_methods->content))();
}

// iterate to the next node in the grid_methods list
void	change_grid_rendering_method(void)
{
	get_data()->lookup.grid_methods = get_data()->lookup.grid_methods->next;
}

void	render_lines_cross(void)
{
	int		i;
	int		j;
	t_point	p1;
	t_data	*d;

	i = -1;
	j = -1;
	d = get_data();
	while (++i < d->map->height)
	{
		j = -1;
		while (++j < d->map->width)
		{
			if (j < d->map->width - 1 && i < d->map->height - 1)
			{
				p1 = d->map->arr[i][j];
				render_line_bonus(p1, d->map->arr[i + 1][j + 1]);
				p1 = d->map->arr[i + 1][j];
				render_line_bonus(p1, d->map->arr[i][j + 1]);
			}
		}
	}
}

void	render_pentagram(void)
{
	int		i;
	int		j;
	t_point	p1;
	t_data	*d;

	i = -1;
	j = -1;
	d = get_data();
	while (++i < d->map->height - 3)
	{
		j = -1;
		while (++j < d->map->width - 3)
		{
			p1 = d->map->arr[i + 1][j];
			render_line_bonus(p1, d->map->arr[i + 1][j + 2]);
			render_line_bonus(p1, d->map->arr[i + 2][j + 2]);
			p1 = d->map->arr[i + 2][j];
			render_line_bonus(p1, d->map->arr[i][j + 1]);
			render_line_bonus(p1, d->map->arr[i + 1][j + 2]);
			p1 = d->map->arr[i][j + 1];
			render_line_bonus(p1, d->map->arr[i + 2][j + 2]);
		}
	}
}
