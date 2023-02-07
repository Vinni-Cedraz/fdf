/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rotation_matrices_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:14:37 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/07 12:52:58 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ROTATION_MATRICES_BONUS_H
# define T_ROTATION_MATRICES_BONUS_H

# include "fdf_t_data_bonus.h"

static void			iso_in_one_step(t_data *d) __attribute__((unused));
static void			scale_z_up_tmp_stage(t_data *d) __attribute__((unused));

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
	t_matrix		undo_iso_and_pre_up;
	t_matrix		undo_iso_and_pre_down;
	t_matrix		undo_iso_and_pre_mirror;
	t_matrix		change_altitude_up;
	t_matrix		change_altitude_down;
	t_matrix		change_altitude_mirror;
	t_matrix		spherical;
}					t_rotation_matrices;

static inline void	iso_in_one_step(t_data *d)
{
	t_mul_mat	mul_mat;

	mul_mat = &multiply_two_matrices_bonus;
	d->matrix->undo_iso = mul_mat(d->matrix->rev_x_54_73, d->matrix->rev_z_45);
	d->matrix->go_iso = mul_mat(d->matrix->rot_z_45, d->matrix->rot_x_54_73);
}

static inline void	scale_z_up_tmp_stage(t_data *d)
{
	t_mul_mat	mul_mat;
	t_matrix	undo_iso;
	t_matrix	pre_up;
	t_matrix	pre_down;
	t_matrix	pre_mirror;

	undo_iso = d->matrix->undo_iso;
	pre_up = d->matrix->pre_change_altitude_up;
	pre_down = d->matrix->pre_change_altitude_down;
	pre_mirror = d->matrix->pre_change_altitude_mirror;
	mul_mat = &multiply_two_matrices_bonus;
	d->matrix->undo_iso_and_pre_up = mul_mat(undo_iso, pre_up);
	d->matrix->undo_iso_and_pre_down = mul_mat(undo_iso, pre_down);
	d->matrix->undo_iso_and_pre_mirror = mul_mat(undo_iso, pre_mirror);
}

#endif
