/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackout_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:23:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/20 11:43:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

void	blackout_bonus(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->img->height)
	{
		j = 0;
		while (j < data->img->width)
		{
			put_pixel_img_bonus(data->img, j, i, BLACK);
			j++;
		}
		i++;
	}
}