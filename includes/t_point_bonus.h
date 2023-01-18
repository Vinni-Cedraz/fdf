/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_point_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:27:17 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/18 20:35:11 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_POINT_BONUS_H
# define T_POINT_BONUS_H

typedef struct s_node_for_a_point	t_node_with_a_point;

/*  \struct */
/*  \brief  t_raw stores the original "uncooked" map's coordinates as they were
given originally in the file, before scales and transformations are applied*/
typedef struct s_raw
{
	short							x;
	short							y;
	short							z;
}									t_raw;

/*  \struct */
/*  \brief  each t_point has stored in it it's old x,y and z values that are set
 * at the moment they achieve isometry by the static function take_snapshot
 * inside two_steps_to_isometry_bonus*/
typedef struct s_origin
{
	double							x;
	double							y;
	double							z;
	double							zoom_x;
	double							zoom_y;
	double 							zoom_z;
	t_raw							raw;
}									t_snapshot;

/*  \struct*/
/*  \brief each t_point has it's cartesian coordinates xyz translated to
 * spherical coordinates and stored in a t_sphere struct */
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
	t_snapshot						ol;
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
