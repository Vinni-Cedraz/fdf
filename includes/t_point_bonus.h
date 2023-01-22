/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:27:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/22 11:52:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_BONUS_H
# define T_POINT_BONUS_H

# include <stdlib.h>

typedef struct s_nd		t_node_with_a_point;
typedef struct s_d		t_data;
typedef struct s_pt		t_point;

typedef struct s_raw
{
	short				x;
	short				y;
	short				z;
}						t_raw;

typedef struct s_origin
{
	double				x;
	double				y;
	double				z;
	double				zoom_x;
	double				zoom_y;
	double				zoom_z;
	t_raw				raw;
}						t_snapshot;

typedef struct s_phere
{
	double				phi;
	double				theta;
	double				r;
}						t_sphere;

typedef struct s_pt
{
	double				x;
	double				y;
	double				z;
	long				color;
	t_sphere			ball;
	t_snapshot			ol;
	void				(*define_p_color_by_altitude)(t_point *p, t_data *d);
}						t_point;

typedef struct s_nd
{
	t_point				point;
	t_node_with_a_point	*next;
}						t_node_with_a_point;

typedef struct s_rgb
{
	double				r;
	double				g;
	double				b;
}						t_rgb;

#endif
