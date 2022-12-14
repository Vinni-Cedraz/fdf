/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_rotation_matrices.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:18:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/06 21:13:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes.h"

static void	define_isometry_step_one_rotation(t_rotation_matrices *matrix);
static void	define_isometry_step_two_rotation(t_rotation_matrices *matrix);

void	define_rotation_matrices(t_rotation_matrices *matrix)
{
	define_isometry_step_one_rotation(matrix);
	define_isometry_step_two_rotation(matrix);
}

static void	define_isometry_step_one_rotation(t_rotation_matrices *matrix)
{
	matrix->rot_z_45 = (t_matrix){
	{cos(RAD_45), sin(RAD_45), 0},
	{-sin(RAD_45), cos(RAD_45), 0},
	{0, 0, 1}};
}

static void	define_isometry_step_two_rotation(t_rotation_matrices *matrix)
{
	matrix->rot_x_54_73 = (t_matrix){
	{1, 0, 0},
	{0, cos(RAD_54_73), sin(RAD_54_73)},
	{0, -sin(RAD_54_73), cos(RAD_54_73)}};
}
