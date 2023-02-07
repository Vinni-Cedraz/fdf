/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:48:19 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/05 21:56:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_BONUS_H
# define FDF_STRUCTS_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "libs/ft_printf_libft/libft/libft_bonus.h"
# include "linked_list_tools.h"
# include <stdio.h>

typedef struct s_ev			t_event;

static void					hash_f(t_event *key) __attribute__((unused));
static void					create_hsl_map(t_data *d) __attribute__((unused));

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

typedef t_matrix			t_m;

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

typedef void				(*t_fsm)(t_data *d);

typedef struct s_hsl
{
	double					h;
	double					s;
	double					l;
}							t_hsl;

typedef struct s_color
{
	double					base;
	double					shaded;
	double					tinted;
	t_rgb					rgb_map[6];
	t_hsl					hsl_map[6];
	t_hsl					hsl;
	t_func_ptr				create_hsl_map;
}							t_color;

typedef struct s_ev
{
	int						key;
	t_func_ptr				f;
}							t_event;

typedef struct s_lookup
{
	t_node					*iso_transit_methods;
	t_node					*grid_methods;
	t_event					*events;
	void					(*set_hash)(t_event *events);
}							t_lookup;

static inline void	hash_f(t_event *events)
{
	int	hash;
	int	i;

	i = -1;
	while (++i <= 22)
	{
		hash = (events[i].key % 96) + 32;
		events[hash] = events[i];
	}
}

typedef struct s_offset		t_offset;

typedef struct s_d
{
	t_assign_coordinates	tool;
	t_state					state;
	t_offset				*offset;
	t_center				center;
	t_emporary				t;
	t_color					c;
	t_mlx					*mlx;
	t_img					*img;
	t_map					*map;
	t_rotation_matrices		*matrix;
	t_lookup				lookup;
}							t_data;

static inline void	create_hsl_map(t_data *d)
{
	d->c.hsl_map[0] = (t_hsl){0.0, 1.0, 1.0};
	d->c.hsl_map[1] = (t_hsl){60.0, 1.0, 0.5};
	d->c.hsl_map[2] = (t_hsl){120.0, 1.0, 0.75};
	d->c.hsl_map[3] = (t_hsl){180.0, 1.0, 0.5};
	d->c.hsl_map[4] = (t_hsl){240.0, 1.0, 0.5};
	d->c.hsl_map[5] = (t_hsl){300.0, 1.0, 1.0};
}

#endif
