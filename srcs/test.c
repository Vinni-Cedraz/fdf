/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:39:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/02 19:21:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/keycodes.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

// define colors: #define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define YELLOW 0xFFFF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF

// WIDTH and HEIGHT of the window
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

// void	put_pixel_image(void *mlx, void *win, int x, int y, int color);
// this struct is just a x,y point:
// typedef struct s_point
// {
// 	int	x;
// 	int	y;
// 	int	z;
// 	int	color;
// }		t_point;
//

// bressenham algorithm to draw a line:
// void	draw_line(t_point p0, t_point p1, void *mlx, void *win)
// {
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;
//
// 	dx = abs(p1.x - p0.x);
// 	dy = abs(p1.y - p0.y);
// 	sx = p0.x < p1.x ? 1 : -1;
// 	sy = p0.y < p1.y ? 1 : -1;
// 	err = (dx > dy ? dx : -dy) / 2;
// 	while (1)
// 	{
// 		put_pixel_image(mlx, win, p0.x, p0.y, p0.color);
// 		if (p0.x == p1.x && p0.y == p1.y)
// 			break ;
// 		e2 = err;
// 		if (e2 > -dx)
// 		{
// 			err -= dy;
// 			p0.x += sx;
// 		}
// 		if (e2 < dy)
// 		{
// 			err += dx;
// 			p0.y += sy;
// 		}
// 	}
// }
//
// bpp means bits per pixel
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	int		hook;
}			t_data;

typedef struct s_quare
{
	int		height_start;
	int		width_start;
	int		total_height;
	int		total_width;
}			t_square;

void	put_pixel_image(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

void	render_square(t_data *data, t_img *img, int color, t_square *square)
{
	int	width_start_start;

	width_start_start = square->height_start;
	if (data->win_ptr == NULL)
		return ;
	while (square->height_start < square->total_height)
	{
		square->width_start = width_start_start;
		while (square->width_start < square->total_width)
			put_pixel_image(img, square->width_start++, square->height_start,
				color);
		++square->height_start;
	}
}

int	deal_key(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_img		img;
	t_data		data;
	t_square	red_square;
	t_square	white_square;

	red_square.height_start = 125;
	red_square.width_start = 125;
	red_square.total_height = 375;
	red_square.total_width = 375;
	white_square.height_start = 0;
	white_square.width_start = 0;
	white_square.total_height = 500;
	white_square.total_width = 500;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "mlx 42");
	img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,
			&img.endian);
	render_square(&data, &img, WHITE, &white_square);
	render_square(&data, &img, RED, &red_square);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.mlx_img, 0, 0);
	mlx_key_hook(data.win_ptr, deal_key, (void *)0);
	mlx_loop(data.mlx_ptr);
}
