/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:19:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/27 22:20:28 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"

static void			draw_menu_background(void);

void	draw_menu(void)
{
	void	*dsp;
	void	*win;

	dsp = get_data()->mlx->display_ptr;
	win = get_data()->mlx->win_ptr;
	draw_menu_background();
	mlx_string_put(dsp, win, 10, 20, MAGENTA, "CONTROLS MENU");
	mlx_string_put(dsp, win, 10, 60, CYAN, "FIRST, GO ISO: 'SPACE TWICE'");
	mlx_string_put(dsp, win, 10, 100, WHITE, "ROTATE 1: 'a' / 'd'");
	mlx_string_put(dsp, win, 10, 140, WHITE, "ROTATE 2: 'q' / 'e'");
	mlx_string_put(dsp, win, 10, 180, WHITE, "ROTATE 3: 'x' / 'v'");
	mlx_string_put(dsp, win, 10, 220, WHITE, "CHANGE ALTITUDE: 'z' / 'c'");
	mlx_string_put(dsp, win, 10, 260, WHITE, "TURN IT INTO A BALL: 'ab'");
	mlx_string_put(dsp, win, 10, 300, WHITE, "ZOOM IN: 'w' / 's'");
	mlx_string_put(dsp, win, 10, 340, WHITE, "BALL ALTITUDE: 'j' / 'k'");
	mlx_string_put(dsp, win, 10, 380, WHITE, "RESET TO ISOMETRIC: ';'");
	mlx_string_put(dsp, win, 10, 420, WHITE, "MOVE: arrow keys");
	mlx_string_put(dsp, win, 10, 460, CYAN, "EXIT: 'esc'");
}

static inline void	draw_menu_background(void)
{
	int	counter;
	int	menu_size;
	int	height;
	int	i;
	int	j;

	counter = 0;
	menu_size = get_data()->scale->menu_width * get_data()->img->height;
	height = get_data()->img->height;
	while (counter < menu_size)
	{
		i = counter / height;
		j = counter % height;
		put_pixel_img_bonus(get_data()->img, i, j, DARKER_GRAY);
		counter++;
	}
}
