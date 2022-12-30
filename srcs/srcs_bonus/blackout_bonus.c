/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackout_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:11:22 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/30 17:36:07 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void	put_pixel_img_bonus(t_img *img, int x, int y, int color);

void	blackout_bonus(t_data *data)
{
	int	i;
	int	j;

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

static void	put_pixel_img_bonus(t_img *img, int x, int y, int color)
{
	char	*ptr_to_color;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	ptr_to_color = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)ptr_to_color = color;
}
