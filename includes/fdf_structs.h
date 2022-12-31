/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/31 19:23:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "printf_libft_structs.h"

// rotation 5 degrees around y axis:
// [x']  ==  [cos(RAD_5)  0  sin(RAD_5)]   [x]
// [y']  ==  [  0     1    0   ] * [y]
// [z']  ==  [-sin(RAD_5) 0  cos(RAD_5)]   [z]
// reversion 5 degrees around y axis:
// [x']  ==  [cos(RAD_5)  0  -sin(RAD_5)]   [x]
// [y']  ==  [  0     1    0   ] * [y]
// [z']  ==  [sin(RAD_5) 0  cos(RAD_5)]   [z]
// rotation 5 degrees around x axis:
// [x']  ==  [1  0    0   ]   [x]
// [y']  ==  [0  cos(RAD_5)  -sin(RAD_5)] * [y]
// [z']  ==  [0  sin(RAD_5)  cos(RAD_5)]   [z]
// reversion 5 degrees around x axis:
// [x']  ==  [1  0    0   ]   [x]
// [y']  ==  [0  cos(RAD_5)  sin(RAD_5)] * [y]
// [z']  ==  [0  -sin(RAD_5)  cos(RAD_5)]   [z]
// rotation 45 degrees around z:
// [x']  ==  [cos(RAD_45)  -sin(RAD_45)  0]   [x]
// [y']  ==  [sin(RAD_45)  cos(RAD_45)   0] * [y]
// [z']  ==  [0  0    1]   [z]
// reversion 45 degrees around z:
// [x']  ==  [cos(RAD_45)  sin(RAD_45)  0]   [x]
// [y']  ==  [-sin(RAD_45)  cos(RAD_45)   0] * [y]
// [z']  ==  [0  0    1]   [z]
// rotation 54.73 degrees around x:
// [x']  ==  [1  0    0   ]   [x]
// [y']  ==  [0  cos(RAD_54.73)  -sin(RAD_54.73)] * [y]
// [z']  ==  [0  sin(RAD_54.73)  cos(RAD_54.73)]   [z]
// reversion 54.73 degrees around x:
// [x']  ==  [1  0    0   ]   [x]
// [y']  ==  [0  cos(RAD_54.73)  sin(RAD_54.73)] * [y]
// [z']  ==  [0  -sin(RAD_54.73)  cos(RAD_54.73)]   [z]

typedef struct s_line
{
	double			x;
	double			y;
	double			x_inc;
	double			y_inc;
	int				dx;
	int				dy;
	int				steps;
	int				color;
}					t_line;

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	double			color;
}					t_point;

typedef struct s_map
{
	int				width;
	int				height;
	double			max_z;
	double			min_z;
	double			target_width;
	double			target_height;
	double			ratio;
	double			scale_z;
	t_point			**arr;
}					t_map;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_create_map
{
	int				x;
	int				y;
	int				fd;
	char			*line;
	t_split			*split;
}					t_create_map;

typedef struct s_mlx
{
	void			*win_ptr;
	void			*mlx_ptr;
	int				hook;
}					t_mlx;

typedef struct s_offset
{
  	double			cx;
	double			cy;
	double			cz;
	float			scale_x;
	float			scale_y;
	float			scale_z;
	short int		move_x;
	short int		move_y;
	short int		centralize_img_x;
	short int		centralize_img_y;
}					t_offset;

typedef struct s_data
{
	short int		rotate_5_around_x;
	short int		reverse_5_around_x;
	short int		rotate_5_around_y;
	short int		reverse_5_around_y;
	short int		neutral_y;
	short int		neutral_x;
	short int		apply_iso;
	short int		reset_iso;
	short int		neutral_iso;
	short int		do_step_one;
	short int		do_step_two;
	short int		zoom_in;
	short int		zoom_out;
	short int		neutral_zoom;
	short int		grid_style_nb;
	t_offset		offset;
	t_mlx			*mlx;
	t_node			*rotations_history;
	t_img			*img;
	t_map			*map;
	t_create_map	tool;
}					t_data;

#endif
