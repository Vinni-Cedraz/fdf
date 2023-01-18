/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/18 00:27:02 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_BONUS_H
# define FDF_STRUCTS_BONUS_H

// stdio needed for FILE type
# include "../lib/ft_printf_libft/libft/libft_bonus.h"
# include "printf_libft_structs.h"
# include "t_point_bonus.h"
# include <stdio.h>

typedef unsigned int short	t_short;

/*  \struct  */
/* \brief temporary variables are often defined locally to hold some values and
 * make code more readable. The purpost t_emporary is to have those handy */
typedef struct s_tmps
{
	double					x;
	double					y;
	double					z;
}							t_emporary;

/*  \struct  */
/*  \brief It organizes the data mlx need to create a window */
typedef struct s_mlx
{
	void					*win_ptr;
	void					*ptr;
	t_short					hook;
}							t_mlx;

/* \struct  */
/*  \brief  Holds values different parse_map_bonus functions needs to read and
 * work with a file */
typedef struct s_assign_coordinates
{
	FILE					*fp;
	char					*argv;
}							t_assign_coordinates;

/*  \struct  */
/*  \brief  holds the values that are used to change x, y and z of the t_points
 * for scaling, change of altitude and translation*/
typedef struct s_offset
{
	double					scale;
	double					scale_z;
	double					move_x;
	double					move_y;
}							t_offset;

/*   \struct  */
/*  \brief  holds the x, y and z values of the specific t_point located at the
 * center of the map*/
typedef struct s_center
{
	double					x;
	double					y;
	double					z;
}							t_center;

/*  \struct  */
/*  \brief  holds the data mlx needs to create and work with an image */
typedef struct s_img
{
	t_short					width;
	t_short					height;
	void					*ptr;
	char					*addr;
	int						bpp;
	int						line_len;
	int						endian;
}							t_img;

/*  \struct  */
/*  \brief  holds the data needed by render_line_bonus to create a line using
 * Bressenham's algorithm*/
typedef struct s_line
{
	double					x;
	double					y;
	double					x_inc;
	double					y_inc;
	short					dx;
	short					dy;
	unsigned int			color;
	t_short					steps;
}							t_line;

/*  \struct  */
/*  \brief  each row in a 3x3 matrix has three columns, t_row holds the values
 * in each of the three columns for each row */
typedef struct s_row
{
	double					col_1;
	double					col_2;
	double					col_3;
}							t_row;

/*  \class  */
/*  \brief  the t_matrix class is used to defined different t_matrix objects,
 * all with three t_row attributes each with it's own t_row values specific to
 * that object*/
typedef struct s_matrix
{
	t_row					row_1;
	t_row					row_2;
	t_row					row_3;
}							t_matrix;

/*  \struct  */
/*  \brief  It's the set of the different t_matrix objects that will be defined
 * in the define_rotation_matrices_bonus function */
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

/*  \class  */
/*  \brief  t_state is a class that holds pseudo-boolean indicators of the state
 * of the map as it is rotated and translated by the user.*/
typedef struct s_state
{
	t_short					snapshot_taken;
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

/*  \class  */
/*  \brief  A t_map is essentially the series of t_points that will be used to
 * render de wireframe, but t_map also contains other important data about the
 * set of t_points, such as it's size and max/min altitude values. */
typedef struct s_map
{
	t_short					has_hexcolor;
	int						width;
	int						height;
	uint					size;
	short					max_z;
	short					min_z;
	double					target_width;
	double					target_height;
	double					ratio;
	t_node_with_a_point		*pts;
	t_point					**arr;
}							t_map;

/*  \class  */
/*  \brief  t_data is a meta-class that holds all the data_structures that are
 * most used throughout the project */
typedef struct s_data
{
	t_assign_coordinates	tool;
	t_state					state;
	t_offset				offset;
	t_center				center;
	t_mlx					*mlx;
	t_img					*img;
	t_map					*map;
	t_rotation_matrices		*matrix;
	t_emporary				t;
}							t_data;

#endif
