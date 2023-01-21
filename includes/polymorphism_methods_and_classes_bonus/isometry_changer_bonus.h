/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry_changer_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:56:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 02:11:44 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISOMETRY_CHANGER_BONUS_H
# define ISOMETRY_CHANGER_BONUS_H

# include "fdf_structs_bonus.h"

void				apply_iso_steps(t_data *d);
void				restore_snapshot(t_data *d);
typedef t_matrix	t_m;
void				transpts_with_given_matrix_bonus(t_data *d, t_m *m);

typedef struct s_is
{
	void			(*action)(t_data *d);
}					t_isometry_changer;

static inline void	go_to_diagonal(t_data *d) __attribute__((unused));
static inline void	go_to_diagonal(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_z_45);
	d->state.isometric = 0;
	d->state.parallel = 0;
	d->state.diagonal = 1;
}

static inline void	go_to_isometric(t_data *d) __attribute__((unused));
static inline void	go_to_isometric(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rot_x_54_73);
	d->state.parallel = 0;
	d->state.diagonal = 0;
	d->state.isometric = 1;
}

static inline void	undo_iso(t_data *d) __attribute__((unused));
static inline void	undo_iso(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_x_54_73);
	d->state.parallel = 0;
	d->state.isometric = 0;
	d->state.diagonal = 1;
}

static inline void	undo_diag(t_data *d) __attribute__((unused));
static inline void	undo_diag(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->rev_z_45);
	d->state.isometric = 0;
	d->state.diagonal = 0;
	d->state.parallel = 1;
}

#endif
