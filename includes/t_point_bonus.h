/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:27:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/12 16:25:47 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_BONUS_H
# define T_POINT_BONUS_H

typedef struct s_node_for_a_point	t_node_with_a_point;

typedef struct s_origin
{
	double							old_x;
	double							old_y;
	double							old_z;
}									t_snapshot;

typedef struct s_phere
{
	double							phi;
	double							theta;
	double							r;
}									t_sphere;

/*  \class */
/*   \brief t_point class defines the attributes a new t_point object has,
 * such as cartesian coordinates, color and etc */
typedef struct s_point
{
	double							x;
	double							y;
	double							z;
	unsigned int					color;
	t_sphere						ball;
	t_snapshot						snapshot;
}									t_point;

/*  \class */
/*   \brief Allows the creation of a linked list where each node has a t_point
 * object as it's first attribute, the other being *next*/
typedef struct s_node_for_a_point
{
	t_point							point;
	t_node_with_a_point				*next;
}									t_node_with_a_point;

#endif
