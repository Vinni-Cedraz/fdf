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

// ALTITUDE CHANGER CLASS:
typedef struct s_zs
{
	void	(*scale_method)(t_data *d);
}			t_zscaler;

// t_zscaler METHODS:
void		z_up_method(t_data *d);
void		z_down_method(t_data *d);
void		z_mirror_method(t_data *d);
void		transpts_with_given_matrix_bonus(t_data *d, t_matrix *rot);

#endif
