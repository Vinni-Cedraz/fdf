/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_interpolation_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:29:32 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/16 14:20:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INTERPOLATION_BONUS_H
# define T_INTERPOLATION_BONUS_H

typedef struct s_in		t_i;
static double			interpolate_linear(t_i inter) __attribute__((unused));
static double			normalize(double result) __attribute__((unused));

typedef struct s_in
{
	double				size_delta;
	double				min_factor;
	double				factor_delta;
	double				current_delta;
	double				(*interpolate)(t_i);
	double				(*normalize_result)(double);
}						t_interpolation;

static inline double	interpolate_linear(t_interpolation inter)
{
	double	factor;
	double	min;

	min = inter.min_factor;
	factor = min + inter.current_delta * inter.factor_delta / inter.size_delta;
	return (factor);
}

static inline double	normalize(double result)
{
	if (result >= 2.26)
		result = 2.26;
	return (result);
}

#endif
