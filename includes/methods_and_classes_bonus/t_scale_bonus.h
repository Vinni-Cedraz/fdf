/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_scale_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:54:09 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/26 18:09:01 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SCALE_BONUS_H
# define T_SCALE_BONUS_H

# include "fdf_prototypes_bonus.h"
# include "fdf_t_data_bonus.h"

// # define WIN_HGHT 720
// # define WIN_WDTH 1370
# define WIN_HGHT 1080
# define WIN_WDTH 1920

static void			calculate_win_factor(void) __attribute__((unused));
static void			create_t_scale(void) __attribute__((unused));

typedef struct s_sc
{
	double			default_scale;
	double			altitude_factor;
	double			menu_width;
	double			win_hght;
	double			win_wdth;
	double			win_factor;
	double			size_factor;
	t_func_ptr		create_t_scale;
	t_func_ptr		calculate_win_factor;
}					t_scale;

static inline void	calculate_win_factor(void)
{
	get_data()->scale->win_factor = 1000 / get_data()->scale->win_hght;
}

static inline void	create_t_scale(void)
{
	t_data	*d;

	d = get_data();
	d->scale->win_hght = WIN_HGHT;
	d->scale->win_wdth = WIN_WDTH;
	d->scale->menu_width = WIN_HGHT * 0.275;
	if (WIN_HGHT == 480)
		d->scale->menu_width = 175;
}

#endif
