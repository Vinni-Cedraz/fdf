/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry_changer_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:56:10 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/20 19:21:16 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISOMETRY_CHANGER_BONUS_H
# define ISOMETRY_CHANGER_BONUS_H

# include "fdf_structs_bonus.h"

void		apply_iso_steps(t_data *d);
void		undo_iso_steps(t_data *d);
void		restore_snapshot(t_data *d);

typedef struct s_is
{
	void	(*action)(t_data *d);
}			t_isometry_changer;

#endif
