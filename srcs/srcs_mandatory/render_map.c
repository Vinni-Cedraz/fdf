/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:12:55 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/15 11:46:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

//this functions draws in an img a line between the points of a map:
void	render_map(t_data *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			if (j < fdf->map->width - 1)
				render_line(fdf->map->arr[i][j],
					fdf->map->arr[i][j + 1],
					fdf->map->arr[i][j + 1].color,
					fdf);
			if (i < fdf->map->height - 1)
				render_line(fdf->map->arr[i][j],
					fdf->map->arr[i + 1][j],
					fdf->map->arr[i + 1][j].color,
					fdf);
			j++;
		}
		i++;
	}
}
