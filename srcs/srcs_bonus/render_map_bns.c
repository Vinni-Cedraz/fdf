/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:24:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 03:24:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

//this functions draws in an img a line between the points of a map:
void	render_map_bns(t_data *fdf)
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
				render_line_bns(fdf->map->arr[i][j],
					fdf->map->arr[i][j + 1],
					fdf->map->arr[i][j + 1].color,
					fdf);
			if (i < fdf->map->height - 1)
				render_line_bns(fdf->map->arr[i][j],
					fdf->map->arr[i + 1][j],
					fdf->map->arr[i + 1][j].color,
					fdf);
			j++;
		}
		i++;
	}
}
