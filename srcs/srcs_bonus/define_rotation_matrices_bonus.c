/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_rotation_matrices_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:18:14 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/01/02 01:28:10 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_includes_bonus.h"
#include "fdf_structs.h"

void		define_rotation_matrices_bonus(t_rotation_matrices *matrix);
static void	define_reversion_matrices(t_rotation_matrices *matrix);
static void	define_isometry_step_one_rotation(t_rotation_matrices *matrix);
static void	define_isometry_step_two_rotation(t_rotation_matrices *matrix);

void	define_rotation_matrices_bonus(t_rotation_matrices *matrix)
{
	matrix->rot_x = (t_matrix){
	{1, 0, 0},
	{0, cos(RAD), -sin(RAD)},
	{0, sin(RAD), cos(RAD)}};
	matrix->rot_y = (t_matrix){
	{cos(RAD), 0, sin(RAD)},
	{0, 1, 0},
	{-sin(RAD), 0, cos(RAD)}};
	matrix->rot_z = (t_matrix){
	{cos(RAD), -sin(RAD), 0},
	{sin(RAD), cos(RAD), 0},
	{0, 0, 1}};
	define_reversion_matrices(matrix);
	define_isometry_step_one_rotation(matrix);
	define_isometry_step_two_rotation(matrix);
}

static void	define_reversion_matrices(t_rotation_matrices *matrix)
{
	matrix->rev_x = (t_matrix){
	{1, 0, 0},
	{0, cos(-RAD), -sin(-RAD)},
	{0, sin(-RAD), cos(-RAD)}};
	matrix->rev_y = (t_matrix){
	{cos(-RAD), 0, sin(-RAD)},
	{0, 1, 0},
	{-sin(-RAD), 0, cos(-RAD)}};
	matrix->rev_z = (t_matrix){
	{cos(-RAD), -sin(-RAD), 0},
	{sin(-RAD), cos(-RAD), 0},
	{0, 0, 1}};
}

static void	define_isometry_step_one_rotation(t_rotation_matrices *matrix)
{
	matrix->rot_z_45 = (t_matrix){
	{cos(RAD_45), -sin(RAD_45), 0},
	{sin(RAD_45), cos(RAD_45), 0},
	{0, 0, 1}};
	matrix->rev_z_45 = (t_matrix){
	{cos(-RAD_45), -sin(-RAD_45), 0},
	{sin(-RAD_45), cos(-RAD_45), 0},
	{0, 0, 1}};
}

static void	define_isometry_step_two_rotation(t_rotation_matrices *matrix)
{
	matrix->rot_x_54_73 = (t_matrix){
	{1, 0, 0},
	{0, cos(RAD_54_73), -sin(RAD_54_73)},
	{0, sin(RAD_54_73), cos(RAD_54_73)}};
	matrix->rev_x_54_73 = (t_matrix){
	{1, 0, 0},
	{0, cos(-RAD_54_73), -sin(-RAD_54_73)},
	{0, sin(-RAD_54_73), cos(-RAD_54_73)}};
}
