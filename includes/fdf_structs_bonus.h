/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/08 23:31:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_BONUS_H
# define FDF_STRUCTS_BONUS_H

# include "printf_libft_structs.h"
// stdio needed for FILE type
# include <stdio.h>

typedef unsigned int short	t_short;

typedef struct s_line
{
	double					x;
	double					y;
	double					x_inc;
	double					y_inc;
	short					dx;
	short					dy;
	t_short					steps;
	unsigned int			color;
}							t_line;

typedef struct s_origin
{
	double					old_x;
	double					old_y;
	double					old_z;
}							t_snapshot;

typedef struct s_point
{
	double					x;
	double					y;
	double					z;
	unsigned int			color;
	double					phi;
	double					theta;
	double					r;
	t_snapshot				snapshot;
}							t_point;

typedef struct s_map
{
	int						width;
	int						height;
	short					max_z;
	short					min_z;
	double					target_width;
	double					target_height;
	double					ratio;
	t_point					**pts;
}							t_map;

typedef struct s_img
{
	t_short					width;
	t_short					height;
	void					*mlx_img;
	char					*addr;
	int						bpp;
	int						line_len;
	int						endian;
}							t_img;

typedef struct s_create_map
{
	t_short					x;
	t_short					y;
	FILE					*fp;
	t_split					*split;
	char					*line;
}							t_create_map;

typedef struct s_row
{
	double					x;
	double					y;
	double					z;
}							t_row;

typedef struct s_matrix
{
	t_row					row_1;
	t_row					row_2;
	t_row					row_3;
}							t_matrix;

typedef struct s_rotation_matrices
{
	t_matrix				rot_x;
	t_matrix				rot_y;
	t_matrix				rot_z;
	t_matrix				rev_z;
	t_matrix				rev_x;
	t_matrix				rev_y;
	t_matrix				rot_z_45;
	t_matrix				rev_z_45;
	t_matrix				rot_x_54_73;
	t_matrix				rev_x_54_73;
	t_matrix				spherical;
}							t_rotation_matrices;

typedef struct s_mlx
{
	void					*win_ptr;
	void					*mlx_ptr;
	t_short					hook;
}							t_mlx;

typedef struct s_offset
{
	double					cx;
	double					cy;
	double					cz;
	double					scale;
	double					scale_z;
	double					move_x;
	double					move_y;
}							t_offset;

// phi is also known as latitude
// theta is also known as longitude
typedef struct s_sphere
{
}							t_sphere;

typedef struct s_state
{
	t_short					rotate_5_around_x;
	t_short					reverse_5_around_x;
	t_short					rotate_5_around_y;
	t_short					reverse_5_around_y;
	t_short					step_towards_isometry;
	t_short					step_back;
	t_short					diagonal;
	t_short					isometric;
	t_short					zoom_in;
	t_short					zoom_out;
	t_short					neutral_zoom;
	t_short					neutral_x;
	t_short					neutral_y;
	t_short					neutral_z;
	t_short					parallel;
	t_short					grid_style_nb;
}							t_state;

typedef struct s_data
{
	t_state					state;
	t_offset				offset;
	t_mlx					*mlx;
	t_img					*img;
	t_map					*map;
	t_create_map			tool;
	t_rotation_matrices		*matrix;
}							t_data;

#endif
