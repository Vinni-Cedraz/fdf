/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:27:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 14:28:48 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_BONUS_H
# define T_POINT_BONUS_H

typedef struct s_origin
{
	double			old_x;
	double			old_y;
	double			old_z;
}					t_snapshot;

typedef struct s_phere
{
	double			phi;
	double			theta;
	double			r;
}					t_sphere;

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
	t_sphere		ball;
	t_snapshot		snapshot;
}					t_point;

#endif
