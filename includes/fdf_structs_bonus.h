/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 10:53:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_BONUS_H
# define FDF_STRUCTS_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "libs/ft_printf_libft/libft/libft_bonus.h"
# include "linked_list_tools.h"
# include "t_event_bonus.h"
# include <stdio.h>

// FORWARD DECLARATIONS (to prevent circular dependencies)
typedef struct s_offset		t_offset;
typedef struct s_color		t_color;

typedef struct s_tmps
{
	double					x;
	double					y;
	double					z;
}							t_emporary;

typedef struct s_mlx
{
	void					*win_ptr;
	void					*ptr;
	int						hook;
}							t_mlx;

typedef struct s_assign_coordinates
{
	FILE					*fp;
	char					*argv;
	char					*first_line;
	t_split					*pts_in_this_row;
}							t_assign_coordinates;

typedef struct s_ctr
{
	double					x;
	double					y;
	double					z;
	int						index;
}							t_center;

typedef struct s_img
{
	int						width;
	int						height;
	void					*ptr;
	char					*addr;
	int						bpp;
	int						line_len;
	int						endian;
}							t_img;

typedef struct s_line
{
	double					x;
	double					y;
	double					x_inc;
	double					y_inc;
	short					dx;
	short					dy;
	unsigned int			color;
	int						steps;
}							t_line;

typedef struct s_vec
{
	double					a;
	double					b;
	double					c;
}							t_column;

typedef struct s_row
{
	double					a;
	double					b;
	double					c;
}							t_row;

typedef struct s_m
{
	t_row					row_1;
	t_row					row_2;
	t_row					row_3;
}							t_matrix;

typedef struct s_rm
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
	t_matrix				go_iso;
	t_matrix				undo_iso;
	t_matrix				scaling_z_up;
	t_matrix				scaling_z_down;
	t_matrix				scaling_z_mirror;
	t_matrix				change_altitude_up;
	t_matrix				change_altitude_down;
	t_matrix				change_altitude_mirror;
	t_matrix				spherical;
}							t_rotation_matrices;

typedef enum e_state
{
	parallel,
	diagonal,
	isometric,
	randomly_rotated,
	spherical,
}							t_state;

typedef struct s_d
{
	t_assign_coordinates	tool;
	t_state					state;
	t_offset				*offset;
	t_center				center;
	t_emporary				t;
	t_color					*c;
	t_mlx					*mlx;
	t_img					*img;
	t_map					*map;
	t_rotation_matrices		*matrix;
	t_lookup				lookup;
}							t_data;

#endif
