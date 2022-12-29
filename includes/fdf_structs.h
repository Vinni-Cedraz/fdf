/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/12/28 21:33:13 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "printf_libft_structs.h"

typedef struct s_line
{
	double			x;
	double			y;
	double			x_inc;
	double			y_inc;
	short int		dx;
	short int		dy;
	short int		steps;
	int				color;
}					t_line;

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_point;

typedef struct s_map
{
	short int		width;
	short int		height;
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
	void			*ptr;
	char			*addr;
	short int		width;
	short int		height;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_create_map
{
	short int		x;
	short int		y;
	short int		fd;
	char			*line;
	t_split			*split;
}					t_create_map;

typedef struct s_check_state
{
	short int		neutral_y;
	short int		neutral_x;
	short int		isometric;
	short int		zoomed_in;
	short int		zoomed_out;
	short int		neutral_zoom;
}					t_check_state;

typedef struct s_offsets
{
	double			center_x;
	double			center_y;
	double			center_z;
	double			scale_x;
	double			scale_y;
	double			scale_z;
	double			move_x;
	double			move_y;
	float			center_img_x;
	float			center_img_y;
	short int		do_step_one;
	short int		do_step_two;
	short int		apply_iso;
	short int		reset_iso;
	short int		rotate_2_around_x;
	short int		reverse_2_around_x;
	short int		rotate_2_around_y;
	short int		reverse_2_around_y;
}					t_offsets;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	int				hook;
}					t_mlx;

typedef struct s_data
{
	t_mlx			*mlx;
	t_offsets		*offset;
	t_check_state	*state;
	t_img			*img;
	t_map			*map;
	t_create_map	tool;
}					t_data;

#endif
