/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zscaler_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:30:51 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/20 18:58:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZSCALER_BONUS_H 
# define ZSCALER_BONUS_H 

#include "fdf_structs_bonus.h"

void					transpts_with_given_matrix_bonus(t_data *d, t_matrix *rot);
void					apply_isometric_steps(t_data *d);

// METHODS TO CHANGE ALTITUDE:

static void				scale_z_up(t_data *d) __attribute__((unused));
static void				scale_z_down(t_data *d) __attribute__((unused));
static void				scale_z_mirror(t_data *d) __attribute__((unused));

static inline void		scale_z_up(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_up);
}

static inline void		scale_z_down(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_down);
}

static inline void		scale_z_mirror(t_data *d)
{
	transpts_with_given_matrix_bonus(d, &d->matrix->change_altitude_mirror);
}

// CLASS FOR THE METHODS TO CHANGE ALTITUDE:
typedef struct s_zs{

	void		(*scale_method)(t_data *d);
}				t_zscaler;

#endif
