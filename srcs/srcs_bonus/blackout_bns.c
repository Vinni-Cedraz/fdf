/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackout_bns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 03:23:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/16 03:23:40 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

// this functions paints the screen black:
void	blackout_bns(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->img->height)
	{
		j = 0;
		while (j < data->img->width)
		{
			put_pixel_img_bns(data->img, j, i, BLACK);
			j++;
		}
		i++;
	}
}
