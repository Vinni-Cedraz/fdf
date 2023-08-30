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
static float			interpolate_linear(t_i inter) __attribute__((unused));
static float			normalize(float result) __attribute__((unused));

typedef struct s_in
{
	float				size_delta;
	float				min_factor;
	float				factor_delta;
	float				current_delta;
	float				(*interpolate)(t_i);
	float				(*normalize_result)(float);
}						t_interpolation;

static inline float	interpolate_linear(t_interpolation inter)
{
	float	factor;
	float	min;

	min = inter.min_factor;
	factor = min + inter.current_delta * inter.factor_delta / inter.size_delta;
	return (factor);
}

static inline float	normalize(float result)
{
	if (result >= 2.26)
		result = 2.26;
	return (result);
}

#endif
