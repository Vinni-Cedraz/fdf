/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry_changer_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:27:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 22:09:51 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISOMETRY_CHANGER_BONUS_H
# define ISOMETRY_CHANGER_BONUS_H

# include "fdf_structs_bonus.h"

// CLASS FOR ISOMETRY CHANGER OBJECTS:
typedef struct s_is
{
	void			(*action)(t_data *d);
}					t_isometry_changer;
//alias
typedef t_isometry_changer	t_i_changer;

// ISOMETRY CHANGER METHODS:
static void			go_to_diagonal(t_data *d) __attribute__((unused));
static void			go_to_isometric(t_data *d) __attribute__((unused));
static void			undo_isometric(t_data *d) __attribute__((unused));
static void			undo_diagonal(t_data *d) __attribute__((unused));
static void			restore_snapshot(t_data *d) __attribute__((unused));
void				apply_iso_steps(t_data *d);
void				restore_from_snapshot(t_data *d);
void				transpts_with_given_matrix_bonus(t_data *d, t_m *m);

// FUNCTION DEFINITIONS:
static inline void	go_to_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_z_45);
	d->state.isometric = 0;
	d->state.parallel = 0;
	d->state.diagonal = 1;
}

static inline void	go_to_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_x_54_73);
	d->state.parallel = 0;
	d->state.diagonal = 0;
	d->state.isometric = 1;
}

static inline void	undo_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_x_54_73);
	d->state.parallel = 0;
	d->state.isometric = 0;
	d->state.diagonal = 1;
}

static inline void	undo_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_z_45);
	d->state.isometric = 0;
	d->state.diagonal = 0;
	d->state.parallel = 1;
}

static inline void	restore_snapshot(t_data *d)
{
	restore_from_snapshot(d);
	d->state.diagonal = 0;
	d->state.parallel = 0;
	d->state.out_of_position = 0;
	d->state.isometric = 1;
}

#endif
