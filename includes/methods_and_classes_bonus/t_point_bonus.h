/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:27:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/02/14 20:23:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_BONUS_H
# define T_POINT_BONUS_H

# include "fdf_defines.h"
# include "fdf_prototypes_bonus.h"
# include "printf_libft_includes.h"
# include <string.h>

typedef struct s_d	t_data;
typedef struct s_pt	t_point;

typedef struct s_phere
{
	double			phi;
	double			theta;
	double			rho;
}					t_sphere;

typedef struct s_raw
{
	double			x;
	double			y;
	double			z;
}					t_raw;

typedef struct s_origin
{
	double			x;
	double			y;
	double			z;
	double			zoom_x;
	double			zoom_y;
	double			zoom_z;
	t_raw			raw;
}					t_snapshot;

typedef struct s_pt
{
	double			x;
	double			y;
	double			z;
	long			color;
	t_sphere		ball;
	t_snapshot		ol;
}					t_point;

#endif
