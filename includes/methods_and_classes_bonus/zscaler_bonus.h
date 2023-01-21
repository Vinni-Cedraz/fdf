/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zscaler_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:48 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/21 11:27:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZSCALER_BONUS_H
# define ZSCALER_BONUS_H

# include "fdf_structs_bonus.h"

// ALTITUUDE CHANGER CLASS:
typedef struct s_zs
{
	void			(*scale_method)(t_data *d);
}					t_zscaler;

// METHODS TO CHANGE ALTITUDE:
static void			scale_z_up(t_data *d) __attribute__((unused));
static void			scale_z_down(t_data *d) __attribute__((unused));
static void			scale_z_mirror(t_data *d) __attribute__((unused));
void				transpts_with_given_matrix_bonus(t_data *d, t_matrix *rot);

// METHODS DEFINITIONS:
static inline void	scale_z_up(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_up);
}

static inline void	scale_z_down(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_down);
}

static inline void	scale_z_mirror(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_mirror);
}

#endif
