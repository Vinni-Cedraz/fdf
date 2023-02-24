/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rotation_matrices_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:14:37 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/25 11:25:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ROTATION_MATRICES_BONUS_H
# define T_ROTATION_MATRICES_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "fdf_t_data_bonus.h"

static void			iso_in_one_step(t_rm *m) __attribute__((unused));
static void			scale_z_up_tmp_stage(t_rm *m) __attribute__((unused));

typedef struct s_vec
{
	double			a;
	double			b;
	double			c;
}					t_column;

typedef struct s_row
{
	double			a;
	double			b;
	double			c;
}					t_row;

typedef struct s_m
{
	t_row			row_1;
	t_row			row_2;
	t_row			row_3;
}					t_matrix;

// ALIAS FOR THE MATRIX MULTIPLICATION FUNCTION
typedef t_matrix	(*t_mul_mat)(t_matrix, t_matrix);
typedef void		(*t_mat_method)(t_rotation_matrices *);

typedef struct s_rm
{
	t_matrix		rot_x;
	t_matrix		rot_y;
	t_matrix		rot_z;
	t_matrix		rev_z;
	t_matrix		rev_x;
	t_matrix		rev_y;
	t_matrix		rot_z_45;
	t_matrix		rev_z_45;
	t_matrix		rot_x_54_73;
	t_matrix		rev_x_54_73;
	t_matrix		go_iso;
	t_matrix		undo_iso;
	t_matrix		pre_change_altitude_up;
	t_matrix		pre_change_altitude_down;
	t_matrix		pre_change_altitude_mirror;
	t_matrix		undo_iso_do_pre_up;
	t_matrix		undo_iso_do_pre_down;
	t_matrix		undo_iso_do_pre_mirror;
	t_matrix		change_altitude_up;
	t_matrix		change_altitude_down;
	t_matrix		change_altitude_mirr;
	t_matrix		spherical;
	t_mul_mat		mul_mat;
	t_mat_method	iso_in_one_step;
	t_mat_method	scale_z_up_tmp_stage;
}					t_rotation_matrices;

static inline void	iso_in_one_step(t_rotation_matrices *m)
{
	m->mul_mat = &multiply_two_matrices_bonus;
	m->undo_iso = m->mul_mat(m->rev_x_54_73, m->rev_z_45);
	m->go_iso = m->mul_mat(m->rot_z_45, m->rot_x_54_73);
}

static inline void	scale_z_up_tmp_stage(t_rotation_matrices *m)
{
	t_matrix	undo_iso;
	t_matrix	pre_up;
	t_matrix	pre_down;
	t_matrix	pre_mirror;

	undo_iso = m->undo_iso;
	pre_up = m->pre_change_altitude_up;
	pre_down = m->pre_change_altitude_down;
	pre_mirror = m->pre_change_altitude_mirror;
	m->undo_iso_do_pre_up = m->mul_mat(undo_iso, pre_up);
	m->undo_iso_do_pre_down = m->mul_mat(undo_iso, pre_down);
	m->undo_iso_do_pre_mirror = m->mul_mat(undo_iso, pre_mirror);
}

#endif
