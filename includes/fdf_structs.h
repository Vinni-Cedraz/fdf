/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/10 21:00:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "printf_libft_structs.h"

typedef struct s_line
{
	double				x;
	double				y;
	double				x_inc;
	double				y_inc;
	int					dx;
	int					dy;
	int					steps;
	int					color;
}						t_line;

typedef struct s_point
{
	double				x;
	double				y;
	double				z;
	double				color;
}						t_point;

typedef struct s_map
{
	int					width;
	int					height;
	double				max_z;
	double				min_z;
	double				target_width;
	double				target_height;
	double				ratio;
	t_point				**arr;
}						t_map;

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					width;
	int					height;
	int					bpp;
	int					line_len;
	int					endian;
}						t_img;

typedef struct s_create_map
{
	int					x;
	int					y;
	int					fd;
	char				*line;
	t_split				*split;
}						t_create_map;

typedef struct s_row
{
	double				x;
	double				y;
	double				z;
}						t_row;

typedef struct s_matrix
{
	t_row				row_1;
	t_row				row_2;
	t_row				row_3;
}						t_matrix;

typedef struct s_rotation_matrices
{
	t_matrix			rot_z_45;
	t_matrix			rot_x_54_73;
}						t_rotation_matrices;

typedef struct s_data
{
	char				**argv;
	void				*win_ptr;
	void				*mlx_ptr;
	int					hook;
	short int			centralize_img_x;
	short int			centralize_img_y;
	short int			neutral_y;
	short int			neutral_x;
	short int			apply_iso;
	short int			reset_iso;
	short int			neutral_iso;
	short int			do_step_one;
	short int			do_step_two;
	short int			zoom_in;
	short int			zoom_out;
	short int			neutral_zoom;
	double				cx;
	double				cy;
	double				cz;
	double				move_x;
	double				move_y;
	double				scale;
	double				scale_z;
	t_img				*img;
	t_map				*map;
	t_create_map		tool;
	t_rotation_matrices	*matrix;
}						t_data;

#endif
